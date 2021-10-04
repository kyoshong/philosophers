/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_loop_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:42:31 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/03 01:43:12 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	count_eat(t_philo *philo)
{
	if (++philo->count_eat == philo->rules->num_of_must_eat)
	{
		pthread_mutex_lock(&philo->rules->counting_eat);
		philo->rules->full_philos++;
		if (philo->rules->full_philos == philo->rules->num_philosophers)
			philo->rules->philo_died = 1;
		pthread_mutex_unlock(&philo->rules->counting_eat);
	}
}

void	*life_loop_count(void *philos)
{
	t_philo	*philo;

	philo = philos;
	gettimeofday(&(philo->last_eat), NULL);
	while (!(philo->rules->philo_died))
	{
		pick_up(philo);
		eating(philo);
		count_eat(philo);
		sleeping(philo);
		thinking(philo);
	}
	if (philo->rules->full_philos != philo->rules->num_philosophers)
		log_died(philo);
	pthread_mutex_lock(&(philo->rules->count_over));
	philo->rules->philo_over++;
	pthread_mutex_unlock(&(philo->rules->count_over));
	return (philos);
}

int	create_thread_limit(pthread_t *thread, t_philo *philos, t_rules *rules)
{
	int	i;

	i = 0;
	gettimeofday(&(rules->stamp), NULL);
	while (i < rules->num_philosophers)
	{
		philos[i] = set_philos(rules, i);
		if (pthread_create(&thread[i], NULL, life_loop_count, \
		(void *)&philos[i]) != 0 || pthread_detach(thread[i]) != 0)
		{
			free(thread);
			return (1);
		}
		usleep(10);
		i++;
	}
	while (rules->philo_over < rules->num_philosophers)
	{
	}
	if (rules->full_philos == rules->num_philosophers)
		printf("ㄲㅓ어억\n");
	return (0);
}

int	make_limit_thread(t_rules *rules)
{
	pthread_t	*thread;
	t_philo		*philos;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * rules->num_philosophers);
	if (thread == NULL)
		return (1);
	philos = (t_philo *)malloc(sizeof(t_philo) * rules->num_philosophers);
	if (philos == NULL)
	{
		print_error("CREATE_PHILOS_ERROR");
		free(thread);
		return (1);
	}
	if (create_thread_limit(thread, philos, rules))
		print_error("CREATE_THREAD_ERROR");
	free(thread);
	free(philos);
	return (0);
}

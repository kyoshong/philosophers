/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:04:38 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/03 01:42:23 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_loop(void *philos)
{
	t_philo	*philo;

	philo = philos;
	philo->last_eat = philo->rules->stamp;
	if (philo->left == philo->right)
	{
		usleep(philo->rules->time_to_die);
		log_died(philo);
	}
	while (!(philo->rules->philo_died))
	{
		pick_up(philo);
		eating(philo);
	}
	pthread_mutex_lock(&(philo->rules->count_over));
	++philo->rules->philo_over;
	pthread_mutex_unlock(&(philo->rules->count_over));
	return (philos);
}

t_philo	set_philos(t_rules *rules, int i)
{
	t_philo	philo;

	philo.id = i + 1;
	philo.count_eat = 0;
	if (philo.id == 1)
		philo.right = rules->num_philosophers - 1;
	else
		philo.right = philo.id - 2;
	philo.left = philo.id - 1;
	philo.rules = rules;
	return (philo);
}

int	create_thread(pthread_t *thread, t_philo *philos, t_rules *rules)
{
	int	i;

	i = 0;
	gettimeofday(&(rules->stamp), NULL);
	while (i < rules->num_philosophers)
	{
		philos[i] = set_philos(rules, i);
		if (pthread_create(&thread[i], NULL, life_loop, \
		(void *)&philos[i]) != 0 || pthread_detach(thread[i]) != 0)
		{
			free(thread);
			return (1);
		}
		i++;
	}
	while (rules->philo_over < rules->num_philosophers)
	{
	}
	return (0);
}

int	make_thread(t_rules *rules)
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
	if (create_thread(thread, philos, rules))
		print_error("CREATE_THREAD_ERROR");
	free(thread);
	free(philos);
	return (0);
}

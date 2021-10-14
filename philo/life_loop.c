/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:04:38 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/14 20:01:30 by hyospark         ###   ########.fr       */
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
	}
	while (!(philo->rules->philo_died))
		eating(philo);
	if (philo->rules->full_philos != philo->rules->num_philos)
	{
		log_died(philo);
		philo->rules->full_philos = 0;
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
		philo.right = rules->num_philos - 1;
	else
		philo.right = philo.id - 2;
	philo.left = philo.id - 1;
	philo.rules = rules;
	pthread_mutex_init(&philo.eating, NULL);
	return (philo);
}

void	*check_starv_thread(void *philos)
{
	t_philo			*philo;
	struct timeval	time;
	long long		comp;

	philo = philos;
	while (!philo->rules->philo_died)
	{
		gettimeofday(&time, NULL);
		pthread_mutex_lock(&philo->eating);
		comp = cal_micro(time, philo->last_eat);
		if (comp > philo->rules->time_to_die)
		{
			log_died(philo);
			pthread_mutex_unlock(&philo->eating);
			break ;
		}
		pthread_mutex_unlock(&philo->eating);
		usleep(100);
	}
	return (philos);
}

int	create_thread(t_philo *philos, t_rules *rules)
{
	int	i;

	i = 0;
	gettimeofday(&(rules->stamp), NULL);
	while (i < rules->num_philos)
	{
		philos[i] = set_philos(rules, i);
		if (pthread_create(&rules->thread[i], NULL, life_loop, \
		(void *)&philos[i]) != 0 || pthread_detach(rules->thread[i]) != 0)
			return (1);
		i++;
		usleep(100);
	}
	i = 0;
	while (i < rules->num_philos)
	{
		if (pthread_create(&rules->s_thread[i], NULL, check_starv_thread, \
		(void *)&philos[i]) != 0 || pthread_detach(rules->s_thread[i]) != 0)
			return (1);
		i++;
	}
	while (rules->philo_over < rules->num_philos)
	{
	}
	return (0);
}

int	make_thread(t_rules *rules)
{
	t_philo		*philos;

	if (init_thread(rules))
		return (1);
	philos = (t_philo *)malloc(sizeof(t_philo) * rules->num_philos);
	if (philos == NULL)
	{
		free(rules->thread);
		free(rules->s_thread);
		return (1);
	}
	if (create_thread(philos, rules))
		return (1);
	if (rules->full_philos == rules->num_philos)
		printf("I am full\n");
	thread_clean_all(philos);
	return (0);
}

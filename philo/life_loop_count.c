/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_loop_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:42:31 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/15 21:27:00 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_loop_count(void *philos)
{
	t_philo *philo;
	long	starved;

	philo = (void *)philos;
	gettimeofday(&(philo->starv), NULL);
	philo->last_eat = philo->rules->stamp;
	starved = cal_micro(philo->starv, philo->last_eat);
	while ((!philo->rules->philo_died) && (starved <= philo->rules->time_to_die))
	{
		gettimeofday(&(philo->starv), NULL);
		starved = cal_micro(philo->starv, philo->last_eat);
		pick_up(philo);
		if (philo->left_hand && philo->right_hand)
		{
			philo->last_eat = eating(philo, philo->last_eat);
			if (++philo->count_eat == philo->rules->num_of_must_eat)
			{
				philo->rules->full_philos++;
				break ;
			}
			if (philo->last_eat.tv_sec == -1 || sleeping(philo, philo->last_eat))
				break ;
			thinking(philo);
		}
	}
	log_died(philo, philo->starv);
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
		if (pthread_create(&thread[i], NULL, life_loop_count, (void *)&i) != 0)
		{
			free(thread);
			return (1);
		}
		if (pthread_detach(thread[i]) != 0)
		{
			free(thread);
			return (1);
		}
		i++;
		usleep(100);
	}
	while (!rules->philo_died)
	{
	}
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
		free_print_error("CREATE_PHILOS_ERROR", (void *)rules->fork_list);
		free(thread);
		return (1);
	}
	if (create_thread_limit(thread, philos, rules))
	{
		free(thread);
		free(philos);
		free_print_error("CREATE_THREAD_ERROR", (void *)rules->fork_list);
		return (1);
	}
	return (0);
}

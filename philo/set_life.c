/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_life.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:16:17 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/14 18:35:02 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_clean_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->rules->num_philos)
	{
		pthread_mutex_unlock(&(philo[i].eating));
		pthread_mutex_destroy(&(philo[i].eating));
		i++;
	}
	free(philo->rules->thread);
	free(philo->rules->s_thread);
	free(philo);
}

void	clean_all(t_rules *rules)
{
	mutex_unlock_all(rules);
	mutex_destroy_all(rules);
	free(rules->fork_list);
}

int	init_thread(t_rules *rules)
{
	rules->thread = (pthread_t *)malloc(sizeof(pthread_t) * rules->num_philos);
	if (rules->thread == NULL)
		return (1);
	rules->s_thread = \
	(pthread_t *)malloc(sizeof(pthread_t) * rules->num_philos);
	if (rules->s_thread == NULL)
	{
		free(rules->thread);
		return (1);
	}
	return (0);
}

int	set_rules(int argc, char const *argv[], t_rules *rules)
{
	rules->num_philos = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]) * 1000;
	rules->time_to_eat = ft_atoi(argv[3]) * 1000;
	rules->time_to_sleep = ft_atoi(argv[4]) * 1000;
	rules->philo_died = 0;
	rules->full_philos = 0;
	rules->philo_over = 0;
	if (argc == 6)
		rules->num_of_must_eat = ft_atoi(argv[5]);
	else
		rules->num_of_must_eat = -1;
	rules->fork_list = (pthread_mutex_t *) \
	malloc(sizeof(pthread_mutex_t) * (rules->num_philos));
	if (rules->fork_list == NULL)
		return (1);
	if (init_mutex(rules))
	{
		free(rules->fork_list);
		return (1);
	}
	return (0);
}

void	lifes(int argc, char const *argv[])
{
	t_rules	rules;

	if (set_rules(argc, argv, &rules))
	{
		print_error("SET_RULES_ERROR\n");
		return ;
	}
	if (make_thread(&rules))
		print_error("THREAD_ERROR");
	clean_all(&rules);
}

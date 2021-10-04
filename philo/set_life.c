/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_life.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:16:17 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/03 01:41:04 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_all(t_rules *rules)
{
	free(rules->fork_list);
	mutex_unlock_all(rules);
	mutex_destroy_all(rules);
}

int	set_rules(int argc, char const *argv[], t_rules *rules)
{
	rules->num_philosophers = ft_atoi(argv[1]);
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
	malloc(sizeof(pthread_mutex_t) * (rules->num_philosophers));
	if (rules->fork_list == NULL)
	{
		print_error("FORK_MALLOC_ERROR\n");
		return (1);
	}
	return (0);
}

void	lifes(int argc, char const *argv[])
{
	t_rules	rules;
	int		error;

	if (set_rules(argc, argv, &rules))
		return ;
	if (init_mutex(&rules))
	{
		mutex_destroy_all(&rules);
		free_print_error("MUTEX_INIT_ERROR", (void *)rules.fork_list);
		return ;
	}
	error = 0;
	if (rules.num_of_must_eat > 0)
		error = make_limit_thread(&rules);
	else
		error = make_thread(&rules);
	if (error)
		free_print_error("THREAD_ERROR", (void *)rules.fork_list);
	usleep(100);
	clean_all(&rules);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_life_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:16:17 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/14 04:00:13 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean_all(t_rules *rules)
{
	free(rules->philo_pid);
}

int	set_rules(int argc, char const *argv[], t_rules *rules)
{
	rules->num_philos = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]) * 1000;
	rules->time_to_eat = ft_atoi(argv[3]) * 1000;
	rules->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6 && rules->num_philos > 1)
		rules->num_of_must_eat = ft_atoi(argv[5]);
	else
		rules->num_of_must_eat = -1;
	rules->philo_died = 0;
	rules->philo_pid = (int *)malloc(sizeof(int) * rules->num_philos);
	if (open_sema(rules) || rules->philo_pid == NULL)
	{
		unlink_sema_all();
		print_error("SET_RULES_ERROR");
		return (1);
	}
	memset(rules->philo_pid, 0, sizeof(int) * rules->num_philos);
	return (0);
}

void	lifes(int argc, char const *argv[])
{
	t_rules	rules;

	if (set_rules(argc, argv, &rules))
		return ;
	if (make_thread(&rules))
		print_error("THREAD_ERROR");
	clean_all(&rules);
}

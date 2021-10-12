/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_life_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:16:17 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/12 18:05:18 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean_all(t_rules *rules)
{
	close_sema_all(rules);
	unlink_sema_all();
}

int	set_rules(int argc, char const *argv[], t_rules *rules)
{
	rules->num_philos = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]) * 1000;
	rules->time_to_eat = ft_atoi(argv[3]) * 1000;
	rules->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		rules->num_of_must_eat = ft_atoi(argv[5]);
	else
		rules->num_of_must_eat = -1;
	if (open_sema(rules))
	{
		unlink_sema_all();
		print_error("SEMP_OPEN_ERROR");
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
	error = 0;
	if (rules.num_of_must_eat > 0)
		error = make_limit_thread(&rules);
	else
		error = create_philos(&rules);
	if (error)
		print_error("THREAD_ERROR");
	while (1)
	{
	}
	usleep(100);
	clean_all(&rules);
}

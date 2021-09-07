/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:16:17 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/06 21:07:39 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_life_rules(int argc, char const *argv[], t_philo *rules)
{
	rules->num_philosophers = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->num_of_must_eat = ft_atoi(argv[5]);
}

void	starting_lifes(t_philo *rules)
{
	pthread_t *thread;

	pthread_create(&thread, NULL, pickup, NULL);

}

void	lifes(int argc, char const *argv[])
{
	t_philo *rules;

	set_life_rules(argc, argv, rules);
	starting_lifes(rules);
}

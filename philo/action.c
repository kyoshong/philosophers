/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:54:47 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 19:53:31 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval	eating(t_philo *philo, struct timeval last_eat)
{
	long starved;
	struct timeval eat;
	struct timeval fork;

	gettimeofday(&fork, NULL);
	log_fork(fork, philo->id);
	starved = cal_micro(fork, last_eat);
	if (check_starv_eat(starved))
	{
		fork.tv_sec = -1;
		return (fork);
	}
	gettimeofday(&eat, NULL);
	last_eat = eat;
	log_eating(eat, philo->id);
	starved = 0;
	while (starved <= rules.time_to_eat + 100)
	{
		gettimeofday(&eat, NULL);
		starved = cal_micro(eat, last_eat);
	}
	put_down(philo);
	return (fork);
}

int	sleeping(t_philo *philo, struct timeval last_eat)
{
	struct timeval	sleeping;
	struct timeval	start;
	long			starved;

	gettimeofday(&sleeping, NULL);
	log_sleeping(sleeping, philo->id);
	if (check_starv_sleep(sleeping ,last_eat, philo->id, rules.time_to_sleep))
		return (1);
	gettimeofday(&start, NULL);
	starved = 0;
	while (starved <= rules.time_to_sleep)
	{
		gettimeofday(&start, NULL);
		starved = cal_micro(start, sleeping);
	}
	return (0);
}

void	thinking(t_philo *philo)
{
	struct timeval think;

	gettimeofday(&think, NULL);
	log_thinking(think, philo->id);
}

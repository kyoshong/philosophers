/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:06:13 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/12 19:58:20 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	cal_micro(struct timeval now, struct timeval std)
{
	return (((now.tv_sec - std.tv_sec) * 1000000) \
	+ (now.tv_usec - std.tv_usec));
}

int	check_starv_eat(t_philo *ph)
{
	long long		comp;
	struct timeval	starv;

	gettimeofday(&starv, NULL);
	comp = cal_micro(starv, ph->last_eat);
	if (comp + ph->rules->time_to_eat > ph->rules->time_to_die)
	{
		while (comp < ph->rules->time_to_die)
		{
			gettimeofday(&starv, NULL);
			comp = cal_micro(starv, ph->last_eat);
		}
		put_down(ph);
		log_died(ph);
		return (1);
	}
	return (0);
}

int	check_starv_sleep(struct timeval starv, t_philo *ph)
{
	long long		comp;

	comp = cal_micro(starv, ph->last_eat);
	if ((comp + ph->rules->time_to_sleep) > ph->rules->time_to_die)
	{
		while (comp < ph->rules->time_to_die)
		{
			gettimeofday(&starv, NULL);
			comp = cal_micro(starv, ph->last_eat);
		}
		log_died(ph);
		return (1);
	}
	return (0);
}

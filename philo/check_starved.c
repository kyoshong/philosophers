/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_starved.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:41:20 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/17 19:47:33 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_starv_eat(long comp, t_philo *philo)
{
	if (comp > philo->rules->time_to_die)
	{
		philo->rules->philo_died = 1;
		return (1);
	}
	return (0);
}

int	check_starv_sleep(struct timeval begin, struct timeval end, t_philo *ph)
{
	int comp;

	comp = cal_micro(begin, end);
	if ((comp + ph->rules->time_to_sleep) > ph->rules->time_to_die)
	{
		if (comp > ph->rules->time_to_die)
		{
			printf("just died %d\n", ph->id);
			log_died(ph, begin);
		}
		else
		{
			printf("sleep over dead %d\n", ph->id);
			log_sleeping(ph, begin);
			while (comp <= ph->rules->time_to_die)
			{
				gettimeofday(&begin, NULL);
				comp = cal_micro(begin, end);
				usleep(100);
			}
		}
		return (1);
	}
	return (0);
}

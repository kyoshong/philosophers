/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_loop_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:42:31 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 19:49:39 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_life_count(void *i)
{
	t_philo philo;

	philo.id = ++rules.thread_id;
	philo.count_eat = 0;
	if (philo.id == 1)
		philo.right = rules.num_philosophers - 1;
	else
		philo.right = philo.id - 2;
	philo.left = philo.id - 1;
	philo.right_hand = 0;
	philo.left_hand = 0;
	life_loop_count(philo);
	return (i);
}

void	life_loop_count(t_philo philo)
{
	struct timeval	starv;
	struct timeval	last_eat;
	long			starved;

	gettimeofday(&starv, NULL);
	last_eat = rules.stamp;
	starved = cal_micro(starv, last_eat);
	while ((!philo_died) && (starved <= rules.time_to_die))
	{
		gettimeofday(&starv, NULL);
		starved = cal_micro(starv, last_eat);
		pick_up(&philo);
		if (philo.left_hand && philo.right_hand)
		{
			last_eat = eating(&philo, last_eat);
			++philo.count_eat;
			if (philo.count_eat == rules.num_of_must_eat)
			{
				rules.full_philos++;
				break ;
			}
			if (last_eat.tv_sec == -1)
				break ;
			if (sleeping(&philo, last_eat))
				break ;
			thinking(&philo);
		}
	}
	log_died(starv, philo.id);
}

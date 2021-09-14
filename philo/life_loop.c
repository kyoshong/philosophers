/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:04:38 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 19:59:47 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_starv_eat(long comp)
{
	// printf("last_eat : %ld %d\n", ((last_eat.tv_sec - rules.stamp.tv_sec) * 1000) + ((last_eat.tv_usec - rules.stamp.tv_usec) / 1000), id);
	// printf("comp : %d id : %d\n", comp, id);
	if (comp > rules.time_to_die)
	{
		philo_died = 1;
		return (1);
	}
	// else if ((comp + add_time) > rules.time_to_die)
	// {
	// 	// printf("comp : %d\n", comp);
	// 	// printf("add time : %d\n", add_time);
	// 	// printf("eating over\nwait : %d\n", rules.time_to_die - comp);
	// 	printf("eat over dead %d\n", id);
	// 	printf("%ld %d has taken a fork\n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
	// 	gettimeofday(&present, NULL);
	// 	printf("%ld %d is eating\n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
	// 	usleep(rules.time_to_die - comp);
	// 	gettimeofday(&present, NULL);
	// 	printf("%ld %d died\n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
	// 	philo_died = 1;
	// 	return (1);
	// }
	return (0);
}

int	check_starv_sleep(struct timeval present, struct timeval last_eat, int id, int add_time)
{
	int comp;

	comp = cal_micro(present, last_eat);
	if ((comp + add_time) > rules.time_to_die)
	{
		if (comp > rules.time_to_die)
		{
			printf("just died %d\n", id);
		}
		else
		{
			printf("sleep over dead %d\n", id);
			printf("%ld %d is sleeping \n", cal_milli(present, rules.stamp), id);
			while (comp <= rules.time_to_die)
			{
				gettimeofday(&present, NULL);
				comp = cal_micro(present, last_eat);
				usleep(100);
			}
		}
		return (1);
	}
	return (0);
}

void	life_loop(t_philo philo)
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
			if (last_eat.tv_sec == -1)
				break ;
			if (sleeping(&philo, last_eat))
				break ;
			thinking(&philo);
		}
	}
	log_died(starv, philo.id);
}

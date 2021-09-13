/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:58:10 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 01:45:08 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_fork(struct timeval fork, int philo_num)
{
	if (philo_died)
		return ;
	printf("%ld %d has taken a fork\n", cal_milli(fork, rules.stamp), philo_num);
}

void	log_eating(struct timeval eat, int philo_num)
{
	if (philo_died)
		return ;
	printf("%ld %d is eating\n", cal_milli(eat, rules.stamp), philo_num);
}

void	log_sleeping(struct timeval sleep, int philo_num)
{
	if (philo_died)
		return ;
	printf("%ld %d is sleeping\n", cal_milli(sleep, rules.stamp), philo_num);
}

void	log_thinking(struct timeval think, int philo_num)
{
	if (philo_died)
		return ;
	printf("%ld %d is thinking\n", cal_milli(think, rules.stamp), philo_num);
}

void	log_died(struct timeval died, int philo_num)
{
	if (philo_died)
		return ;
	printf("%ld %d died\n", cal_milli(died, rules.stamp), philo_num);
}

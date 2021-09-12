/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:58:10 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/12 14:16:18 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_fork(struct timeval fork, int philo_num)
{
	printf("%ld %d has taken a fork\n", ((fork.tv_sec - rules.stamp.tv_sec) * 1000) \
	 + ((fork.tv_usec - rules.stamp.tv_usec) / 1000), philo_num);
}

void	log_eating(struct timeval eat, int philo_num)
{
	printf("%d %d is eating\n",((eat.tv_sec - rules.stamp.tv_sec) * 1000) \
	 + ((eat.tv_usec - rules.stamp.tv_usec) / 1000), philo_num);
}

void	log_sleeping(struct timeval sleep, int philo_num)
{
	printf("%d %d is sleeping\n",((sleep.tv_sec - rules.stamp.tv_sec) * 1000) \
	 + ((sleep.tv_usec - rules.stamp.tv_usec) / 1000), philo_num);
}

void	log_thinking(struct timeval think, int philo_num)
{
	printf("%d %d is thinking\n", ((think.tv_sec - rules.stamp.tv_sec) * 1000) \
	 + ((think.tv_usec - rules.stamp.tv_usec) / 1000), philo_num);
}

void	log_died(struct timeval died, int philo_num)
{
	printf("%d %d died\n", ((died.tv_sec - rules.stamp.tv_sec) * 1000) \
	 + ((died.tv_usec - rules.stamp.tv_usec) / 1000), philo_num);
}

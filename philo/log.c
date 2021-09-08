/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:58:10 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/08 21:41:13 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_fork(int time, int philo_num)
{
	printf("%d %d has taken a fork\n", time, philo_num);
}

void	log_eating(int time, int philo_num)
{
	printf("%d %d is eating\n", time, philo_num);
}

void	log_sleeping(int time, int philo_num)
{
	printf("%d %d is sleeping\n", time, philo_num);
}

void	log_thinking(int time, int philo_num)
{
	printf("%d %d is thinking\n", time, philo_num);
}

void	log_died(int time, int philo_num)
{
	printf("%d %d died\n", time, philo_num);
}

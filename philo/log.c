/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:58:10 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/18 01:57:14 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_fork(int time, int philo_num)
{
	printf("%d %d ", time, philo_num);
	printf("has taken a fork\n");
}

void	log_eating(int time, int philo_num)
{
	printf("%d %d ", time, philo_num);
	printf("is eating\n");
}

void	log_sleeping(int time, int philo_num)
{
	printf("%d %d ", time, philo_num);
	printf("is sleeping\n");
}

void	log_thinking(int time, int philo_num)
{
	printf("%d %d ", time, philo_num);
	printf("is thinking\n");
}

void	log_died(int time, int philo_num)
{
	printf("%d %d ", time, philo_num);
	printf("died\n");
}

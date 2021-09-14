/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:58:10 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 20:01:44 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_fork(struct timeval fork, int philo_num)
{
	pthread_mutex_lock(&(rules.print_log));
	if (philo_died)
		return ;
	printf("%ld %d has taken a fork\n", cal_milli(fork, rules.stamp), philo_num);
	pthread_mutex_unlock(&(rules.print_log));
}

void	log_eating(struct timeval eat, int philo_num)
{
	pthread_mutex_lock(&(rules.print_log));
	if (philo_died)
		return ;
	printf("%ld %d is eating\n", cal_milli(eat, rules.stamp), philo_num);
	pthread_mutex_unlock(&(rules.print_log));
}

void	log_sleeping(struct timeval sleeping, int philo_num)
{
	pthread_mutex_lock(&(rules.print_log));
	if (philo_died)
		return ;
	printf("%ld %d is sleeping\n", cal_milli(sleeping, rules.stamp), philo_num);
	pthread_mutex_unlock(&(rules.print_log));
}

void	log_thinking(struct timeval think, int philo_num)
{
	pthread_mutex_lock(&(rules.print_log));
	if (philo_died)
		return ;
	printf("%ld %d is thinking\n", cal_milli(think, rules.stamp), philo_num);
	pthread_mutex_unlock(&(rules.print_log));
}

void	log_died(struct timeval died, int philo_num)
{
	pthread_mutex_lock(&(rules.print_log));
	philo_died = 1;
	usleep(1000);
	if (!philo_died)
	{
		printf("%ld %d died\n", cal_milli(died, rules.stamp), philo_num);
	}
	return ;
	pthread_mutex_unlock(&(rules.print_log));

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:58:10 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/17 19:55:04 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_fork(t_philo *philo, struct timeval fork)
{
	pthread_mutex_lock(&(philo->rules->print_log));
	if (!philo->rules->philo_died)
		printf("%ld %d has taken a fork\n", \
		cal_milli(fork, philo->rules->stamp), philo->id);
	pthread_mutex_unlock(&(philo->rules->print_log));
}

void	log_eating(t_philo *philo, struct timeval eat)
{
	pthread_mutex_lock(&(philo->rules->print_log));
	if (!philo->rules->philo_died)
		printf("%ld %d is eating\n", \
		cal_milli(eat, philo->rules->stamp), philo->id);
	pthread_mutex_unlock(&(philo->rules->print_log));
}

void	log_sleeping(t_philo *philo, struct timeval sleeping)
{
	pthread_mutex_lock(&(philo->rules->print_log));
	if (!philo->rules->philo_died)
		printf("%ld %d is sleeping\n", \
		cal_milli(sleeping, philo->rules->stamp), philo->id);
	pthread_mutex_unlock(&(philo->rules->print_log));
}

void	log_thinking(t_philo *philo, struct timeval think)
{
	pthread_mutex_lock(&(philo->rules->print_log));
	if (!philo->rules->philo_died)
		printf("%ld %d is thinking\n", \
		cal_milli(think, philo->rules->stamp), philo->id);
	pthread_mutex_unlock(&(philo->rules->print_log));
}

void	log_died(t_philo *philo, struct timeval died)
{
	pthread_mutex_lock(&(philo->rules->print_log));
	philo->rules->philo_died = 1;
	usleep(1000);
	if (!philo->rules->philo_died)
		printf("%ld %d died\n", \
		cal_milli(died, philo->rules->stamp), philo->id);
	return ;
	pthread_mutex_unlock(&(philo->rules->print_log));
}

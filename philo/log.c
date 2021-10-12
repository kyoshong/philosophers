/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:58:10 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/12 19:51:51 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval	log_print(t_philo *philo, char *msg)
{
	struct timeval	time;

	pthread_mutex_lock(&philo->rules->print_log);
	gettimeofday(&time, NULL);
	if (!philo->rules->philo_died)
	{
		printf(msg, cal_micro(time, philo->rules->stamp) / 1000, philo->id);
	}
	pthread_mutex_unlock(&philo->rules->print_log);
	return (time);
}

void	log_died(t_philo *philo)
{
	struct timeval	time;

	pthread_mutex_lock(&philo->rules->print_log);
	gettimeofday(&time, NULL);
	if (!(philo->rules->philo_died))
	{
		printf("%lld %d died\n", \
		cal_micro(time, philo->rules->stamp) / 1000, philo->id);
	}
	philo->rules->philo_died = 1;
	pthread_mutex_unlock(&philo->rules->print_log);
}

void	print_error(char *str)
{
	printf("%s\n", str);
}

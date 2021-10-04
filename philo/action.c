/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:54:47 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/03 01:41:30 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	long long		starv;
	struct timeval	eat;

	log_print(philo, "%ld %d has taken a fork\n");
	philo->last_eat = log_print(philo, "%ld %d is eating\n");
	if (check_starv_eat(philo))
		return ;
	starv = 0;
	while (starv <= (long long)philo->rules->time_to_eat)
	{
		gettimeofday(&eat, NULL);
		starv = cal_micro(eat, philo->last_eat);
	}
	put_down(philo);
	sleeping(philo);
	return ;
}

void	sleeping(t_philo *philo)
{
	struct timeval	sleeping;
	struct timeval	start;
	long long		starv;

	if (philo->rules->philo_died)
		return ;
	sleeping = log_print(philo, "%ld %d is sleeping\n");
	if (check_starv_sleep(sleeping, philo))
		return ;
	gettimeofday(&start, NULL);
	starv = 0;
	while (starv <= (long long)philo->rules->time_to_sleep)
	{
		gettimeofday(&start, NULL);
		starv = cal_micro(start, sleeping);
	}
	thinking(philo);
	return ;
}

void	thinking(t_philo *philo)
{
	if (philo->rules->philo_died)
		return ;
	log_print(philo, "%ld %d is thinking\n");
	return ;
}

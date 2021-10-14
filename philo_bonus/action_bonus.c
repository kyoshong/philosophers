/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:54:47 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/14 17:47:56 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philo *philo)
{
	long long		starv;
	struct timeval	eat;

	sem_wait(philo->rules->bch_forks);
	log_print(philo, "%ld %d has taken a fork\n");
	philo->last_eat = log_print(philo, "%ld %d is eating\n");
	starv = 0;
	while (starv <= (long long)philo->rules->time_to_eat)
	{
		gettimeofday(&eat, NULL);
		starv = cal_micro(eat, philo->last_eat);
	}
	if (philo->rules->num_of_must_eat > -1)
		sem_post(philo->rules->cunt_eat);
	sem_post(philo->rules->bch_forks);
	sleeping(philo);
	return ;
}

void	sleeping(t_philo *philo)
{
	struct timeval	sleeping;
	struct timeval	start;
	long long		starv;

	sleeping = log_print(philo, "%ld %d is sleeping\n");
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
	log_print(philo, "%ld %d is thinking\n");
	usleep(10);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:54:47 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/14 03:54:46 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	count_eat(t_philo *philo)
{
	if (++philo->count_eat == philo->rules->num_of_must_eat)
	{
		pthread_mutex_lock(&philo->rules->counting_eat);
		philo->rules->full_philos++;
		if (philo->rules->full_philos == philo->rules->num_philos)
			philo->rules->philo_died = 1;
		pthread_mutex_unlock(&philo->rules->counting_eat);
	}
}

void	eating(t_philo *philo)
{
	long long		starv;
	struct timeval	eat;

	pick_up(philo);
	log_print(philo, "%ld %d has taken a fork\n");
	philo->last_eat = log_print(philo, "%ld %d is eating\n");
	starv = 0;
	while (starv <= (long long)philo->rules->time_to_eat)
	{
		gettimeofday(&eat, NULL);
		starv = cal_micro(eat, philo->last_eat);
	}
	if (philo->rules->num_of_must_eat > 0)
		count_eat(philo);
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
	starv = 0;
	while (starv <= philo->rules->time_to_sleep)
	{
		gettimeofday(&start, NULL);
		starv = cal_micro(start, sleeping);
	}
	thinking(philo);
	return ;
}

void	thinking(t_philo *philo)
{
	struct timeval	thinking;

	if (philo->rules->philo_died)
		return ;
	thinking = log_print(philo, "%ld %d is thinking\n");
	return ;
}

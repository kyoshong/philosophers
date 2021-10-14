/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:58:10 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/13 20:13:32 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

struct timeval	log_print(t_philo *philo, char *msg)
{
	struct timeval	time;

	sem_wait(philo->rules->print_log);
	gettimeofday(&time, NULL);
	printf(msg, cal_micro(time, philo->rules->stamp) / 1000, philo->id);
	sem_post(philo->rules->print_log);
	return (time);
}

void	log_died(t_philo *philo)
{
	struct timeval	time;

	sem_wait(philo->rules->print_log);
	gettimeofday(&time, NULL);
	printf("%ld %d died\n", \
		cal_micro(time, philo->rules->stamp) / 1000, philo->id);
	exit(1);
}

long	cal_micro(struct timeval now, struct timeval std)
{
	return (((now.tv_sec - std.tv_sec) * 1000000) \
	+ (now.tv_usec - std.tv_usec));
}

void	print_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

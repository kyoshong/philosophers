/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:58:10 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/12 18:18:25 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

struct timeval	log_print(t_philo *philo, char *msg)
{
	struct timeval	time;

	sem_wait(philo->rules->print_log);
	gettimeofday(&time, NULL);
		printf(msg, cal_milli(time, philo->rules->stamp), philo->id);
	sem_post(philo->rules->print_log);
	return (time);
}

void	log_died(t_philo *philo)
{
	struct timeval	time;

	sem_wait(philo->rules->print_log);
	gettimeofday(&time, NULL);
		printf("%ld %d died\n", \
		cal_milli(time, philo->rules->stamp), philo->id);
	sem_post(philo->rules->print_log);
}

void	print_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	free_print_error(char *str, void *arg)
{
	printf("%s\n", str);
	free(&arg);
}

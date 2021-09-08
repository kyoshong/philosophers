/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:04:38 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/08 22:41:11 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	life_loop(t_philo *philo)
{
	struct timeval eat;

	pthread_mutex_lock(&(rules.lock));
	if (rules.fork_list[philo->left] && rules.fork_list[philo->right])
	{
		rules.fork_list[philo->left] = 0;
		rules.fork_list[philo->right] = 0;
		gettimeofday(&eat, NULL);
		printf("%d %d has taken a fork\n", eat.tv_usec - rules.stemp.tv_usec,
		philo->philo_id);
		gettimeofday(&eat, NULL);
		printf("%d %d is eating\n", eat.tv_usec - rules.stemp.tv_usec,
		philo->philo_id);
		usleep(rules.time_to_eat);
		rules.fork_list[philo->left] = 1;
		rules.fork_list[philo->right] = 1;
	}
	pthread_mutex_unlock(&(rules.lock));
}

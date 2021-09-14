/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:54:47 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 15:23:21 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	preempt(t_philo *philo)
{
	pthread_mutex_lock(&(rules.change));
	if (rules.fork_list[philo->left])
	{
		printf("%d has taken a philo.left fork\n", philo->id);
		rules.fork_list[philo->left] = 0;
		philo->left_hand = 1;
	}
	else if (rules.fork_list[philo->right])
	{
		printf("%d has taken a philo.left fork\n", philo->id);
		rules.fork_list[philo->right] = 0;
		philo->right_hand = 1;
	}
	pthread_mutex_unlock(&(rules.change));
}

struct timeval	eating(t_philo *philo, struct timeval last_eat)
{
	long starved;
	struct timeval eat;
	struct timeval fork;


	gettimeofday(&fork, NULL);
	log_fork(fork, philo->id);
	starved = cal_micro(fork, last_eat);
	if (check_starv_eat(starved))
	{
		log_died(fork, philo->id);
		printf("eat died\n");
		eat.tv_sec = -1;
		return (eat);
	}
	gettimeofday(&eat, NULL);
	last_eat = eat;
	log_eating(eat, philo->id);
	starved = 0;
	while (starved <= rules.time_to_eat + 100)
	{
		gettimeofday(&eat, NULL);
		starved = cal_micro(eat, last_eat);
	}
	put_down(philo);
	return (eat);
}

int	sleeping(t_philo *philo, struct timeval last_eat)
{
	struct timeval sleep;
	struct timeval start;
	long starved;

	gettimeofday(&sleep, NULL);
	log_sleeping(sleep, philo->id);
	if (check_starv_sleep(sleep ,last_eat, philo->id, rules.time_to_sleep))
	{
		return (1);
	}
	gettimeofday(&start, NULL);
	starved = 0;
	while (starved <= rules.time_to_sleep)
	{
		gettimeofday(&start, NULL);
		starved = cal_micro(start, sleep);
	}
	return (0);
}

void	thinking(t_philo *philo)
{
	struct timeval think;

	gettimeofday(&think, NULL);
	log_thinking(think, philo->id);
}

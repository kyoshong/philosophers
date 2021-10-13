/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:10:07 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/14 03:54:46 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&(philo->rules->fork_list[philo->right]));
		pthread_mutex_lock(&(philo->rules->fork_list[philo->left]));
		return ;
	}
	pthread_mutex_lock(&(philo->rules->fork_list[philo->left]));
	pthread_mutex_lock(&(philo->rules->fork_list[philo->right]));
}

void	put_down(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->rules->fork_list[philo->right]));
	pthread_mutex_unlock(&(philo->rules->fork_list[philo->left]));
}

int	init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&rules->print_log, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(rules->counting_eat), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(rules->count_over), NULL) != 0)
		return (1);
	while (i < rules->num_philos)
	{
		pthread_mutex_init(&(rules->fork_list[i]), NULL);
		i++;
	}
	return (0);
}

int	mutex_unlock_all(t_rules *rules)
{
	int	i;

	i = 0;
	if (pthread_mutex_unlock(&rules->print_log) != 0)
		return (1);
	if (pthread_mutex_unlock(&(rules->counting_eat)) != 0)
		return (1);
	if (pthread_mutex_unlock(&(rules->count_over)) != 0)
		return (1);
	while (i < rules->num_philos)
	{
		pthread_mutex_unlock(&(rules->fork_list[i]));
		i++;
	}
	return (0);
}

int	mutex_destroy_all(t_rules *rules)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&(rules->print_log)) != 0)
		return (1);
	if (pthread_mutex_destroy(&(rules->counting_eat)) != 0)
		return (1);
	if (pthread_mutex_destroy(&(rules->count_over)) != 0)
		return (1);
	while (i < rules->num_philos)
	{
		pthread_mutex_destroy(&(rules->fork_list[i]));
		i++;
	}
	return (0);
}

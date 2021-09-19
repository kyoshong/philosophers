/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:10:07 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/17 19:52:40 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_rules *rules)
{
	pthread_mutex_init(&(rules->pick_up_all), NULL);
	pthread_mutex_init(&(rules->pick_up_left), NULL);
	pthread_mutex_init(&(rules->pick_up_right), NULL);
	pthread_mutex_init(&(rules->print_log), NULL);
	pthread_mutex_init(&(rules->put_down), NULL);
	pthread_mutex_init(&(rules->counting_eat), NULL);
	return (0);
}

int		mutex_unlock_all(t_rules *rules)
{
	if (pthread_mutex_unlock(&(rules->pick_up_all)) != 0)
		return (1);
	if (pthread_mutex_unlock(&(rules->pick_up_left)) != 0)
		return (1);
	if (pthread_mutex_unlock(&(rules->pick_up_right)) != 0)
		return (1);
	if (pthread_mutex_unlock(&(rules->print_log)) != 0)
		return (1);
	if (pthread_mutex_unlock(&(rules->put_down)) != 0)
		return (1);
	if (pthread_mutex_unlock(&(rules->counting_eat)) != 0)
		return (1);
	return (0);
}

int		mutex_destroy_all(t_rules *rules)
{
	if (pthread_mutex_destroy(&(rules->pick_up_all)) != 0)
		return (1);
	if (pthread_mutex_destroy(&(rules->pick_up_left)) != 0)
		return (1);
	if (pthread_mutex_destroy(&(rules->pick_up_right)) != 0)
		return (1);
	if (pthread_mutex_destroy(&(rules->print_log)) != 0)
		return (1);
	if (pthread_mutex_destroy(&(rules->put_down)) != 0)
		return (1);
	if (pthread_mutex_destroy(&(rules->counting_eat)) != 0)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:48:40 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/15 21:09:54 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up_all(t_philo *philo)
{
	pthread_mutex_lock(&(philo->rules->pick_up_all));
	philo->rules->fork_list[philo->left] = 0;
	philo->rules->fork_list[philo->right] = 0;
	philo->left_hand = 1;
	philo->right_hand = 1;
	pthread_mutex_unlock(&(philo->rules->pick_up_all));
}

void	pick_up_left(t_philo *philo)
{
	pthread_mutex_lock(&(philo->rules->pick_up_left));
	if (philo->right_hand && philo->rules->fork_list[philo->left])
	{
		philo->rules->fork_list[philo->left] = 0;
		philo->left_hand = 1;
	}
	else if (philo->rules->fork_list[philo->right])
	{
		philo->rules->fork_list[philo->right] = 0;
		philo->right_hand = 1;
	}
	pthread_mutex_unlock(&(philo->rules->pick_up_left));
}

void	pick_up_right(t_philo *philo)
{
	pthread_mutex_lock(&(philo->rules->pick_up_right));
	if (philo->left_hand && philo->rules->fork_list[philo->right])
	{
		philo->rules->fork_list[philo->right] = 0;
		philo->right_hand = 1;
	}
	else if (philo->rules->fork_list[philo->left])
	{
		philo->rules->fork_list[philo->left] = 0;
		philo->left_hand = 1;
	}
	pthread_mutex_unlock(&(philo->rules->pick_up_right));
}

void	pick_up(t_philo *philo)
{
	if (philo->rules->fork_list[philo->right] \
	&& philo->rules->fork_list[philo->left])
	{
		pick_up_all(philo);
	}
	else if (philo->id % 2 == 0)
		pick_up_left(philo);
	else
		pick_up_right(philo);
}

void	put_down(t_philo *philo)
{
	pthread_mutex_lock(&(philo->rules->put_down));
	philo->rules->fork_list[philo->left] = 1;
	philo->rules->fork_list[philo->right] = 1;
	pthread_mutex_unlock(&(philo->rules->put_down));
	philo->left_hand = 0;
	philo->right_hand = 0;
}

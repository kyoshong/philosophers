/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:48:40 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 15:26:38 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up(t_philo *philo)
{
	pthread_mutex_lock(&(rules.pick_up));
	if (philo->id % 2 == 0)
	{
		if (philo->right_hand && rules.fork_list[philo->left])
		{
			rules.fork_list[philo->left] = 0;
			philo->left_hand = 1;
		}
		else if (rules.fork_list[philo->right])
		{
			rules.fork_list[philo->right] = 0;
			philo->right_hand = 1;
		}
	}
	else
	{
		if (philo->left_hand && rules.fork_list[philo->right])
		{
			rules.fork_list[philo->right] = 0;
			philo->right_hand = 1;
		}
		else if (rules.fork_list[philo->left])
		{
			rules.fork_list[philo->left] = 0;
			philo->left_hand = 1;
		}
	}
	pthread_mutex_unlock(&(rules.pick_up));
}

void	put_down(t_philo *philo)
{
	pthread_mutex_lock(&(rules.put_down));
	rules.fork_list[philo->left] = 1;
	rules.fork_list[philo->right] = 1;
	philo->left_hand = 0;
	philo->right_hand = 0;
	pthread_mutex_unlock(&(rules.put_down));
}

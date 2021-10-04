/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:48:40 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/01 22:52:52 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up(t_philo *philo)
{
	pthread_mutex_lock(&(philo->rules->fork_list[philo->right]));
	pthread_mutex_lock(&(philo->rules->fork_list[philo->left]));
}

void	put_down(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->rules->fork_list[philo->right]));
	pthread_mutex_unlock(&(philo->rules->fork_list[philo->left]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:48:40 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 13:18:39 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_up(t_philo *philo)
{
	pthread_mutex_lock(&(rules.pick_up));
	rules.fork_list[philo->left] = 0;
	rules.fork_list[philo->right] = 0;
	pthread_mutex_unlock(&(rules.pick_up));
}

void	put_down(t_philo *philo)
{
	pthread_mutex_lock(&(rules.put_down));
	rules.fork_list[philo->left] = 1;
	rules.fork_list[philo->right] = 1;
	pthread_mutex_unlock(&(rules.put_down));
}

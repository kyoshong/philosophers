/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_fork_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:48:40 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/10 17:37:16 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	pick_up(t_philo *philo)
{
	sem_wait(philo->rules->bch_forks);
}

void	put_down(t_philo *philo)
{
	sem_post(philo->rules->bch_forks);
}

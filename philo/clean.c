/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:09:37 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 17:19:56 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_all(void)
{
	while (!philo_died)
	{
	}
	pthread_mutex_unlock(&(rules.pick_up_all));
	pthread_mutex_unlock(&(rules.pick_up_left));
	pthread_mutex_unlock(&(rules.pick_up_right));
	pthread_mutex_unlock(&(rules.print_log));
	pthread_mutex_unlock(&(rules.put_down));
	pthread_mutex_destroy(&(rules.pick_up_all));
	pthread_mutex_destroy(&(rules.pick_up_left));
	pthread_mutex_destroy(&(rules.pick_up_right));
	pthread_mutex_destroy(&(rules.print_log));
	pthread_mutex_destroy(&(rules.put_down));
}

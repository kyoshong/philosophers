/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:06:13 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/12 18:14:12 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	cal_micro(struct timeval std)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec - std.tv_sec) * 1000000) \
	+ (now.tv_usec - std.tv_usec));
}

long	cal_milli(struct timeval std)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec - std.tv_sec) * 1000) \
	+ ((now.tv_usec - std.tv_usec) / 1000));
}

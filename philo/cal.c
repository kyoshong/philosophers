/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:06:13 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/03 01:39:26 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	cal_micro(struct timeval now, struct timeval std)
{
	return (((now.tv_sec - std.tv_sec) * 1000000) \
	+ (now.tv_usec - std.tv_usec));
}

long	cal_milli(struct timeval now, struct timeval std)
{
	return (((now.tv_sec - std.tv_sec) * 1000) \
	+ ((now.tv_usec - std.tv_usec) / 1000));
}

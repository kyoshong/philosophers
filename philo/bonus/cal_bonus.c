/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:06:13 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/12 19:50:57 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	cal_micro(struct timeval now, struct timeval std)
{
	return (((now.tv_sec - std.tv_sec) * 1000000) \
	+ (now.tv_usec - std.tv_usec));
}

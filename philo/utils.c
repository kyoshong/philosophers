/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:20:18 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/18 02:07:00 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	isnum(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	space_check(char b)
{
	if (b == ' ' || b == '\n' || b == '\r' || b == '\t' || b == '\f')
		return (1);
	else if (b == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	num;
	long	start;

	i = 0;
	num = 0;
	while (space_check(str[i]) == 1 && str[i] != '\0')
		i++;
	start = i;
	while (str[i] != '\0')
	{
		if (isnum(str[i]) == 0)
			print_error("ARG_ERROR");
		i++;
	}
	i = start;
	while ((str[i] >= '0' && (str[i] <= '9') && str[i] != '\0'))
	{
		num = (num * 10) + ((str[i] - '0'));
		if (num > 2147483647)
			print_error("ARG_ERROR");
		i++;
	}
	return (num);
}

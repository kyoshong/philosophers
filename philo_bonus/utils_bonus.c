/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:20:18 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/08 00:16:51 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	isnum(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (!(str[i] > 47 && str[i] < 58))
			return (1);
		i++;
	}
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

	i = 0;
	num = 0;
	while (space_check(str[i]))
		i++;
	if (isnum((char *)str, i) || str[i] == '\0')
		return (-1);
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		num = (num * 10) + ((str[i] - '0'));
		if (num > 2147483647)
		{
			print_error("ARG_ERROR");
			return (-1);
		}
		i++;
	}
	return (num);
}

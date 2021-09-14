/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:58:14 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 15:49:01 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *str)
{
	printf("%s", str);
	return (-1);
}

int	free_print_error(char *str, void *arg)
{
	printf("%s", str);
	free(&arg);
	return (-1);
}

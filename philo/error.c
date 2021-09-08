/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 00:58:14 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/08 17:59:41 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *str)
{
	printf("%s", str);
	exit(1);
}

void	free_print_error(char *str, void *arg)
{
	printf("%s", str);
	free(&arg);
	exit(1);
}

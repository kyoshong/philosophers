/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:37:28 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 16:00:39 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char const *argv[])
{
	if (argc < 5)
		print_error("TOO_FEW_ARG");
	if (argc > 6)
		print_error("TOO_MANY_ARG");
	if (lifes(argc, argv) < 0)
		return (-1);
	return (0);
}

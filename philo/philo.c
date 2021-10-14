/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:37:28 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/14 19:24:22 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char const *argv[])
{
	if (argc < 5 || argc > 6)
	{
		print_error("ARG_ERROR");
		return (1);
	}
	argc--;
	while (argc > 0)
	{
		if (ft_atoi(argv[argc]) < 1)
		{
			print_error("ARG_NUM_ERROR");
			return (1);
		}
		argc--;
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	if (check_args(argc, argv))
		return (1);
	lifes(argc, argv);
	return (0);
}

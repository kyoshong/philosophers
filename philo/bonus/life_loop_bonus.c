/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:04:38 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/12 18:10:33 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	life_loop(t_philo philo)
{
	philo.last_eat = philo.rules->stamp;
	while (1)
	{
		pick_up(&philo);
		printf("%d\n", philo.id);
		eating(&philo);
	}
}

t_philo	set_philos(t_rules *rules, int i)
{
	t_philo	philo;

	philo.id = i + 1;
	philo.count_eat = 0;
	philo.rules = rules;
	return (philo);
}

int	create_philos(t_rules *rules)
{
	int	i;
	int pid;
	int stat;

	i = 0;
	gettimeofday(&(rules->stamp), NULL);
	while (i < rules->num_philos)
	{
		pid = fork();
		if (pid == 0)
		{
			life_loop(set_philos(rules, i));
			exit(0);
		}
		else if (pid < 0)
			print_error("FORK_ERROR\n");
		waitpid(pid, &stat, WNOHANG);
		usleep(100);
		i++;
	}
	return (0);
}

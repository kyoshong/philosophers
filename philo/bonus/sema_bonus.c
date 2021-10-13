/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sema_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:10:07 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/14 04:22:30 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	open_sema(t_rules *rules)
{
	unlink_sema_all();
	rules->print_log = sem_open("print_log", O_CREAT, 0644, 1);
	if (rules->print_log == SEM_FAILED)
		return (1);
	rules->cunt_eat = sem_open("cunt_eat", O_CREAT, 0644, 1);
	if (rules->cunt_eat == SEM_FAILED)
		return (1);
	rules->bch_forks = sem_open("bunch_of_forks", O_CREAT, \
	0644, rules->num_philos / 2);
	if (rules->bch_forks == SEM_FAILED)
		return (1);
	return (0);
}

void	close_sema_all(t_rules *rules)
{
	if (sem_close(rules->print_log) < 0)
		print_error("print_log Sem Close Error\n");
	if (sem_close(rules->cunt_eat) < 0)
		print_error("cunt_eat Sem Close Error\n");
	if (sem_close(rules->bch_forks) < 0)
		print_error("bch_forks Sem Close Error\n");
}

void	unlink_sema_all(void)
{
	sem_unlink("print_log");
	sem_unlink("cunt_eat");
	sem_unlink("bunch_of_forks");
}

void	*count_eat_sema(void *rule)
{
	int		i;
	int		must_eat;
	t_rules	*rules;

	rules = rule;
	i = 0;
	must_eat = rules->num_of_must_eat * rules->num_philos + 1;
	while (i < must_eat)
	{
		sem_wait(rules->cunt_eat);
		i++;
	}
	rules->philo_died = 1;
	return (rule);
}

void	*check_starv_thread(void *philos)
{
	t_philo			*philo;
	struct timeval	time;
	long long		comp;

	philo = philos;
	while (1)
	{
		gettimeofday(&time, NULL);
		comp = cal_micro(time, philo->last_eat);
		if (comp > philo->rules->time_to_die)
		{
			log_died(philo);
		}
		usleep(100);
	}
	return (philos);
}

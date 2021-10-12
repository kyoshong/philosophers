/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sema_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:10:07 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/12 18:02:31 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	open_sema(t_rules *rules)
{
	unlink_sema_all();
	rules->print_log = sem_open("print_log", O_CREAT, 0644, 1);
	if (rules->print_log == SEM_FAILED)
		return (1);
	rules->cunt_eat = sem_open("cunt_eat", O_CREAT, 0644, rules->num_philos/2);
	if (rules->cunt_eat == SEM_FAILED)
		return (1);
	rules->bch_forks = sem_open("bunch_of_forks", O_CREAT, 0644, rules->num_philos/2);
	if (rules->bch_forks == SEM_FAILED)
		return (1);
	return (0);
}

void	close_sema_all(t_rules *rules)
{
	if (sem_close(rules->print_log) < 0)
		print_error("Sem Close Error\n");
	if (sem_close(rules->cunt_eat) < 0)
		print_error("Sem Close Error\n");
	if (sem_close(rules->bch_forks) < 0)
		print_error("Sem Close Error\n");
}

void	unlink_sema_all(void)
{
	sem_unlink("print_log");
	sem_unlink("cunt_eat");
	sem_unlink("bunch_of_forks");
}

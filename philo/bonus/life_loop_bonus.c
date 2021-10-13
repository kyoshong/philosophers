/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:04:38 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/14 04:08:37 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*life_loop(void *philos)
{
	int			stat;
	int			pid;
	t_philo		*philo;

	philo = philos;
	philo->last_eat = philo->rules->stamp;
	pid = fork();
	if (pid == 0)
	{
		if (pthread_create(&philo->s_thread, NULL, check_starv_thread, \
		(void *)philo) != 0 || pthread_detach(philo->s_thread) != 0)
			exit(1);
		while (1)
			eating(philo);
	}
	else if (pid < 0)
		print_error("FORK_ERROR\n");
	philo->rules->philo_pid[philo->id - 1] = pid;
	waitpid(pid, &stat, 0);
	philo->rules->philo_died = 1;
	return (philos);
}

t_philo	set_philos(t_rules *rules, int i)
{
	t_philo	philo;

	philo.id = i + 1;
	philo.count_eat = 0;
	philo.rules = rules;
	return (philo);
}

int	create_philos(pthread_t *thread, t_philo *philos, t_rules *rules)
{
	int	i;

	i = 0;
	gettimeofday(&(rules->stamp), NULL);
	while (i < rules->num_philos)
	{
		philos[i] = set_philos(rules, i);
		if (pthread_create(&thread[i], NULL, life_loop, \
		(void *)&philos[i]) != 0 || pthread_detach(thread[i]) != 0)
			return (1);
		i++;
	}
	while (!rules->philo_died)
	{
	}
	close_sema_all(rules);
	unlink_sema_all();
	i = 0;
	while (i < rules->num_philos)
	{
		if (rules->philo_pid[i] > 0)
			kill(rules->philo_pid[i], SIGKILL);
		i++;
	}
	return (0);
}

int	make_thread(t_rules *rules)
{
	pthread_t	*thread;
	pthread_t	count;
	t_philo		*philos;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * rules->num_philos);
	if (thread == NULL)
		return (1);
	philos = (t_philo *)malloc(sizeof(t_philo) * rules->num_philos);
	if (philos == NULL)
	{
		free(thread);
		return (1);
	}
	if ((rules->num_of_must_eat > 0) && (pthread_create(&count, NULL, \
	count_eat_sema, (void *)rules) != 0 || pthread_detach(count) != 0))
		return (1);
	if (create_philos(thread, philos, rules))
		print_error("CREATE_THREAD_ERROR");
	free(thread);
	free(philos);
	return (0);
}

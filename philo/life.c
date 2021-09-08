/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:16:17 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/08 22:38:29 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_life(void *philo_arg)
{
	t_philo *philo;
	
	philo = (t_philo *)philo_arg;
	if (philo->philo_id == 1)
		philo->right = rules.num_philosophers;
	else
		philo->right = philo->philo_id - 1;
	philo->left = philo->philo_id;
	life_loop(philo);
	return (NULL);
}

void	set_life_rules(int argc, char const *argv[])
{
	rules.num_philosophers = ft_atoi(argv[1]);
	rules.fork_list = (int *)malloc(sizeof(int) * (rules.num_philosophers + 1));
	if (rules.fork_list == NULL)
		print_error("FORK_MALLOC_ERROR\n");
	rules.ready_q = (int *)malloc(sizeof(int) * (rules.num_philosophers + 1));
	if (rules.ready_q == NULL)
		print_error("ready_q_MALLOC_ERROR\n");
	memset(rules.fork_list, 1, sizeof(int) * (rules.num_philosophers + 1));
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6 && argv[5] >= 0)
		rules.num_of_must_eat = ft_atoi(argv[5]);
	else
		rules.num_of_must_eat = -1;
	pthread_mutex_init(&(rules.lock), NULL);
}

void	make_thread(void)
{
	pthread_t	*thread;
	t_philo		*philo;
	int			i;

	philo = (t_philo *)malloc(sizeof(t_philo) * rules.num_philosophers);
	if (philo == NULL)
		print_error("PHILO_MALLOC_ERROR\n");
	thread = (pthread_t *)malloc(sizeof(pthread_t) * rules.num_philosophers);
	if (thread == NULL)
		free_print_error("MALLOC_THREAD_ERROR\n", (void *)philo);
	i = 0;
	gettimeofday(&(rules.stemp), NULL);
	while (i < rules.num_philosophers)
	{
		philo[i].count_eat = 0;
		philo[i].philo_id = i + 1;
		pthread_create(&thread[i], NULL, start_life, (void *)&philo[i]);
		pthread_detach(thread[i]);
		i++;
	}
}

void	lifes(int argc, char const *argv[])
{
	set_life_rules(argc, argv);
	make_thread();
}

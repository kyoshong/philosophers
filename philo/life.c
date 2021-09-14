/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:16:17 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 15:04:52 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_life(void *i)
{
	t_philo philo;

	philo.id = ++rules.thread_id;
	philo.count_eat = 0;
	if (philo.id == 1)
		philo.right = rules.num_philosophers - 1;
	else
		philo.right = philo.id - 2;
	philo.left = philo.id - 1;
	philo.right_hand = 0;
	philo.left_hand = 0;
	life_loop(philo);
	return (i);
}

void	set_life_rules(int argc, char const *argv[])
{
	rules.num_philosophers = ft_atoi(argv[1]);
	rules.fork_list = (int *)malloc(sizeof(int) * (rules.num_philosophers));
	if (rules.fork_list == NULL)
		print_error("FORK_MALLOC_ERROR\n");
	memset(rules.fork_list, 1, sizeof(int) * (rules.num_philosophers));
	rules.time_to_die = ft_atoi(argv[2]) * 1000;
	rules.time_to_eat = ft_atoi(argv[3]) * 1000;
	rules.time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6 && argv[5] >= 0)
		rules.num_of_must_eat = ft_atoi(argv[5]);
	else
		rules.num_of_must_eat = -1;
	pthread_mutex_init(&(rules.pick_up), NULL);
	pthread_mutex_init(&(rules.put_down), NULL);
	pthread_mutex_init(&(rules.change), NULL);
}

void	make_thread(void)
{
	pthread_t	*thread;
	int			i;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * rules.num_philosophers);
	if (thread == NULL)
		print_error("MALLOC_THREAD_ERROR\n");
	i = 0;
	gettimeofday(&(rules.stamp), NULL);
	while (i < rules.num_philosophers)
	{
		pthread_create(&thread[i], NULL, start_life, (void *)&i);
		pthread_detach(thread[i]);
		i++;
		usleep(100);
	}
	while (!philo_died)
	{
	}
}

void	lifes(int argc, char const *argv[])
{
	set_life_rules(argc, argv);
	make_thread();
}

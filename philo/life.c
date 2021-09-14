/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:16:17 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/14 19:32:44 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_life(void *i)
{
	t_philo philo;

	philo.id = ++rules.thread_id;
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

int	set_life_rules(int argc, char const *argv[])
{
	if (ft_atoi(argv[1]) < 1)
		return (-1);
	rules.num_philosophers = ft_atoi(argv[1]);
	rules.fork_list = (int *)malloc(sizeof(int) * (rules.num_philosophers));
	if (rules.fork_list == NULL)
		print_error("FORK_MALLOC_ERROR\n");
	memset(rules.fork_list, 1, sizeof(int) * (rules.num_philosophers));
	rules.time_to_die = ft_atoi(argv[2]) * 1000;
	rules.time_to_eat = ft_atoi(argv[3]) * 1000;
	rules.time_to_sleep = ft_atoi(argv[4]) * 1000;
	if ((argc == 6) && (ft_atoi(argv[5]) >= 0))
		rules.num_of_must_eat = ft_atoi(argv[5]);
	else
		rules.num_of_must_eat = -1;
	rules.full_philos = 0;
	pthread_mutex_init(&(rules.pick_up_all), NULL);
	pthread_mutex_init(&(rules.pick_up_left), NULL);
	pthread_mutex_init(&(rules.pick_up_right), NULL);
	pthread_mutex_init(&(rules.print_log), NULL);
	pthread_mutex_init(&(rules.put_down), NULL);
	return (0);
}

int	make_thread(void)
{
	pthread_t	*thread;
	int			i;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * rules.num_philosophers);
	if (thread == NULL)
		print_error("MALLOC_THREAD_ERROR\n");
	i = 0;
	gettimeofday(&(rules.stamp), NULL);
	if (rules.num_of_must_eat > -1)
	{
		while (i < rules.num_philosophers)
		{
			pthread_create(&thread[i], NULL, start_life, (void *)&i);
			pthread_detach(thread[i]);
			i++;
			usleep(100);
		}
	}
	else
	{
		while (i < rules.num_philosophers)
		{
			pthread_create(&thread[i], NULL, start_life_count, (void *)&i);
			pthread_detach(thread[i]);
			i++;
			usleep(100);
		}
	}
	clean_all();
	return (0);
}

int	lifes(int argc, char const *argv[])
{
	if (set_life_rules(argc, argv) < 0)
		return (-1);
	if (make_thread() < 0)
		return (-1);
	return (0);
}

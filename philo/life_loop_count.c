// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   life_loop_count.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/09/06 21:04:38 by hyospark          #+#    #+#             */
// /*   Updated: 2021/09/11 22:57:03 by hyospark         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "philo.h"

// int	check_starv_eat(struct timeval present, struct timeval last_eat, int id)
// {
// 	int comp;

// 	comp = ((present.tv_sec - last_eat.tv_sec) * 1000000) + (present.tv_usec - last_eat.tv_usec);
// 	if (comp > rules.time_to_die)
// 	{
// 		printf("just died %d\n", id);
// 		gettimeofday(&present, NULL);
// 		printf("%ld %d died\n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
// 		philo_died = 1;
// 		return (1);
// 	}
// 	return (0);
// }

// int	check_starv_sleep(struct timeval present, struct timeval last_eat, int id, int add_time)
// {
// 	int comp;

// 	comp = ((present.tv_sec - last_eat.tv_sec) * 1000000) + (present.tv_usec - last_eat.tv_usec);
// 	if (comp > rules.time_to_die)
// 	{
// 		printf("just died %d\n", id);
// 		gettimeofday(&present, NULL);
// 		printf("%ld %d died\n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
// 		philo_died = 1;
// 		return (1);
// 	}
// 	else if ((comp + add_time) > rules.time_to_die)
// 	{
// 		printf("sleep over dead %d\n", id);
// 		gettimeofday(&present, NULL);
// 		printf("%ld %d is sleeping \n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
// 		usleep(rules.time_to_die - comp);
// 		gettimeofday(&present, NULL);
// 		printf("%ld %d died\n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
// 		philo_died = 1;
// 		return (1);
// 	}
// 	return (0);
// }

// void	life_loop(t_philo philo)
// {
// 	struct timeval starv;
// 	struct timeval eat;
// 	struct timeval fork;
// 	struct timeval sleep;
// 	struct timeval think;
// 	struct timeval last_eat;

// 	gettimeofday(&(rules.stamp), NULL);
// 	gettimeofday(&starv, NULL);
// 	last_eat = rules.stamp;
// 	while ((!philo_died) && ((starv.tv_sec - last_eat.tv_sec) * 1000000) + ((starv.tv_usec - last_eat.tv_usec)) <= rules.time_to_die)
// 	{
// 		if (rules.fork_list[philo.left] || rules.fork_list[philo.right])
// 		{
// 			if (rules.fork_list[philo.left])
// 			{
// 				pthread_mutex_lock(&(rules.pick_up));
// 				rules.fork_list[philo.left] = 0;
// 				philo.left_hand = 1;
// 				pthread_mutex_unlock(&(rules.pick_up));
// 			}
// 			if (rules.fork_list[philo.right])
// 			{
// 				pthread_mutex_lock(&(rules.pick_up));
// 				rules.fork_list[philo.left] = 0;
// 				philo.right_hand = 1;
// 				pthread_mutex_unlock(&(rules.pick_up));
// 			}
// 			if (philo.left_hand && philo.right_hand)
// 			{
// 				gettimeofday(&fork, NULL);
// 				if (check_starv_eat(fork, last_eat, philo.philo_id))
// 					break ;
// 				printf("%ld %d has taken a fork\n", ((fork.tv_sec - rules.stamp.tv_sec) * 1000)+ ((fork.tv_usec - rules.stamp.tv_usec) / 1000), philo.philo_id);
// 				gettimeofday(&eat, NULL);
// 				gettimeofday(&last_eat, NULL);
// 				printf("%ld %d is eating\n", ((eat.tv_sec - rules.stamp.tv_sec) * 1000) + ((eat.tv_usec - rules.stamp.tv_usec) / 1000),
// 				philo.philo_id);
// 				philo.count_eat++;
// 				usleep(rules.time_to_eat);
// 				pthread_mutex_lock(&(rules.put_down));
// 				rules.fork_list[philo.left] = 1;
// 				rules.fork_list[philo.right] = 1;
// 				philo.right_hand = 0;
// 				philo.left_hand = 0;
// 				pthread_mutex_unlock(&(rules.put_down));
// 			}
// 			else
// 				continue ;
// 		}
// 		else
// 		{
// 			gettimeofday(&starv, NULL);
// 			continue ;
// 		}
// 		gettimeofday(&sleep, NULL);
// 		if (check_starv_sleep(sleep ,last_eat, philo.philo_id, rules.time_to_sleep))
// 			break ;
// 		printf("%ld %d is sleeping\n", ((sleep.tv_sec - rules.stamp.tv_sec) * 1000)
// 		+ ((sleep.tv_usec - rules.stamp.tv_usec) / 1000), philo.philo_id);
// 		usleep(rules.time_to_sleep);
// 		gettimeofday(&think, NULL);
// 		printf("%ld %d is thinking\n", ((think.tv_sec - rules.stamp.tv_sec) * 1000)
// 		+ ((think.tv_usec - rules.stamp.tv_usec) / 1000), philo.philo_id);
// 		gettimeofday(&starv, NULL);
// 	}
// 	printf("%ld %d died\n", ((starv.tv_sec - rules.stamp.tv_sec) * 1000) + ((starv.tv_usec - rules.stamp.tv_usec) / 1000), philo.philo_id);
// 	philo_died = 1;
// }

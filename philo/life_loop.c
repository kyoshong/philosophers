/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:04:38 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/12 14:20:25 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_starv_eat(long comp)
{
	// printf("last_eat : %ld %d\n", ((last_eat.tv_sec - rules.stamp.tv_sec) * 1000) + ((last_eat.tv_usec - rules.stamp.tv_usec) / 1000), id);
	// printf("comp : %d id : %d\n", comp, id);
	if (comp > rules.time_to_die)
	{
		philo_died = 1;
		return (1);
	}
	// else if ((comp + add_time) > rules.time_to_die)
	// {
	// 	// printf("comp : %d\n", comp);
	// 	// printf("add time : %d\n", add_time);
	// 	// printf("eating over\nwait : %d\n", rules.time_to_die - comp);
	// 	printf("eat over dead %d\n", id);
	// 	printf("%ld %d has taken a fork\n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
	// 	gettimeofday(&present, NULL);
	// 	printf("%ld %d is eating\n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
	// 	usleep(rules.time_to_die - comp);
	// 	gettimeofday(&present, NULL);
	// 	printf("%ld %d died\n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
	// 	philo_died = 1;
	// 	return (1);
	// }
	return (0);
}

int	check_starv_sleep(struct timeval present, struct timeval last_eat, int id, int add_time)
{
	int comp;

	comp = ((present.tv_sec - last_eat.tv_sec) * 1000000) + (present.tv_usec - last_eat.tv_usec);
	if (comp > rules.time_to_die)
	{
		printf("just died %d\n", id);
		gettimeofday(&present, NULL);
		printf("%ld %d died\n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
		philo_died = 1;
		return (1);
	}
	else if ((comp + add_time) > rules.time_to_die)
	{
		printf("sleep over dead %d\n", id);
		gettimeofday(&present, NULL);
		printf("%ld %d is sleeping \n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
		usleep(rules.time_to_die - comp);
		gettimeofday(&present, NULL);
		printf("%ld %d died\n", ((present.tv_sec - rules.stamp.tv_sec) * 1000) + ((present.tv_usec - rules.stamp.tv_usec) / 1000), id);
		philo_died = 1;
		return (1);
	}
	return (0);
}

void	life_loop(t_philo philo)
{
	struct timeval starv;
	struct timeval eat;
	struct timeval fork;
	struct timeval sleep;
	struct timeval think;
	struct timeval last_eat;
	long temp;

	gettimeofday(&(rules.stamp), NULL);
	gettimeofday(&starv, NULL);
	last_eat = rules.stamp;
	while ((!philo_died) && ((starv.tv_sec - last_eat.tv_sec) * 1000000) + ((starv.tv_usec - last_eat.tv_usec)) <= rules.time_to_die)
	{
		// printf("id : %d %d %d\n", philo.philo_id, rules.fork_list[philo.left], rules.fork_list[philo.right]);

		// if ((rules.fork_list[philo.left] && rules.fork_list[philo.right]) || (philo.left_hand || philo.right_hand))
		// {
			// if (philo.left_hand && !rules.fork_list[philo.left])
			// {
			// 	pthread_mutex_lock(&(rules.change_left));
			// 	rules.fork_list[philo.left] = 1;
			// 	philo.left_hand = 0;
			// 	pthread_mutex_unlock(&(rules.change_left));
			// }
			// if (philo.right_hand && !rules.fork_list[philo.right])
			// {
			// 	pthread_mutex_lock(&(rules.change_right));
			// 	rules.fork_list[philo.right] = 1;
			// 	philo.right_hand = 0;
			// 	pthread_mutex_unlock(&(rules.change_right));
			// }
			if (rules.fork_list[philo.left] && rules.fork_list[philo.right])
			{
				pthread_mutex_lock(&(rules.pick_up_all));
				rules.fork_list[philo.left] = 0;
				rules.fork_list[philo.right] = 0;
				pthread_mutex_unlock(&(rules.pick_up_all));
				gettimeofday(&fork, NULL);
				log_fork(fork, philo.philo_id);
				temp = ((fork.tv_sec - last_eat.tv_sec) * 1000000) + (fork.tv_usec - last_eat.tv_usec);
				if (check_starv_eat(temp))
				{
					log_died(fork, philo.philo_id);
					break ;
				}
				gettimeofday(&eat, NULL);
				last_eat = eat;
				log_eat(eat, philo.philo_id);
				usleep(rules.time_to_eat);
				gettimeofday(&sleep, NULL);
				pthread_mutex_lock(&(rules.put_down));
				rules.fork_list[philo.left] = 1;
				rules.fork_list[philo.right] = 1;
				// philo.right_hand = 0;
				// philo.left_hand = 0;
				pthread_mutex_unlock(&(rules.put_down));
				if (check_starv_sleep(sleep ,last_eat, philo.philo_id, rules.time_to_sleep))
					break ;
				log_sleeping(sleep,philo.philo_id);
				usleep(rules.time_to_sleep);
				gettimeofday(&think, NULL);
				log_think(think, philo.philo_id);
				gettimeofday(&starv, NULL);
			}
		// }
		// else
		// 	continue ;
	
		// if (rules.fork_list[philo.left] || rules.fork_list[philo.right])
		// {
		// 	pthread_mutex_lock(&(rules.pick_up));
		// 	if (rules.fork_list[philo.left])
		// 	{
		// 		printf("%d has taken a philo.left fork\n", philo.philo_id);
		// 		rules.fork_list[philo.left] = philo.philo_id;
		// 		philo.left_hand = 1;
		// 	}
		// 	if (rules.fork_list[philo.right])
		// 	{
		// 		rules.fork_list[philo.right] = philo.philo_id;
		// 		philo.right_hand = 1;
		// 		printf("%d has taken a philo.right fork\n", philo.philo_id);
		// 	}
		// 	pthread_mutex_unlock(&(rules.pick_up));
		// }
	}
	printf("%ld %d died\n", ((starv.tv_sec - rules.stamp.tv_sec) * 1000) + ((starv.tv_usec - rules.stamp.tv_usec) / 1000), philo.philo_id);
	philo_died = 1;
}

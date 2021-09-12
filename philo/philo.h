/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:37:26 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/12 14:17:24 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <memory.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_rules
{
	int	num_philosophers;
	int time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_must_eat;
	int *fork_list;
	int *next_to;
	struct timeval stamp;
	pthread_mutex_t pick_up;
	pthread_mutex_t pick_up_all;
	pthread_mutex_t put_down;
	pthread_mutex_t change_left;
	pthread_mutex_t change_right;
	int thread_id;
}			t_rules;

typedef struct s_philo
{
	int philo_id;
	int count_eat;
	int left;
	int right;
	int right_hand;
	int left_hand;
}			t_philo;

t_rules rules;
int		philo_died;

//error
void	print_error(char *str);
void	free_print_error(char *str, void *arg);

//utils
int		space_check(char b);
int		ft_atoi(const char *str);
int		isnum(char c);
int		ft_strlen(char const *str);

//life
void	*start_life(void *philo_arg);
void	make_thread();
void	set_life_rules(int argc, char const *argv[]);
void	lifes(int argc, char const *argv[]);

//life_loop
void	life_loop(t_philo philo);

//log
void	log_fork(struct timeval fork, int philo_num);
void	log_eating(struct timeval eat, int philo_num);
void	log_sleeping(struct timeval sleep, int philo_num);
void	log_thinking(struct timeval think, int philo_num);
void	log_died(struct timeval died, int philo_num);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:37:26 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/08 22:37:44 by hyospark         ###   ########.fr       */
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
	struct timeval stemp;
	pthread_mutex_t lock;
	int *ready_q;
}			t_rules;

typedef struct s_philo
{
	int philo_id;
	int count_eat;
	int left;
	int right;
}			t_philo;

t_rules rules;

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
void	life_loop(t_philo *philo);

//log
void	log_fork(int time, int philo_num);
void	log_eating(int time, int philo_num);
void	log_sleeping(int time, int philo_num);
void	log_thinking(int time, int philo_num);
void	log_died(int time, int philo_num);

#endif

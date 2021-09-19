/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:37:26 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/17 19:34:00 by hyospark         ###   ########.fr       */
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
	struct timeval stamp;
	pthread_mutex_t pick_up_all;
	pthread_mutex_t pick_up_left;
	pthread_mutex_t pick_up_right;
	pthread_mutex_t put_down;
	pthread_mutex_t print_log;
	pthread_mutex_t counting_eat;
	int thread_id;
	int full_philos;
	int philo_died;
}			t_rules;

typedef struct s_philo
{
	int id;
	int count_eat;
	int left;
	int right;
	int right_hand;
	int left_hand;
	t_rules *rules;
	struct timeval	starv;
	struct timeval	last_eat;
}			t_philo;

//error
void	print_error(char *str);
void	free_print_error(char *str, void *arg);

//utils
int		space_check(char b);
int		ft_atoi(const char *str);
int		isnum(char *str, int i);
int		ft_strlen(char const *str);

//life
int		init_mutex(t_rules *rules);
int		mutex_destroy_all(t_rules *rules);
int		set_rules(int argc, char const *argv[], t_rules *rules);
void	lifes(int argc, char const *argv[]);

//check_starved
int	check_starv_eat(long comp, t_philo *philo);
int	check_starv_sleep(struct timeval begin, struct timeval end, t_philo *ph);

//life_loop
int			make_thread(t_rules *rules);
t_philo		set_philos(t_rules *rules, int i);
void		*life_loop(void *philo);

//life_loop_count
int		make_limit_thread(t_rules *rules);
void	*start_life_count(void *i);
void	*life_loop_count(void *philos);

//log
void	log_fork(t_philo *philo, struct timeval fork);
void	log_eating(t_philo *philo, struct timeval eat);
void	log_sleeping(t_philo *philo, struct timeval sleep);
void	log_thinking(t_philo *philo, struct timeval think);
void	log_died(t_philo *philo, struct timeval died);

//action
void			preempt(t_philo *philo);
struct timeval	eating(t_philo *philo, struct timeval last_eat);
int				sleeping(t_philo *philo, struct timeval last_eat);
void			thinking(t_philo *philo);

//cal
long	cal_micro(struct timeval now, struct timeval std);
long	cal_milli(struct timeval now, struct timeval std);

//mutex_fork
void	pick_up(t_philo *philo);
void	pick_up_all(t_philo *philo);
void	pick_up_right(t_philo *philo);
void	pick_up_left(t_philo *philo);
void	put_down(t_philo *philo);

void	clean_all(void);

#endif

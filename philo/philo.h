/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:37:26 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/12 19:51:14 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_rules
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	struct timeval	stamp;
	pthread_mutex_t	*fork_list;
	pthread_mutex_t	print_log;
	pthread_mutex_t	counting_eat;
	pthread_mutex_t	count_over;
	int				full_philos;
	int				philo_died;
	int				philo_over;
}			t_rules;

typedef struct s_philo
{
	int				id;
	int				count_eat;
	int				left;
	int				right;
	t_rules			*rules;
	struct timeval	last_eat;
}				t_philo;

void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
long long		cal_micro(struct timeval now, struct timeval std);
int				check_starv_eat(t_philo *philo);
int				check_starv_sleep(struct timeval starv, t_philo *ph);
void			count_eat(t_philo *philo);
void			*life_loop(void *philo);
t_philo			set_philos(t_rules *rules, int i);
int				make_thread(t_rules *rules);
struct timeval	log_print(t_philo *philo, char *msg);
void			log_died(t_philo *philo);
void			print_error(char *str);
void			pick_up(t_philo *philo);
void			put_down(t_philo *philo);
int				isnum(char *str, int i);
int				ft_strlen(char const *str);
int				space_check(char b);
int				ft_atoi(const char *str);
void			clean_all(t_rules *rules);
int				set_rules(int argc, char const *argv[], t_rules *rules);
void			lifes(int argc, char const *argv[]);
int				init_mutex(t_rules *rules);
int				mutex_destroy_all(t_rules *rules);
int				mutex_unlock_all(t_rules *rules);

#endif

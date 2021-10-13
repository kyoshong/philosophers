/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:37:26 by hyospark          #+#    #+#             */
/*   Updated: 2021/10/14 03:39:36 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <unistd.h>
# include <sys/wait.h>
# include <memory.h>
# include <signal.h>

typedef struct s_rules
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	struct timeval	stamp;
	sem_t			*print_log;
	sem_t			*bch_forks;
	sem_t			*cunt_eat;
	int				full_philos;
	int				philo_died;
	int				*philo_pid;
}			t_rules;

typedef struct s_philo
{
	int				id;
	int				count_eat;
	t_rules			*rules;
	struct timeval	last_eat;
	pthread_t		s_thread;
}				t_philo;

void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
long			cal_micro(struct timeval now, struct timeval std);
int				check_starv_eat(t_philo *ph);
int				check_starv_sleep(struct timeval starv, t_philo *ph);
t_philo			set_philos(t_rules *rules, int i);
struct timeval	log_print(t_philo *philo, char *msg);
void			log_died(t_philo *philo);
void			print_error(char *str);
void			free_print_error(char *str, void *arg);
void			up(t_philo *philo);
int				isnum(char *str, int i);
int				ft_strlen(char const *str);
int				space_check(char b);
int				ft_atoi(const char *str);
void			clean_all(t_rules *rules);
int				set_rules(int argc, char const *argv[], t_rules *rules);
void			lifes(int argc, char const *argv[]);
int				open_sema(t_rules *rules);
void			close_sema_all(t_rules *rules);
void			unlink_sema_all(void);
void			*life_loop(void *philos);
int				make_thread(t_rules *rules);
void			*count_eat_sema(void *rule);
void			*check_starv_thread(void *philos);

#endif

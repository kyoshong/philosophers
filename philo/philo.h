/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:37:26 by hyospark          #+#    #+#             */
/*   Updated: 2021/09/06 21:05:53 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo
{
	int	num_philosophers;
	int time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_must_eat;
}			t_philo;

//error
void	print_error(char *str);

//utils
int		space_check(char b);
int		ft_atoi(const char *str);
int		isnum(char c);
int		ft_strlen(char const *str);

//life
void	starting_lifes(t_philo *rules);
void	set_life_rules(int argc, char const *argv[], t_philo *rules);
void	lifes(int argc, char const *argv[]);

//pickup
void	pickup();


//log
void	log_fork(int time, int philo_num);
void	log_eating(int time, int philo_num);
void	log_sleeping(int time, int philo_num);
void	log_thinking(int time, int philo_num);
void	log_died(int time, int philo_num);

#endif

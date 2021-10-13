# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 00:20:00 by hyospark          #+#    #+#              #
#    Updated: 2021/10/14 01:11:59 by hyospark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Wextra -Werror
SOURCE = philo.c \
		set_life.c \
		log.c \
		utils.c \
		life_loop.c \
		action.c \
		mutex.c
LIB = -lpthread
OUT = philo
OBJECT = $(SOURCE:.c=.o)
B_SOURCE = bonus/philo_bonus.c \
		bonus/set_life_bonus.c \
		bonus/log_bonus.c \
		bonus/utils_bonus.c \
		bonus/life_loop_bonus.c \
		bonus/sema_bonus.c \
		bonus/action_bonus.c \
		bonus/check_starved_bonus.c
B_OBJECT = $(B_SOURCE:.c=.o)
B_OUT = philo_bonus

.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}
$(NAME): $(OBJECT)
	gcc ${FLAGS} $(LIB) $(OBJECT) -o $(OUT)
all : $(NAME)
bonus : $(B_OBJECT)
	gcc ${FLAGS} $(LIB) $(B_OBJECT) -o $(B_OUT)
clean:
	@rm -f $(OBJECT)
	@rm -f $(B_OBJECT)
fclean: clean
	@rm -f $(OUT)
	@rm -f $(B_OUT)
re:	fclean all

.PHONY: all clean fclean re bonus

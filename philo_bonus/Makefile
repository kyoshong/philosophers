# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 00:20:00 by hyospark          #+#    #+#              #
#    Updated: 2021/10/14 19:12:43 by hyospark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
FLAGS = -Wall -Wextra -Werror
SOURCE = philo_bonus.c \
		set_life_bonus.c \
		log_bonus.c \
		utils_bonus.c \
		life_loop_bonus.c \
		sema_bonus.c \
		action_bonus.c
LIB = -lpthread
OUT = philo_bonus
OBJECT = $(SOURCE:.c=.o)

.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}
$(NAME): $(OBJECT)
	gcc ${FLAGS} $(LIB) $(OBJECT) -o $(OUT)
all : $(NAME)
clean:
	@rm -f $(OBJECT)
	@rm -f $(B_OBJECT)
fclean: clean
	@rm -f $(OUT)
	@rm -f $(B_OUT)
re:	fclean all

.PHONY: all clean fclean re

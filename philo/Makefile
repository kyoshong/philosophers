# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 00:20:00 by hyospark          #+#    #+#              #
#    Updated: 2021/10/14 19:15:32 by hyospark         ###   ########.fr        #
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

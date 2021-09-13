# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 00:20:00 by hyospark          #+#    #+#              #
#    Updated: 2021/09/13 17:46:10 by hyospark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Wextra -Werror
SOURCE = philo.c \
		error.c \
		life.c \
		log.c \
		utils.c \
		life_loop.c \
		mutex_fork.c \
		action.c \

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
fclean: clean
	@rm -f $(NAME)
	@rm -f $(OUT)
re:	fclean all

.PHONY: all clean fclean re

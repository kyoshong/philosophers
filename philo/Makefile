# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 00:20:00 by hyospark          #+#    #+#              #
#    Updated: 2021/08/18 02:06:15 by hyospark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo.a
FLAGS = -Wall -Wextra -Werror 
SOURCE = philo.c \
		error.c \
		life.c \
		log.c \
		utils.c \

LIB = -lpthread
OUT = philo
OBJECT = $(SOURCE:.c=.o)

.c:
	gcc -c ${FLAGS} $<
	
$(NAME): $(OBJECT)
	gcc $(CFLAGS) $(LIB) $(OBJECT) -o $(OUT)

all : $(NAME)
clean:
	@rm -f $(OBJECT)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(OUT)
re:	fclean all

.PHONY: all clean fclean re

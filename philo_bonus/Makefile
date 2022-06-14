# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 05:39:12 by ahakam            #+#    #+#              #
#    Updated: 2022/06/13 04:49:54 by ahakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo_bonus

CC=gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize==address -g

OBJ=ft_atoi.c\
	philo.c\
	ft_strcmp.c\
	pars.c\
	philo_utils.c\
	routine.c\
	print.c
	
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	
re: fclean all

clean:
	rm -f $(NAME)
	
fclean:clean
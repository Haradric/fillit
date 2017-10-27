#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 14:48:16 by mbraslav          #+#    #+#              #
#    Updated: 2017/01/12 14:48:22 by mbraslav         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fillit
OBJ =	main.o\
		additional_functions.o\
		str_to_lst.o\
		add_coords.o\
		solve.o\
		print_and_free.o\
		ft_functions.o\
		ft_functions2.o\
		string_checker.o\
		place_figure.o\

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 13:37:05 by dlongfel          #+#    #+#              #
#    Updated: 2020/02/02 13:37:06 by dlongfel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./src/main.c ./src/validation.c ./src/checkout.c  \
	./src/brute_force.c ./src/create_list.c ./src/map.c \
	./src/offset.c ./libft/ft_memalloc.c ./libft/ft_memset.c \
	./libft/ft_putstr.c ./libft/ft_bzero.c

OBJ		= $(SRC:.c=.o)

INCLUDE = ./includes

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(INCLUDE)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

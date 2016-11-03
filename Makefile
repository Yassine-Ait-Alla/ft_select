# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/30 01:29:56 by yaitalla          #+#    #+#              #
#    Updated: 2015/08/06 13:45:02 by yaitalla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_select
CFLAGS=-Werror -Wextra -Wall -Ilibft/includes
LFLAGS=-Llibft -lft
SRC= main.c lst.c file.c key.c display.c file2.c file3.c
OBJ=$(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(LFLAGS) -ltermcap

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)

lib:
	make -C libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 01:38:18 by flcristi          #+#    #+#              #
#    Updated: 2022/11/12 00:13:55 by flcristi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ft_printf.c ft_printf_numbers.c ft_printf_char.c

OBJ		= ${SRC:%.c=%.o}

CFLAGS	= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJ}

%.o: %.c
	cc $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -f ${OBJ}

fclean:
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
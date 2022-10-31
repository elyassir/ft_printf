# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 09:57:10 by yel-mass          #+#    #+#              #
#    Updated: 2022/10/31 10:01:58 by yel-mass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_puchar.c ft_putstr.c ft_puthexa.c ft_putnbr.c ft_putptr.c ft_putunint.c
OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

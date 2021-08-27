# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 14:28:44 by vduriez           #+#    #+#              #
#    Updated: 2021/08/25 15:05:22 by vduriez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS =	ft_printf.c				\
		SRCS/ft_atoi.c			\
		SRCS/ft_checkflagwidth.c\
		SRCS/ft_chkflg.c		\
		SRCS/ft_flagapp.c		\
		SRCS/ft_getlength.c		\
		SRCS/ft_lecture.c		\
		SRCS/ft_precision.c		\
		SRCS/ft_size.c			\
		SRCS/ft_skip.c			\
    	SRCS/ft_strdup.c		\
    	SRCS/ft_strncpy.c		\
    	SRCS/ft_strlen.c		\
		SRCS/ft_treat_char.c	\
		SRCS/ft_treat_double.c	\
		SRCS/ft_treat_hexa.c	\
		SRCS/ft_treat_percent.c	\
		SRCS/ft_treat_uint.c	\
		SRCS/ft_treat_pointer.c	\
		SRCS/ft_treat_string.c	\

OBJ = $(SRCS:.c=.o)

INCLUDES = -I/INCLUDES/ft_printf.h

all: $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)
		rm -rf $(SUPP)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY : clean fclean re

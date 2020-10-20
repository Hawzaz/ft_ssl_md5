# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 14:16:22 by bmellon           #+#    #+#              #
#    Updated: 2020/08/12 15:51:16 by bmellon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

NAME	=	libftprintf.a

SRC		=	printf/ft_print.c printf/printer.c printf/handler.c \
			printf/parser.c printf/handler_csp.c printf/handle_flags.c \
			printf/parser_flags.c printf/act_flags.c printf/fcts.c \
			printf/new_fcts.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-std=c99 -Wall -Werror -Wextra -pedantic -pedantic-errors

LIB		=	libft/libft.a

INC		=	include/

all		:	$(NAME)

%.o:%.c 	$(INC)libftprintf.h
			$(CC) -o $@ $(CFLAGS) -I $(INC) -c $<

$(NAME)	:	$(LIB) $(OBJ)
			cp libft/libft.a ./$(NAME)
			ar rc $(NAME) $(OBJ)
			echo $(NAME) compiled !

$(LIB)	:	FORCE
			make -j -C libft/

FORCE	:

clean	:
			make -C libft/ clean
			rm -rf $(OBJ)

fclean	:	clean
			make -C libft/ fclean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all, clean, fclean, re

.SILENT:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 14:55:17 by bmellon           #+#    #+#              #
#    Updated: 2020/10/25 14:05:44 by bmellon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ssl

CC		=	gcc

SRC		=	main.c parsing.c

OBJ		=	$(SRC:.c=.o)

FLAG	=	-Wall -Wextra -Werror

F		=	-fsanitize=address

all		:	precomp $(NAME)

precomp	:
			@make -C libft/

$(NAME)	:	$(OBJ)
			@cp libft/libftprintf.a ./$(NAME)
			@gcc -o $@ $^ -Llibft/ -lftprintf
			@echo $(NAME) compiled !

%.o: 		%.c
			@gcc $(FLAG) -o $@ -c $<

clean	:
			@make -C libft/ clean
			@/bin/rm -f $(OBJ)

fclean	:	clean
			@make -C libft/ fclean
			@rm -f $(NAME)

re		:	fclean all

.PHONY: fclean all clean re

.PRECIOUS: $@
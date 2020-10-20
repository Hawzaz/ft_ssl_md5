# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 14:16:22 by bmellon           #+#    #+#              #
#    Updated: 2019/08/23 22:10:29 by bmellon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		= gcc

SRC		=	ft_bzero.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_strcat.c ft_strcpy.c ft_strdup.c \
			ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncpy.c ft_strchr.c \
			ft_strrchr.c ft_strstr.c ft_atoi.c ft_strnstr.c ft_strcmp.c \
			ft_strncmp.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isnum.c \
			ft_isprint.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_striter.c \
			ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striteri.c \
			ft_strmap.c ft_putchar.c  ft_putstr.c ft_putendl.c ft_putnbr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_itoa.c ft_strequ.c ft_strjoin.c ft_strsub.c ft_strtrim.c \
			ft_strmapi.c ft_strnequ.c ft_splitc.c ft_lstnew.c ft_lstadd.c \
			ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
			ft_revstr.c ft_lstaddback.c ft_lstlen.c ft_revsplit.c ft_split.c \
			ft_putsplit.c ft_occuc.c ft_stritertab.c ft_lstnew2.c ft_swapc.c \
			ft_putnbrendl.c reverse_tab.c get_next_line.c streplace.c \
			ft_stristr.c ft_strcstr.c ft_strcpyn.c ft_strdupn.c ft_strndup.c \
			ft_tabdup.c get_tab_size.c handle_free.c ft_copyuntil.c \
			get_next_line_old.c ft_stralnum.c handle_free_ext.c ft_putlong.c \
			ft_putlonglong.c ft_putnbr_max.c ft_nbrlen.c ft_itoa_base.c \
			ft_putnbr_base.c

OBJ		=	$(SRC:.c=.o)

FLAG	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@ar rsc $(NAME) $(OBJ)
	@echo $(NAME) compiled !

%.o:%.c
	@gcc $(FLAG) -o $@ -c $^ -I includes
clean	:
			@rm -f $(OBJ)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all

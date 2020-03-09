# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malavent <malavent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:01:01 by achoquel          #+#    #+#              #
#    Updated: 2019/06/12 10:38:59 by malavent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	:	all clean fclean re

NAME	=	wolf3d

SRCS	=		srcs/menu.c	\
				srcs/utils.c	\
				srcs/loaders.c	\
				srcs/weapons.c  \
				srcs/main.c  \
				srcs/checker.c \
				srcs/parser.c  

OBJS	= 	$(SRCS:.c=.o)

PWD		=	$(shell pwd)

CC		=	@gcc

##CFLAGS	+=	-Wall -Wextra -Werror

LIB		=	-L./srcs/libft/ -lft

INC		= 	-I $(FWDIR)

FWDIR	=	$(PWD)/frameworks

FW		=	-F $(FWDIR) -framework SDL2

RM		=	@/bin/rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@make  -C srcs/libft/
			$(CC) -o $(NAME) $(OBJS) $(LIB) $(FW)
			@echo "\033[32m[✓] wolf3d compiled !\033[0m"

clean	:
			@make -C srcs/libft/ clean
			$(RM) $(OBJS)
			@echo "\033[32m[✓] objects cleaned !\033[0m"

fclean	:	clean
			$(RM) $(NAME)
			$(RM) srcs/libft/libft.a
			@echo "\033[32m[✓] objects, libraries and binaries cleaned !\033[0m"

re		:	fclean all

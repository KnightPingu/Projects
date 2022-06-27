# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 10:46:39 by dpeyrat           #+#    #+#              #
#    Updated: 2021/12/23 10:55:04 by dpeyrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c init.c thread.c utils.c

OBJS	= ${SRCS:.c=.o}

NAME	= philo

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

$(NAME):	${OBJS}	
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:			fclean all

.PHONY:		re clean fclean all

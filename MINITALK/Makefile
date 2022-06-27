# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 13:24:27 by dpeyrat           #+#    #+#              #
#    Updated: 2021/10/11 14:46:17 by dpeyrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CLIENT	= client.c

SERVER	= server.c

NAMEC	= client

NAMES	= server

PRINTF	= ft_printf/libftprintf.a 

OBJSC	= ${CLIENT:.c=.o}

OBJSS	= ${SERVER:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	${NAMEC} ${NAMES}

${NAMEC}:	${OBJSC} ${PRINTF}
		${CC} ${CFLAGS} -o ${NAMEC} ${OBJSC} ${PRINTF}

${NAMES}:	${OBJSS} ${PRINTF}
		${CC} ${CFLAGS} -o ${NAMES} ${OBJSS} ${PRINTF}

${PRINTF}:
		cd ft_printf && make

clean:
		rm -f ${OBJSS} ${OBJSC}
		cd ft_printf && make clean

fclean:		clean
		rm -f ${NAMEC} ${NAMES}
		cd ft_printf && make fclean

re:			fclean all

.PHONY:	re clean fclean all printf

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 15:07:07 by dpeyrat           #+#    #+#              #
#    Updated: 2021/08/30 14:05:16 by dpeyrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF		= ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_printf_utils3.c

INT			= INT/ft_integers.c INT/ft_int.c

CHAR		= CHAR/ft_char.c CHAR/ft_string.c CHAR/ft_displaystring.c CHAR/ft_nonvar_char.c

UNSIGNED	= UNSIGNED/ft_uint.c UNSIGNED/ft_unsigned.c UNSIGNED/ft_address.c UNSIGNED/ft_hex.c

SRCS	= ${PRINTF} ${INT} ${CHAR} ${UNSIGNED}

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: 	${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
	@echo "Compiling .c files"
	@ar rc ${NAME} ${OBJS}
	ranlib ${NAME}
clean:
	@echo "Deleting .o files"
	@rm -f ${OBJS}
fclean: clean
	@echo "Deleting ${NAME} file"
	@rm -f ${NAME}
re:		fclean all

.PHONY:	re clean fclean all


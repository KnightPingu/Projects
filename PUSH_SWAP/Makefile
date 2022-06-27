# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 14:31:54 by dpeyrat           #+#    #+#              #
#    Updated: 2021/11/06 16:29:19 by dpeyrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPER		= OPER/push_ft.c OPER/reverse_ft.c OPER/rotate_ft.c OPER/swap_ft.c

START		= INIT/error_check_utils.c INIT/error_check.c INIT/init.c INIT/parse.c

SORT		= SORT/sort.c SORT/finish_sort.c SORT/sort_small.c

SRCS	= ${OPER} ${START} ${SORT} 

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

LIBFT	= libft/libft.a

all: 	${NAME}

${NAME}:	${OBJS} ${LIBFT}
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIBFT}:
			@cd libft && make
clean:
	@rm -f ${OBJS}
	@cd libft && make clean
fclean: clean
	@rm -f ${NAME}
	@cd libft && make fclean
re:		fclean all

.PHONY:	re clean fclean all


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 12:36:28 by dpeyrat           #+#    #+#              #
#    Updated: 2020/11/30 08:51:39 by dpeyrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

BASIC_OBJS	= ${BASIC:.c=.o}

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

BASIC	= ${filter-out ${BONUS}, ${SRCS}}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${BASIC_OBJS}
	@echo "Compiling .c files"
	@ar rc ${NAME} ${BASIC_OBJS}
	ranlib ${NAME}

clean:
		@echo "Deleting .o files"
		@rm -f ${OBJS}

fclean:		clean
		@echo "Deleting libft.a file"
		@rm -f ${NAME}

re:			fclean all

bonus:		 ${OBJS}
	@echo "Compiling .c files"
	@ar cr ${NAME} ${OBJS}
	ranlib ${NAME}

bonusre:	fclean bonus

.PHONY:		re clean fclean all bonus bonusre

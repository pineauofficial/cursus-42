# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pineau <pineau@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 22:46:23 by pineau            #+#    #+#              #
#    Updated: 2022/11/29 15:39:09 by pineau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = -I ./

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}

AR = ar rcs

SRCS = ft_printf.c\
	ft_putchar.c\
	ft_putnbr_p.c\
	ft_putnbr_u.c\
	ft_putnbr_base.c\
	ft_putstr.c\
	ft_putnbr_x.c\
	
${NAME} : ${OBJS}
		$(AR) ${NAME} ${OBJS}

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY: re clean fclean all

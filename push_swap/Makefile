# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pineau <pineau@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 12:18:17 by pineau            #+#    #+#              #
#    Updated: 2022/12/14 20:51:27 by pineau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = -I ./

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME = push_swap.a

OBJS = ${SRCS:.c=.o}

AR = ar rcs

SRCS = push_swap.c\
	swapers_part_one.c\
	swapers_part_two.c\
	swapers_part_three.c\
	check.c\
	
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
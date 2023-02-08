# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pineau <pineau@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 12:18:17 by pineau            #+#    #+#              #
#    Updated: 2023/02/07 18:01:58 by pineau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = -I ./

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME = push_swap

OBJS = ${SRCS:.c=.o}

SRCS = push_swap.c\
	swapers_part_one.c\
	swapers_part_two.c\
	swapers_part_three.c\
	check.c\
	algo.c\
	count.c\
	get_things.c\
	tableau.c\
	sort_algo.c\
	check_part2.c\
	
	
${NAME} : ${OBJS}
		$(CC) ${CFLAGS} ${OBJS} -o ${NAME}

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY: re clean fclean all
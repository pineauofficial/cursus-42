# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pineau <pineau@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 12:27:17 by pineau            #+#    #+#              #
#    Updated: 2023/05/10 14:57:04 by pineau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

BONUS_NAME = pipex_bonus

CC	= gcc

CFLAGS	= -Werror -Wextra -Wall -g3

INC	= -I ./include/

SRC_PATH	= ./srcs/

SRC	= \
		main.c\
		utils.c\
		utils2.c\
		path.c\
		utils3.c\
		

BONUS_SRC_PATH = ./srcs_bonus/

BONUS_SRC = \
		main_bonus.c\
		utils_bonus.c\
		utils2_bonus.c\
		path_bonus.c\
		get_next_line.c\
		get_next_line_utils.c\
		here_doc.c\
		
	
SRCS        = $(addprefix $(SRC_PATH), $(SRC))
OBJ_PATH    = obj/
OBJ        = $(SRC:.c=.o)
OBJS        = $(addprefix $(OBJ_PATH), $(OBJ))

BONUS_SRCS = $(addprefix $(BONUS_SRC_PATH), $(BONUS_SRC))
BONUS_OBJ_PATH = bonus_obj/
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_OBJS = $(addprefix $(BONUS_OBJ_PATH), $(BONUS_OBJ))

$(NAME): $(OBJ_PATH) $(OBJS)
	@echo "Compiling pipex..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC)
	@echo "Pipex ready."

all: $(NAME) $(BONUS_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(BONUS_NAME): $(BONUS_OBJ_PATH) $(BONUS_OBJS)
	@echo "Compiling pipex bonus..."
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(INC)
	@echo "Pipex bonus ready."

bonus: $(BONUS_NAME)

$(BONUS_OBJ_PATH)%.o: $(BONUS_SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(BONUS_OBJ_PATH):
	@mkdir $(BONUS_OBJ_PATH)
	
clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH) $(BONUS_OBJ_PATH)


fclean: clean
	@echo "Removing pipex..."
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus re clean fclean

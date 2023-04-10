# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pineau <pineau@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 17:00:47 by pineau            #+#    #+#              #
#    Updated: 2023/04/09 17:01:45 by pineau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol
BONUS_NAME = fractol_bonus

# Compiler
CC        = gcc
CFLAGS    = -Werror -Wextra -Wall -g3 

# Minilibx
MLX_PATH    = ./mlx_linux/
MLX_NAME    = libmlx.a
MLX        = $(MLX_PATH)$(MLX_NAME)

# Includes
INC        =    -I ./include/\
                -I $(MLX_PATH)

# Sources
SRC_PATH    =./srcs/
SRC        =	\
				check.c\
				main.c\
				image.c\
				event.c\
				fractal.c\
				colors.c\
				zoom.c\
				arrows.c\
				check_numbers.c\
				utils.c\

BONUS_SRC_PATH = ./bonus_srcs/
BONUS_SRC    =	\
				check_bonus.c\
				main_bonus.c\
				image_bonus.c\
				event_bonus.c\
				fractal_bonus.c\
				colors_bonus.c\
				zoom_bonus.c\
				arrows_bonus.c\
				check_numbers_bonus.c\
				utils_bonus.c\
								
SRCS        = $(addprefix $(SRC_PATH), $(SRC))
OBJ_PATH    = obj/
OBJ        = $(SRC:.c=.o)
OBJS        = $(addprefix $(OBJ_PATH), $(OBJ))

BONUS_SRCS = $(addprefix $(BONUS_SRC_PATH), $(BONUS_SRC))
BONUS_OBJ_PATH = bonus_obj/
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_OBJS = $(addprefix $(BONUS_OBJ_PATH), $(BONUS_OBJ))

$(NAME): $(MLX) $(OBJ_PATH) $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(INC) -lXext -lX11 -lm
	@echo "Fractol ready."

all: $(NAME) $(BONUS_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	
$(BONUS_OBJ_PATH):
	@mkdir $(BONUS_OBJ_PATH)
	
$(BONUS_OBJ_PATH)%.o: $(BONUS_SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)


$(BONUS_NAME): ${MLX} $(BONUS_OBJ_PATH) $(BONUS_OBJS)
	@echo "Compiling fractol bonus..."
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(MLX) $(INC) -lXext -lX11 -lm -Lmlx
	@echo "Fractol bonus ready."

bonus: $(BONUS_NAME)

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH) $(BONUS_OBJ_PATH)
	@make clean -C $(MLX_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus re clean fclean

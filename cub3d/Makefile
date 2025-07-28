# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 14:05:33 by nakoriko          #+#    #+#              #
#    Updated: 2025/07/17 11:36:39 by nakoriko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
#cancellato -O3, perche mi dava errori di compilazione di write
CFLAGS = -Wall -Wextra -Werror 

MLX_FLAGS = -lmlx -Lmlx -Lmlx -lXext -lX11 -lm -lbsd

INCLUDES = -I$(HEADER_DIR) -I$(MLX_DIR) -Ilibft -Iprintf

HEADER_DIR = include/
HEADERS = cub3d.h

# per caso se non funziona - provare ad eliminare MLX_DIR dal includes sotto
# INCLUDES = -I$(HEADER_DIR) -I$(MLX_DIR) -Imlx
# INCLUDES = -I$(HEADER_DIR)  -Imlx

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

SRC_MAIN = \
	main.c

SRC_ENGINE = \
	engine/raycasting.c \
	engine/redraw_render.c

SRC_EVENTS = \
	events/hooks.c \
	events/movements_arrow.c \
	events/movements_asdw.c

SRC_INIT = \
	init/init_game.c \
	init/init_player.c \
	init/init_textures.c

SRC_PARSER = \
	parser/map_validation.c \
	parser/parser_main.c \
	parser/parser_map.c \
	parser/parser_texture_line.c \
	parser/unclosed_map_check.c

SRC_UTILS = \
	utils/errors.c \
	utils/free_all.c \
	utils/utils_raycasting.c \
	utils/utils_redraw_render.c \
	utils/utils.c

SRCDIR = $(addprefix sources/,  $(SRC_MAIN) $(SRC_ENGINE) $(SRC_EVENTS) $(SRC_INIT) $(SRC_PARSER) $(SRC_UTILS))
OBJ = $(SRCDIR:.c=.o)

LIBFT_DIR = libft
PRINTF = $(LIBFT_DIR)/ft_printf/libftft_printf.a
LIBFT = $(LIBFT_DIR)/libft.a

# LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# forse manipolazioni con mlx non servono
all: $(LIBFT) $(MLX) $(NAME)

# per caso di errori, provasre ad eliminare CFLAGS giu
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(MLX_FLAGS)


%.o:%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)
	cd $(MLX_DIR) && make

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) clean -C $(MLX_DIR); fi
	rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY:  all clean fclean re libft

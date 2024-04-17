NAME = cub3d

CC = cc

FLAGS = -Wall -Wextra -g -Werror -MMD -MP #-fsanitize=address

LFLAGS	= -L$(MLX_DIR) -L$(LIBFT_DIR)

LINKS	= -lft -lmlx -lXext -lX11 -lm

INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(INCL_DIR) 

MLX_DIR = minilibx
MLX		= $(MLX_DIR)/libmlx.a

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCL_DIR	= incl

SRC = main.c\
	window.c\
	read_map.c\
	parsing_textures.c\
	valid_map.c\
	check_path.c\
	colours.c\
	free.c\
	utils.c\
	calculate.c\
	move.c\
	init_pers.c\
	key.c \
	import_texture.c \
	tools.c \
	draw_texture.c \

OBJ = $(addprefix bin/, $(SRC:.c=.o))
DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
		$(CC) $(FLAGS) $(LFLAGS) $(OBJ) $(LINKS) -o $(NAME)

-include	$(DEPS)

bin/%.o :src/%.c
	@mkdir -p $(dir $@)
	$(CC) -O3 -c $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
		rm -rf bin
		$(MAKE) fclean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX_DIR)

fclean: clean
		rm -f libft.a $(NAME)

re: fclean all

.PHONY: all clean fclean re



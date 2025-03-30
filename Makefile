NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Use brew's path to glfw
GLFW_PATH = /goinfre/moel-idr/homebrew/Cellar/glfw/3.4
LDFLAGS = -Lincludes/libft -lft -Lincludes/MLX42/build -lmlx42 -L$(GLFW_PATH)/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit

# Source files
SRC_DIR = .
SRC = julia/julia.c mandlebrot/mandle_brot.c parce/parce.c utils/keys.c utils/utils.c utils/keys_help.c main.c burningship/burning_ship.c
OBJ = $(SRC:.c=.o)

# Library paths
LIBFT_DIR = includes/libft
MLX_DIR = includes/MLX42

all: $(NAME)

$(NAME): $(OBJ) includes.h
	$(MAKE) -C $(LIBFT_DIR)
	@if [ ! -d "$(MLX_DIR)/build" ]; then \
		mkdir -p $(MLX_DIR)/build; \
		cmake -S $(MLX_DIR) -B $(MLX_DIR)/build; \
		cmake --build $(MLX_DIR)/build; \
	fi
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)/include -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)/build" ]; then \
		$(MAKE) -C $(MLX_DIR)/build clean; \
	fi

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@if [ -d "$(MLX_DIR)/build" ]; then \
		rm -rf $(MLX_DIR)/build; \
	fi

re: fclean all

.PHONY: all clean fclean re
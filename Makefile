NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror

GLFW_PATH = /goinfre/moel-idr/homebrew/Cellar/glfw/3.4

LDFLAGS = -Lincludes/libft -lft \
          -Lincludes/MLX42/build -lmlx42 \
          -L$(GLFW_PATH)/lib -lglfw \
          -framework Cocoa -framework OpenGL -framework IOKit

SRC_DIR = mandetory/
SRC = $(SRC_DIR)julia/julia.c \
	   $(SRC_DIR)mandlebrot/mandle_brot.c \
	   $(SRC_DIR)parce/parce.c \
	   $(SRC_DIR)utils/keys.c \
	   $(SRC_DIR)utils/utils.c \
	   $(SRC_DIR)utils/keys_help.c \
	   $(SRC_DIR)main.c
OBJ = $(SRC:.c=.o)

BON_DIR = Bonus/
BON_SRC = $(BON_DIR)burningship_bonus/burning_ship.c \
          $(BON_DIR)julia_bonus/julia_bonus.c \
          $(BON_DIR)mandlebrot_bonus/mandle_brot_bonus.c \
          $(BON_DIR)utils_bonus/keys_bonus.c \
          $(BON_DIR)utils_bonus/keys_help_bonus.c \
          $(BON_DIR)utils_bonus/utils_bonus.c \
          $(BON_DIR)parce_bonus/parce_bonus.c \
          $(BON_DIR)main_bonus.c
BON_OBJ = $(BON_SRC:.c=.o)

LIBFT_DIR = includes/libft
MLX_DIR = includes/MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	@echo "🔧 Building the libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "🔧 Building standard version..."
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@echo "✅ Standard build complete!"

%.o: %.c fractol.h
	@$(CC) $(CFLAGS) -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)/include -c $< -o $@

bonus: $(BON_OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "🔧 Building bonus version..."
	@$(CC) $(CFLAGS) -o $(NAME) $(BON_OBJ) $(LDFLAGS)
	@echo "✅ Bonus build complete!"

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)/build" ]; then \
		echo "🛠️  Building MLX42..."; \
		mkdir -p $(MLX_DIR)/build; \
		cmake -S $(MLX_DIR) -B $(MLX_DIR)/build; \
		cmake --build $(MLX_DIR)/build; \
	fi

$(BON_DIR)%.o: $(BON_DIR)%.c
	@mkdir -p $(@D)  # Ensure output directory exists
	@$(CC) $(CFLAGS) -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)/include -c $< -o $@


clean:
	@rm -f $(OBJ) $(BON_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Cleaned object files."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🧹🔥 Full clean complete."

re: fclean all

.PHONY: all bonus clean fclean re
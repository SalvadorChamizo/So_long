NAME = so_long
NAME_BNS = so_long_bonus
CC = gcc
FLAGS = -g -Wall -Werror -Wextra -Iinclude
GLFW = -lglfw -L"/Users/schamizo/.brew/opt/glfw/lib/"
FRAMEWORK = -framework Cocoa -framework OpenGL -framework IOKit
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = ./MLX42
MLX = $(MLX_PATH)/libmlx42.a

FILES =	so_long \
		free_memory \
		image_handle \
		initialize \
		maps_errors \
		maps_utils \
		movement \
		read_maps \
		so_long_utils \

BNS_FILES = so_long_bns \
			free_memory_bns \
			image_handle_bns \
			initialize_bns \
			maps_errors_bns \
			maps_utils_bns \
			movement_bns \
			read_maps_bns \
			so_long_utils_bns \

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
BNS_SRC_DIR = ./bns/
BNS_SRCS = $(addprefix $(BNS_SRC_DIR), $(addsuffix .c, $(BNS_FILES)))

OBJS_DIR = ./src/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
BNS_OBJ_DIR = ./bns/
BNS_OBJS = $(addprefix $(BNS_OBJ_DIR), $(addsuffix .o, $(BNS_FILES)))

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(FLAGS) $(GLFW) $(FRAMEWORK) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(NAME_BNS): $(LIBFT) $(MLX) $(BNS_OBJS)
	@$(CC) $(FLAGS) $(GLFW) $(FRAMEWORK) $(BNS_OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(MLX):
	make -C $(MLX_PATH) all

all: $(NAME)

bonus: $(NAME_BNS)

clean: 
	rm -f $(OBJS) $(BNS_OBJS)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME) $(NAME_BNS)
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX_PATH) fclean

re: fclean all

.PHONY = all clean fclean re libft
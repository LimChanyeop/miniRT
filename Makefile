NAME = miniRT
MLX_NAME = libmlx.dylib
MLX_PATH = ./lib/minilibx_mms
LIBFT_PATH = ./lib/libft_utils
INCLUDES_PATH = ./includes
SRC_PATH = ./src
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_PATH)
FLAGS = -L$(LIBFT_PATH) -lft_utils -L$(MLX_PATH) -lmlx -L$(SRC_PATH) -lminirt

all : $(NAME)

$(NAME) : libft mlx source ./$(MLX_NAME)
	@gcc main.c $(CFLAGS) $(FLAGS) -o miniRT

clean :
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	make -C $(SRC_PATH) clean

fclean :
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX_PATH) clean
	make -C $(SRC_PATH) fclean
	rm -rf $(NAME)
	rm -rf $(MLX_NAME)
	rm -rf miniRT.bmp

re : fclean all

libft : 
	make -C $(LIBFT_PATH) all

mlx : 
	make -C $(MLX_PATH) all

source : 
	make -C $(SRC_PATH) all

./$(MLX_NAME):
	@cp $(MLX_PATH)/$(MLX_NAME) $(MLX_NAME)

.PHONY : all clean re fclean source libft mlx
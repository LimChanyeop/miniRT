NAME = libminirt

MLX_PATH = ./lib/minilibx_mms_20200219
LIBFT_PATH = ./lib/libft
GET_NEXT_LINE_PATH = ./lib/get_next_line
INCLUDES_PATH = ../includes
SRC_PATH = ./src
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_PATH)
SOURCE =  $(addprefix $(SRC_PATH), $(FILES))

FLAGS = -lmlx -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -L$(GET_NEXT_LINE_PATH) -lgnl
OBJECT = $(SOURCE:.c=.o)
$(NAME): $(OBJECT)
	make -C $(LIBFT_PATH) all
	make -C $(GET_NEXT_LINE_PATH) all
	gcc $(CFLAGS) $(OBJECT) $(FLAGS) -o $(NAME)

$(OBJECT) : $(SOURCE)
	gcc -c $(OBJECT) $(FLAGS)

all : $(NAME)

clean :
	rm -rf $(NAME)
re : clean all

run : all
	./$(NAME)
ppm : all
	./$(NAME) > result.ppm
open : ppm
	open ./result.ppm
.PHONY : all clean re ppm open run

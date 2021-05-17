NAME = libminirt.a

MLX_PATH = ./lib/minilibx_mms_20200219
LIBFT_PATH = ./lib/libft_utils
INCLUDES_PATH = ./includes
SRC_PATH = ./src/
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_PATH)
SOURCE = $(addprefix $(SRC_PATH), *.c)
FLAGS = -L$(LIBFT_PATH) -lft_utils -L. -lmlx
OBJECT = $(SOURCE:.c=.o)
$(NAME): $(OBJECT)
	make -C $(LIBFT_PATH) all
	ar rcs $(NAME) *.o
	
$(OBJECT) : $(SOURCE)
	gcc -c $(SOURCE) $(CFLAGS)

all : $(NAME)

clean :
	rm -rf $(NAME)
re : clean all

gcc : all
	gcc 1_main.c -g -fsanitize=address $(CFLAGS) $(FLAGS) -L. -lminirt 
	rm -rf *.o

run : all
	./$(NAME)
ppm : all
	./$(NAME) > result.ppm
open : ppm
	open ./result.ppm
.PHONY : all clean re ppm open run

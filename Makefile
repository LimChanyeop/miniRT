NAME = libminirt.a

MLX_PATH = ./lib/minilibx_mms

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
	gcc main.c $(CFLAGS) $(FLAGS) -L. -lminirt

clean :
	rm -rf $(NAME)

re : clean all

.PHONY : all clean re

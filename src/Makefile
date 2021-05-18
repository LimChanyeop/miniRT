NAME = libminirt.a
INCLUDES_PATH = ../includes
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_PATH)
SOURCE = camera.c \
			ambients.c \
			hit_object.c \
			canvas.c \
			color.c \
			cylinder.c \
			error_handling.c \
			handle_event.c \
			handle_mlx.c \
			initiation.c \
			input_validation.c \
			input_validation2.c \
			light.c \
			make_bmp.c \
			parse.c \
			parsing_utils.c \
			parsing1.c \
			parsing2.c \
			plane.c \
			ray.c \
			sphere.c \
			square.c \
			triangle.c \
			vec_utils1.c \
			vec_utils2.c \
			vec_utils3.c \
			vec_utils4.c
			
OBJECT = $(SOURCE:.c=.o)
$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)
$(OBJECT) : $(SOURCE)
	gcc -c $(SOURCE) $(CFLAGS)
all : $(NAME)
clean :
	rm -rf $(OBJECT)
fclean : clean
	rm -rf $(NAME)
re : fclean all
.PHONY : all clean fclean re
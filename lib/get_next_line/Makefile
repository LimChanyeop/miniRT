CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libgnl.a
FILES = get_next_line.c

OBJS = $(FILES:%.c=%.o)

all : $(NAME)

$(OBJS) : $(FILES)
	$(CC) $(CFLAGS) $(FILES)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: bonus all clean fclean re


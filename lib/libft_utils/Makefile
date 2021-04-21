CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libft_utils.a
FILES =	ft_atoi.c \
					ft_split_space.c \
					ft_split_comma.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					get_next_line.c \
					get_next_line_utils.c \
					ft_strncmp.c \
					ft_isdigit.c \
					ft_isspace.c \
					ft_iscomma.c \
					ft_atof.c

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

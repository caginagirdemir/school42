NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra

SRCS = main.c \
	  draw.c \
	  draw_utils.c \
	  read_file.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
	gcc -Wall -Wextra -Werror $(SRCS) libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -o fdf

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re 

NAME =  cub3d

CC = gcc
FLAGS = -Wall -Werror -Wextra

SRCS = main.c \
		 first_screen.c \
		 draw_utils.c \
		 utils.c \
		 refresh.c \
		 read_file.c \
		 get_next_line.c \
		 first_screen_utils.c \
		 load_image.c \
		 refresh_utils.c \
		 refresh2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
	gcc -Wall -Wextra -Werror $(SRCS) libft/libft.a ./minilibx_mac/libmlx.a -framework OpenGL -framework AppKit -o cub3d

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re 

SRC = srcs/main.c srcs/handle_nums.c srcs/handle_dict.c srcs/utils.c
OBJS = ${SRC:.c=.o}
INC = includes
GCC = gcc -Wall -Werror -Wextra
NAME = rush-02

all: ${NAME}

%.o: %.c
	${GCC} -c $< -o $@ -I${INC}

${NAME}: ${OBJS}
	${GCC} -o ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:	fclean all clean

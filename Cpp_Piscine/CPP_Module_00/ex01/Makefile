NAME	=	phonebook
SRCS	=	Contact.cpp PhoneBook.cpp main.cpp
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	c++ -o $(NAME) $(SRCS)
%.o: %.c
	c++ -c $< -o $@ $(CFLAGS)
clean:
	rm -rf $(NAME)
re: clean all
.PHONY: all, clean, re

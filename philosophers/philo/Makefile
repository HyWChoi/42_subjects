# CC = Clang
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

srcs = $(shell find . -name "*.c")
OBJS := $(srcs:.c=.o)
NAME = philo

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libs/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

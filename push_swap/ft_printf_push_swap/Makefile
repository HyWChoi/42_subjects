NAME = libftprintf.a
AR = ar rcs
RM = rm -f
SRCS = ft_printf.c char.c int.c ptr.c unsigned_int.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

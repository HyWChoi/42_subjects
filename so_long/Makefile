NAME = so_long
LIBFT = libft/libft.a
RM = rm -f
SRCS = so_long.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) $(LIBFT) libmlx.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -lmlx -c $< -o $@

clean:
	$(RM) $(OBJS) $(CHECKER_OBJS)
fclean: clean
	$(RM) -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus

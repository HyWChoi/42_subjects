NAME = so_long
LIBFT = libft/libft.a
LIBMLX = libmlx.a
RM = rm -f
SRCS = so_long.c so_long_init_map.c so_long_valid_check.c main.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) $(LIBFT) $(LIBMLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(CHECKER_OBJS)
fclean: clean
	$(RM) -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus

NAME = so_long
LIBFT = libft/libft.a
LIBMLX = libmlx.a
RM = rm -f
SRCS = so_long_utils.c so_long_init_map.c so_long_valid_check.c so_long_find_path_BFS_1.c so_long_find_path_BFS_2.c \
		main.c so_long_init_game_graphics.c so_long_set_graphics_1.c so_long_set_graphics_2.c so_long_key_hooks_1.c so_long_key_hooks_2.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
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

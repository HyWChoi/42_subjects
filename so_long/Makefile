NAME = pipex
LIBFT = libft/libft.a
RM = rm -f
SRCS = ft_pipex.c ft_pipex_utils.c ft_pipex_utlis_2.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -lmlx -c $< -o $@

clean:
	$(RM) $(OBJS) $(CHECKER_OBJS)
fclean: clean
	$(RM) -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus

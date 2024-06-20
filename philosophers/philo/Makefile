# CC = Clang
CC = cc
CFLAGS = -Wall -Wextra -Werror

srcs = ph_forks.c ph_eating.c ph_life.c ph_print.c ph_excute_check.c \
		ph_mutex.c ph_clean.c ph_init.c ph_setup.c ph_utils.c ph_thread.c \
		ph_misc.c dbg_philo.c main.c
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

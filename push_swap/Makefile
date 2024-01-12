NAME = push_swap.a
AR = ar rcs
RM = rm -f
SRCS = push_swap_deque_1.c push_swap_command_1.c push_swap_deque_2.c watch_deque.c \
		merge_test.c push_swap_command_2.c push_swap_element_status.c push_swap_checker.c \
		push_swap_command_3.c push_swap_sanity_check.c

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

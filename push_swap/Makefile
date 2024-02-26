NAME = push_swap.a
AR = ar rcs
RM = rm -f
SRCS = push_swap_checker.c push_swap_command_1.c push_swap_command_2.c push_swap_command_3.c \
		push_swap_deque_1.c push_swap_deque_2.c push_swap_devide_1.c push_swap_devide_2.c \
		push_swap_devide_3.c push_swap_element_status_1.c push_swap_element_status_2.c \
		push_swap_calcs.c push_swap_sanity_check.c watch_deque.c push_swap_merge_1.c push_swap_merge_2.c \
		push_swap_merge_3.c push_swap_merge_4.c push_swap_merge_5.c push_swap_merge_6.c push_swap_merge_7.c \
		push_swap_merge_2.5.c push_swap_merge_3.5.c push_swap_merge_4.5.c push_swap_merge_5.5.c

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

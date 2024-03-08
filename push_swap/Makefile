NAME = push_swap
CHECKER = checker
LIBFT = libft/libft.a
AR = ar rcs
RM = rm -f
SRCS = push_swap_command_1.c push_swap_command_2.c push_swap_command_3.c \
		push_swap_deque_1.c push_swap_deque_2.c push_swap_devide_1.c push_swap_devide_2.c \
		push_swap_devide_3.c push_swap_element_status_1.c push_swap_element_status_2.c \
		push_swap_calcs.c push_swap_sanity_check.c watch_deque.c push_swap_merge_1.c push_swap_merge_2.c \
		push_swap_merge_3.c push_swap_merge_4.c push_swap_merge_5.c push_swap_merge_6.c push_swap_merge_7.c \
		push_swap_merge_8.c push_swap_merge_9.c push_swap_merge_10.c push_swap_merge_11.c \
		get_next_line.c get_next_line_utils.c checker_command_1.c checker_command_2.c \
		push_swap_under6_1.c push_swap_under6_2.c push_swap_under6_3.c main.c

OBJS = $(SRCS:.c=.o)

CHECKER_SRCS = $(filter-out main.c, $(SRCS)) checker.c
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(CHECKER_OBJS)
fclean: clean
	$(RM) -f $(NAME) $(CHECKER)

re: fclean all

bonus: $(CHECKER)

$(CHECKER): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER)

.PHONY: all clean fclean re bonus

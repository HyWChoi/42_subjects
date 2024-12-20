CC = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = span
SRCS = main.cpp Span.cpp
OBJS = $(SRCS:.cpp=.o)

# 규칙 정의
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

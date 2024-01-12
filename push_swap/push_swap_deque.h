#ifndef PUSH_SWAP_DEQUE_H
# define PUSH_SWAP_DEQUE_H
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef int boolean;
typedef int element;
typedef struct s_deque
{
    element *data;
    int front;
    int rear;
}	t_deque;

void    init_deque(t_deque *dq, size_t size);
boolean is_empty(t_deque *dq);
boolean is_full(t_deque *dq, size_t size);
void    push_front(t_deque *dq, int num, size_t size);
void    push_rear(t_deque *dq, int num, size_t size);
element    pop_rear(t_deque *dq, size_t size);
element    pop_front(t_deque *dq, size_t size);
void    print_dq(t_deque *dq, size_t size);
int	count_dq(t_deque *dq, size_t size);

#endif

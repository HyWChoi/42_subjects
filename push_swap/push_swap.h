#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# define MAX_SIZE 10
# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef int boolean;
typedef int element;
typedef struct s_deque
{
    element *data;
    int front;
    int rear;
}	t_deque;

void    init_deque(t_deque *dq);
boolean is_empty(t_deque *dq);
boolean is_full(t_deque *dq);
element get_front(t_deque *dq);
element get_rear(t_deque *dq);
void    push_front(t_deque *dq, int num);
void    push_rear(t_deque *dq, int num);
element    pop_rear(t_deque *dq);
element    pop_front(t_deque *dq);
void    print_dq(t_deque *dq);
#endif
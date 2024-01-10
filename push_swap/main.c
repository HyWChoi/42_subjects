#include "push_swap.h"

void    init_dq_a_b(t_deque *dq_a, t_deque *dq_b, int argc, char *argv[])
{
    int i;

    i = 1;
    init_deque(dq_a, argc); //큐의 가장 앞은 항상 검사를 위해 비어있어야 함
    init_deque(dq_b, argc);
    while (i < argc)
    {
        push_rear(dq_a, ft_atoi(*(argv + i++)), argc);
    }
}

int main(int argc, char *argv[])
{
    t_deque q_a;
    t_deque q_b;

    init_dq_a_b(&q_a, &q_b, argc, argv);
}


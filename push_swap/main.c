#include "push_swap.h"

void init_malloc(t_deque *dq, int argc)
{
    int i;

    i = 0;
    while (i < argc)
        init_deque(dq);
}

void init_push(t_deque *dq, int argc, char *argv[])
{
    int i;

    i = 1;
    while (i < argc)
        push_front(dq, *argv[i], argc);

}

int main(int argc, char *argv[])
{
    t_deque *q_a;
    t_deque *q_b;
    int     i;

    i = 0;
    q_a = NULL;
    q_b = NULL;
    init_malloc(q_a, argc);
    init_malloc(q_b, argc);
    init_push(q_a, argc, argv);

    print_dq(q_a);
}

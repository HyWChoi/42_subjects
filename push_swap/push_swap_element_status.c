#include "push_swap_element_status.h"

void    is_first_bigger_second(t_deque *dq, size_t size, void f(t_deque *dq, size_t size))
{
    element first_element;
    element second_element;

	if (count_dq(dq, size) < 2)
	{
		ft_printf("\nSwap nothing if there is only one or no elements.\n");
		return ;
	}
    first_element = dq->data[(dq->front + 1) % size];
    second_element = dq->data[(dq->front + 2) % size];
	if (first_element > second_element)
        f(dq, size);
}
void    is_first_bigger_last(t_deque *dq, size_t size, void f(t_deque *dq, size_t size))
{
    element first_element;
    element last_element;

	if (count_dq(dq, size) < 2)
	{
		ft_printf("\nSwap nothing if there is only one or no elements.\n");
		return ;
	}
    first_element = dq->data[(dq->front + 1) % size];
    last_element = dq->data[(dq->rear) % size];
	if (first_element > last_element)
        f(dq, size);
}
void    push_element(t_deque *start, t_deque *destination, size_t size, void f(t_deque *dq_a, t_deque *dq_b, size_t size))
{
    f(start, destination, size);
}

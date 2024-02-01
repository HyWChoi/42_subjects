#include "push_swap_element_status.h"

void	compare_elem_first_last_a(t_deque *dq, size_t size)
{
	if (dq->data[(dq->front + 1) % size] > dq->data[dq->rear])
		ra(dq, size);
	else if (dq->data[(dq->front + 1) % size] < dq->data[dq->rear])
		rra(dq, size);
}

void	compare_elem_first_last_b(t_deque *dq, size_t size)
{
	if (dq->data[(dq->front + 1) % size] > dq->data[dq->rear])
		rb(dq, size);
	else if (dq->data[(dq->front + 1) % size] < dq->data[dq->rear])
		rrb(dq, size);
}

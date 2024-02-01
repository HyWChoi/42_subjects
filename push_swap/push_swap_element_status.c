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

void compare_and_push(t_deque *dq_a, t_deque *dq_b, size_t size)
{
    int top_a = dq_a->data[(dq_a->front + 1) % size];
    int bottom_a = dq_a->data[dq_a->rear];
    int bottom_b = dq_b->data[dq_b->rear];

    // 비교 로직에 따라 조건문을 수정하면 됩니다.
    if (top_a > bottom_a && top_a > bottom_b)
    {
        pb(dq_a, dq_b, size);
    }
    // 필요한 경우 추가적인 조건문을 포함시킬 수 있습니다.
}

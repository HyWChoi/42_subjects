#include "push_swap_command.h"

void	sa(t_deque *dq_a, size_t size)
{
	element temp;

	if (count_dq(dq_a, size) < 2)
	{
		ft_printf("\nSa do nothing if there is only one or no elements.\n");
		return ;
	}
	temp = dq_a->data[(dq_a->front + 2) % size];
	dq_a->data[(dq_a->front + 2) % size] = dq_a->data[(dq_a->front + 1) % size];
	dq_a->data[(dq_a->front + 1) % size] = temp;
}
void	sb(t_deque *dq_b, size_t size)
{
	element temp;

	if (count_dq(dq_b, size) < 2)
	{
		ft_printf("\nSb do nothing if there is only one or no elements.\n");
		return ;
	}
	temp = dq_b->data[(dq_b->front + 2) % size];
	dq_b->data[(dq_b->front + 2) % size] = dq_b->data[(dq_b->front + 1) % size];
	dq_b->data[(dq_b->front + 1) % size] = temp;
}
void	ss(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	sa(dq_a, size);
	sb(dq_b, size);
}
void	pa(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	if (is_empty(dq_b))
		return ;
	push_rear(dq_a, pop_front(dq_b, size), size);
}

void	pb(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	if (is_empty(dq_a))
		return ;
	push_rear(dq_b, pop_front(dq_a, size), size);
}

#include "push_swap_command.h"

void	sa(t_deque *dq_a, size_t size)
{
	element temp;

	if (count_dq(dq_a, size) < 2)
		return ;
	temp = dq_a->data[(dq_a->front + 1) % size];
	dq_a->data[(dq_a->front + 1) % size] = dq_a->data[(dq_a->front + 2) % size];
	dq_a->data[(dq_a->front + 2) % size] = temp;
	ft_printf("sa\n");
}
void	sb(t_deque *dq_b, size_t size)
{
	element temp;

	if (count_dq(dq_b, size) < 2)
		return ;
	temp = dq_b->data[(dq_b->front + 1) % size];
	dq_b->data[(dq_b->front + 1) % size] = dq_b->data[(dq_b->front + 2) % size];
	dq_b->data[(dq_b->front + 2) % size] = temp;
	ft_printf("sb\n");
}
void	ss(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	sa(dq_a, size);
	sb(dq_b, size);
	ft_printf("ss\n");
}
void	pa(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	if (is_empty(dq_b))
		return ;
	push_front(dq_a, pop_front(dq_b, size), size);
	ft_printf("pa\n");
}

void	pb(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	if (is_empty(dq_a))
		return ;
	push_front(dq_b, pop_front(dq_a, size), size);
	ft_printf("pb\n");
}

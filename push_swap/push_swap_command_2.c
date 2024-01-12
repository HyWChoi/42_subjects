#include "push_swap_command.h"

void	ra(t_deque *dq_a, size_t size)
{
	push_front(dq_a, pop_rear(dq_a, size), size);
}
void	rb(t_deque *dq_b, size_t size)
{
	push_front(dq_b, pop_rear(dq_b, size), size);
}
void	rr(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	ra(dq_a, size);
	rb(dq_b, size);
}
void	rra(t_deque *dq_a, size_t size)
{
	push_rear(dq_a, pop_front(dq_a, size), size);
}
void	rrb(t_deque *dq_b, size_t size)
{
	push_rear(dq_b, pop_front(dq_b, size), size);
}

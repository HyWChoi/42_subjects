#include "push_swap_checker.h"

boolean	is_sorted(t_deque *dq, size_t size)
{
	int i;

	i = (dq->front + 1) % size;
	ft_printf("fi: %d\n", i);
	while (i != dq->rear)
	{
		ft_printf("i: %d\n", i);
		if (dq->data[i] > dq->data[(i + 1) % size])
			return (FALSE);
		i = (i + 1) % size;
	}
	return (TRUE);
}

void	checker(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	if (is_sorted(dq_a, size) && is_empty(dq_b))
		ft_printf("OK\n");
	else
		ft_printf("Error\n");
}

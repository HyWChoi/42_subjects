#include "push_swap_merge.h"

boolean	is_sorted_desc1(t_deque *dq, int amt)
{
	int i;
	size_t k;

	i = (dq->front + 1) % dq->size;
	k = 0;
	while ((i != dq->rear) && (k++ < amt - 1))
	{
		if (dq->data[i] < dq->data[(i + 1)])
			return (FALSE);
		i = (i + 1) % dq->size;
	}
	return (TRUE);
}

void	find_max(t_deque *dq, int amt)
{
	int i;
	int max;
	int max_index;

	i = 0;
	max = dq->data[(dq->front + 1) % dq->size];
	max_index = (dq->front + 1) % dq->size;
	while (i++ < amt)
	{
		if (max < dq->data[(dq->front + i) % dq->size])
		{
			max = dq->data[(dq->front + i) % dq->size];
			max_index = (dq->front + i) % dq->size;
		}
	}
}

void	make_asc_b(t_deque *dq_a, t_deque *dq_b, int amt)
{
	int i;

	i = 0;
	if (is_sorted_desc1(&dq_a, amt))
		while (i++ < amt)
			pb(dq_a, dq_b, dq_a->size);
}
// int	calc_amt(int depth, int i, int n)
// {
// 	if (depth == 0)
// 		return (n);
// 	else if (i < ft_pow(3, depth - 1))
// 		return (calc_amt(depth - 1, i, n) / 3);
// 	else if (i < ft_pow(3, depth - 1) * 2)
// 		return (calc_amt(depth - 1, (2 * ft_pow(3, depth - 1)) - 1 - i, n) / 3 + calc_amt(depth - 1, (2 * ft_pow(3, depth - 1)) - 1 - i, n) % 3);
// 	else
// 		return (calc_amt(depth - 1, (3 * ft_pow(3, depth - 1)) - 1 - i, n) / 3);
// }

void	merge_triangle(t_deque *dq_a, t_deque *dq_b, int depth)
{
	int	i;
	int	k;
	int	limit;

	i = 0;
	k = 0;
	limit = 0;
	while (k < ft_pow(3, depth - 1))
	{
		while (i++ < calc_amt(depth, k, dq_a->size - 1))
		{
				pa(dq_a, dq_b, dq_a->size);
		}
		limit += i;
		i = 0;
		k++;
	}
	while ((size_t)i++ < 9)
	{
		if (is_first_bigger_last(dq_b, dq_b->size))
		{
			if (dq_a->data[dq_a->rear % dq_a->size] < dq_b->data[(dq_b->front + 1) % dq_b->size]
				&& dq_a->data[(dq_a->front + 1) % dq_a->size] > dq_b->data[(dq_b->front + 1) % dq_b->size])
				pa(dq_a, dq_b, dq_a->size);
			else if (dq_a->data[dq_a->rear % dq_a->size] > dq_b->data[(dq_b->front + 1) % dq_b->size]
				&& is_first_bigger_last(dq_a, dq_a->size))
				rra(dq_a, dq_a->size);
			else if (dq_a->data[dq_a->rear % dq_a->size] > dq_b->data[(dq_b->front + 1) % dq_b->size]
			    && dq_a->data[(dq_a->front + 1) % dq_a->size] > dq_b->data[(dq_b->front + 1) % dq_b->size])
				pa(dq_a, dq_b, dq_a->size);
			else
				rra(dq_a, dq_a->size);
		}
		else
		{
			if (dq_a->data[dq_a->rear % dq_a->size] < dq_b->data[dq_b->rear % dq_b->size])
			{
				rrb(dq_b, dq_b->size);
				pa(dq_a, dq_b, dq_a->size);
			}
			else if (dq_a->data[dq_a->rear % dq_a->size] > dq_b->data[dq_b->rear % dq_b->size]
				&& is_first_bigger_last(dq_a, dq_a->size))
				rra(dq_a, dq_a->size);
			else if (dq_a->data[dq_a->rear % dq_a->size] > dq_b->data[dq_b->rear % dq_b->size]
				&& dq_a->data[(dq_a->front + 1) % dq_a->size] > dq_b->data[dq_b->rear % dq_b->size])
			{
				rrb(dq_b, dq_b->size);
				pa(dq_a, dq_b, dq_a->size);
			}
			else
				rra(dq_a, dq_a->size);
		}
	}
	i = 0;
	while ((size_t)i++ < 9)
	{
		if (!is_first_bigger_last(dq_b, dq_b->size))
		{
			if (dq_a->data[dq_a->rear % dq_a->size] > dq_b->data[(dq_b->front + 1) % dq_b->size])
				pa(dq_a, dq_b, dq_a->size);
			else if (dq_a->data[dq_a->rear % dq_a->size] < dq_b->data[(dq_b->front + 1) % dq_b->size]
				&& !is_first_bigger_last(dq_a, dq_a->size))
				rra(dq_a, dq_a->size);
			else if (dq_a->data[dq_a->rear % dq_a->size] < dq_b->data[(dq_b->front + 1) % dq_b->size]
			    && dq_a->data[(dq_a->front + 1) % dq_a->size] < dq_b->data[(dq_b->front + 1) % dq_b->size])
				pa(dq_a, dq_b, dq_a->size);
			else
				rra(dq_a, dq_a->size);
		}
		else
		{
			if (dq_a->data[dq_a->rear % dq_a->size] > dq_b->data[dq_b->rear % dq_b->size]
				&& dq_a->data[(dq_a->front + 1) % dq_a->size] < dq_b->data[(dq_b->rear) % dq_b->size])
			{
				rrb(dq_b, dq_b->size);
				pa(dq_a, dq_b, dq_a->size);
			}
			else if (dq_a->data[dq_a->rear % dq_a->size] > dq_b->data[dq_b->rear % dq_b->size]
				&& !is_first_bigger_last(dq_a, dq_a->size))
				rra(dq_a, dq_a->size);
			else if (dq_a->data[dq_a->rear % dq_a->size] > dq_b->data[dq_b->rear % dq_b->size]
				&& dq_a->data[(dq_a->front + 1) % dq_a->size] < dq_b->data[dq_b->rear % dq_b->size])
			{
				rrb(dq_b, dq_b->size);
				pa(dq_a, dq_b, dq_a->size);
			}
			else
				rra(dq_a, dq_a->size);
		}
	}
}

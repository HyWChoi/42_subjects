#include "push_swap_checker.h"
#include <stdio.h>

void	init_dq_a_b(t_deque *dq_a, t_deque *dq_b, int argc, char *argv[])
{
	int i;

	i = 1;
	init_deque(dq_a, argc); //큐의 가장 앞은 항상 검사를 위해 비어있어야 함
	init_deque(dq_b, argc);
	while (i < argc)
	{
		if (ft_is_number(*(argv + i)) == ERROR)
			error_exit(dq_a, dq_b);
		push_rear(dq_a, ft_atoi_push_swap(*(argv + i++), dq_a, dq_b), argc);
	}
}
int	is_first_bigger_second(t_deque *dq, size_t size)
{
	if (dq->data[(dq->front + 1) % size] < dq->data[(dq->front + 2) % size])
		return (FALSE);
	return (TRUE);
}
int	is_first_bigger_last(t_deque *dq, size_t size)
{
	if (dq->data[(dq->front + 1) % size] < dq->data[(dq->rear) % size])
		return (FALSE);
	return (TRUE);
}
int	is_second_bigger_last(t_deque *dq, size_t size)
{
	if (dq->data[(dq->front + 2) % size] < dq->data[(dq->rear) % size])
		return (FALSE);
	return (TRUE);
}
int	ft_pow(int base, int exp)
{
	int result = 1;

	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

int	calc_depth(int i)
{
	int depth = 1;
	int count = 0;
	while (ft_pow(3, depth) <= i)
	{
		depth++;
		count++;
	}
	if (depth == 2)
		return (1);
	return (count - 1);
}

int	calc_dir(int depth, int i)
{
	if (depth == 0)
		return (1);
	if (i < ft_pow(3, depth - 1))
		return (calc_dir(depth - 1, i));
	if (i < ft_pow(3, depth - 1) * 2)
		return (!calc_dir(depth - 1, ft_pow(3, depth - 1) * 2 - 1 - i));
	else
		return (!calc_dir(depth - 1, ft_pow(3, depth - 1) * 3 - 1 - i));
}

int	calc_amt(int depth, int i, int n)
{
	if (depth == 0)
    	return (n);
    else if (i < ft_pow(3, depth - 1))
    	return (calc_amt(depth - 1, i, n) / 3);
    else if (i < ft_pow(3, depth - 1) * 2)
		return (calc_amt(depth - 1, (2 * ft_pow(3, depth - 1)) - 1 - i, n) / 3 + calc_amt(depth - 1, (2 * ft_pow(3, depth - 1)) - 1 - i, n) % 3);
    else
    	return (calc_amt(depth - 1, (3 * ft_pow(3, depth - 1)) - 1 - i, n) / 3);
}

void	make_triangle_asc(t_deque *dq_a, t_deque *dq_b, int amt)
{
	int i;

	i = 0;
	while (i++ < amt)
	{
		if (is_empty(dq_a))
			return;
		if (i == 1)
		{
			if (is_first_bigger_second(dq_a, dq_a->size))
			{
				if (!is_first_bigger_last(dq_a, dq_a->size))
					rra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
			}
			else
			{
				sa(dq_a, dq_a->size);
				if (!is_first_bigger_last(dq_a, dq_a->size))
					rra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
			}
		}
		else
		{
			if (is_first_bigger_second(dq_a, dq_a->size))
			{
				if (!is_first_bigger_last(dq_a, dq_a->size))
					rra(dq_a, dq_a->size);
				while (dq_a->data[(dq_a->front + 1) % dq_a->size] > dq_b->data[(dq_b->front + 1) % dq_b->size])
					ra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
			}
			else
			{
				sa(dq_a, dq_a->size);
				if (!is_first_bigger_last(dq_a, dq_a->size))
					rra(dq_a, dq_a->size);
				while (dq_a->data[(dq_a->front + 1) % dq_a->size] > dq_b->data[(dq_b->front + 1) % dq_b->size])
					ra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
			}
		}
	}
}

void	make_triangle_desc(t_deque *dq_a, t_deque *dq_b, int amt)
{
	int i;

	i = 0;
	while (i++ < amt)
	{
		if (is_empty(dq_a))
			return;
		if (i == 1)
		{
			if (!is_first_bigger_second(dq_a, dq_a->size))
			{
				if (is_first_bigger_last(dq_a, dq_a->size))
					rra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
			}
			else
			{
				sa(dq_a, dq_a->size);
				if (is_first_bigger_last(dq_a, dq_a->size))
					rra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
			}
		}
		else
		{
			if (!is_first_bigger_second(dq_a, dq_a->size))
			{
				int count = count_dq(dq_a, dq_a->size);
				if (is_first_bigger_last(dq_a, dq_a->size))
					rra(dq_a, dq_a->size);
				while (dq_a->data[(dq_a->front + 1) % dq_a->size] < dq_b->data[(dq_b->front + 1) % dq_b->size] && count-- > 0)
					ra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
			}
			else
			{
				int count = count_dq(dq_a, dq_a->size);
				sa(dq_a, dq_a->size);
				if (is_first_bigger_last(dq_a, dq_a->size))
					rra(dq_a, dq_a->size);
				while (dq_a->data[(dq_a->front + 1) % dq_a->size] < dq_b->data[(dq_b->front + 1) % dq_b->size] && count-- > 0)
					ra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
			}
		}
	}
}

void	make_triangular(t_deque *dq_a, t_deque *dq_b)
{
	int	i;
	int	depth;
	int	dir;
	int	amt;

	if (dq_a->size == 0)
		return ;
	depth = calc_depth(dq_a->size - 1);
	i = 0;
	while (i < ft_pow(3, depth))
	{
		dir = calc_dir(depth, i);
		amt = calc_amt(depth, i, dq_a->size - 1);
		if (dir == 1)
			make_triangle_asc(dq_a, dq_b, amt);
		else
			make_triangle_desc(dq_a, dq_b, amt);
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_deque dq_a;
	t_deque dq_b;
	int i;

	i = 0;
	init_dq_a_b(&dq_a, &dq_b, argc, argv);
	watch_dq_a_b_state(&dq_a, &dq_b, argc);
	make_triangular(&dq_a, &dq_b);
	watch_dq_a_b_state(&dq_a, &dq_b, argc);
	return (0);
}

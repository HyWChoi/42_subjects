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
int ft_pow(int base, int exp)
{
	int result;

	result = 1;
	if (exp == 0)
		return (1);
	while (exp > 1)
	{
		if (exp % 2 == 0)
		{
			base *= base;
			exp /= 2;
		}
		else
		{
			result *= base;
			exp--;
		}
	}
	return (result * base);
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

boolean	is_sorted_desc1(t_deque *dq, int amt)
{
	int i;
	int k;

	i = (dq->front + 1) % dq->size;
	k = 0;
	while ((i != dq->rear % dq->size) && (k++ < amt - 1))
	{
		if (dq->data[i % dq->size] < dq->data[(i + 1) % dq->size])
			return (FALSE);
		i = (i + 1) % dq->size;
	}
	return (TRUE);
}

boolean	is_sorted_asc1(t_deque *dq, int amt)
{
	int i;
	int k;

	i = (dq->front + 1) % dq->size;
	k = 0;
	while ((i != dq->rear % dq->size ) && (k++ < amt - 1))
	{
		if (dq->data[i % dq->size] > dq->data[(i + 1) % dq->size])
			return (FALSE);
		i = (i + 1) % dq->size;
	}
	return (TRUE);
}

int	get_max_index_index_with_limit(t_deque *dq, int amt, element limit)
{
	int i;
	element max;
	size_t index;

	i = 0;
	max = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	if (max > limit)
	{
		i++;
		max = dq->data[(dq->front + 1 + i) % dq->size];
		index = (dq->front + 1 + i) % dq->size;
	}
	while (i < amt - 1)
	{
		if (max < dq->data[(dq->front + 1 + i) % dq->size] && dq->data[(dq->front + 1 + i) % dq->size] < limit)
		{
			max = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	if (dq->data[(dq->rear) % dq->size] > max && dq->data[(dq->rear) % dq->size] < limit)
		index = dq->rear % dq->size;
	return (index);
}

int	get_max_index(t_deque *dq, int amt)
{
	int i;
	element max;
	size_t index;

	i = 1;
	max = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt - 1)
	{
		if (max < dq->data[(dq->front + 1 + i) % dq->size])
		{
			max = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	if (dq->data[(dq->rear) % dq->size] > max)
		index = dq->rear % dq->size;
	return (index);
}


int	count_moves_with_value(t_deque *dq, int value_index)
{
	int ra;
	int rra;
	int sa;
	int pb;

	pb = 0;
	sa = 1;
	ra = 2;
	rra = 3;
	if (value_index == (dq->front + 1) % dq->size)
		return (pb);
	else if (value_index == (dq->front + 2) % dq->size)
		return (sa);
	else if ((unsigned long)value_index > dq->rear % dq->size)
		return (rra);
	else if ((unsigned long)value_index <= ((dq->front) % dq->size + (dq->rear) % dq->size) / 2)
		return (ra);
	else
		return (rra);
}

void	make_asc_2_b(t_deque *dq_a, t_deque *dq_b, int amt)
{
	int	i;
	int	move;
	int	max_index;

	i = 0;
	if (is_sorted_desc1(dq_a, amt))
		while (amt-- > 0)
			pb(dq_a, dq_b,dq_a->size);
	while (i < amt)
	{
		if (i == 0)
		{
			max_index = get_max_index(dq_a, amt);
			move = count_moves_with_value(dq_a, max_index);
		}
		else
		{
			max_index = get_max_index_index_with_limit(dq_a, amt, dq_b->data[(dq_b->front + 1) % dq_b->size]);
			move = count_moves_with_value(dq_a, max_index);
		}
		if (move == 1) // sa
		{
			sa(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else if (move == 2) // ra
		{
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != dq_a->data[max_index])
				ra(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else if (move == 3) // rra
		{
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != dq_a->data[max_index])
				rra(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else
			pb(dq_a, dq_b, dq_a->size);
		i++;
	}
}

int	get_min_index_with_limit(t_deque *dq, int amt, element limit)
{
	int i;
	element min;
	size_t index;

	i = 0;
	min = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt - 1)
	{
		if (dq->data[(dq->front + 1 + i) % dq->size] < min && dq->data[(dq->front + 1 + i) % dq->size] > limit)
		{
			min = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	if (dq->data[(dq->rear) % dq->size] < min && dq->data[(dq->rear) % dq->size] > limit)
		index = dq->rear % dq->size;
	return (index);
}

int	get_min_index(t_deque *dq, int amt)
{
	int i;
	element min;
	size_t index;

	i = 0;
	min = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt - 1)
	{
		if (min > dq->data[(dq->front + 1 + i) % dq->size])
		{
			min = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	if (dq->data[(dq->rear) % dq->size] < min)
		index = dq->rear % dq->size;
	return (index);
}

void	make_desc_2_b(t_deque *dq_a, t_deque *dq_b, int amt)
{
	int	i;
	int	move;
	int	min_index;

	i = 0;
	if (is_sorted_asc1(dq_a, amt))
		while (amt-- > 0)
			pb(dq_a, dq_b,dq_a->size);
	while (i < amt)
	{
		if (i == 0)
		{
			min_index = get_min_index(dq_a, amt);
			move = count_moves_with_value(dq_a, min_index);
		}
		else
		{
			min_index = get_min_index_with_limit(dq_a, amt - i, dq_b->data[(dq_b->front + 1) % dq_b->size]);
			move = count_moves_with_value(dq_a, min_index);
		}
		if (move == 1) // sa
		{
			sa(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else if (move == 2) // ra
		{
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != dq_a->data[min_index % dq_a->size])
				ra(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else if (move == 3) // rra
		{
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != dq_a->data[min_index % dq_a->size])
				rra(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else
			pb(dq_a, dq_b, dq_a->size);
		i++;
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
	dq_b->size = dq_a->size;
	i = 0;
	while (i < ft_pow(3, depth))
	{
		dir = calc_dir(depth, i);
		amt = calc_amt(depth, i, dq_a->size - 1);
		if (dir == 1)
			make_asc_2_b(dq_a, dq_b, amt);
		else
			make_desc_2_b(dq_a, dq_b, amt);
		// ft_printf("dir: %d, amt: %d\n", dir, amt);
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
	// watch_dq_a_b_state(&dq_a, &dq_b, argc);
	// make_asc_2_b(&dq_a, &dq_b, 3);
	// make_desc_2_b(&dq_a, &dq_b, 4);
	// make_desc_2_b(&dq_a, &dq_b, 3);
	make_triangular(&dq_a, &dq_b);
	// watch_dq_a_b_state(&dq_a, &dq_b, argc);

	return (0);
}

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
	while (i < amt - 1)
	{
		// ft_printf("flag1\n");
		if (max <= dq->data[(dq->front + 1 + i) % dq->size] && dq->data[(dq->front + 1 + i) % dq->size] < limit)
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

	i = 0;
	max = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt - 1)
	{
		// ft_printf("flag2\n");
		if (max <= dq->data[(dq->front + 1 + i) % dq->size])
		{
			max = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	if (dq->data[(dq->rear) % dq->size] > max)
		index = dq->rear % dq->size;
	// ft_printf("max: %d, index: %d\n", max, index);
	return (index);
}

boolean	is_closer_front(t_deque *dq, int value_index)
{
	int front_distance, rear_distance;

	front_distance = (value_index - dq->front + dq->size) % dq->size;
	rear_distance = (dq->rear - value_index + dq->size) % dq->size;

	if (front_distance <= rear_distance)
		return (TRUE);
	else
		return (FALSE);
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
	else if (is_closer_front(dq, value_index))
		return (ra);
	else
		return (rra);
}

void	make_asc_2_b(t_deque *dq_a, t_deque *dq_b, int amt)
{
	int	i;
	int	move;
	int	max_index;
	int max;

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
			max = dq_a->data[max_index];

			// ft_printf("max: %d\n", max);
			// ft_printf("max_index: %d\n", max_index);
		}
		else
		{
			max_index = get_max_index_index_with_limit(dq_a, amt, dq_b->data[(dq_b->front + 1) % dq_b->size]);
			move = count_moves_with_value(dq_a, max_index);
			max = dq_a->data[max_index];
			if (max > dq_b->data[(dq_b->front + 1) % dq_b->size])
			{
				rra(dq_a, dq_a->size);
				continue ;
			}
			// ft_printf("dq_a->front: %d, dq_a->rear: %d\n",dq_a->front % dq_a->size, dq_a->rear % dq_a->size);
			// ft_printf("max: %d\n", max);
			// ft_printf("max_index: %d\n", max_index);
		}
		if (move == 1) // sa
		{
			sa(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else if (move == 2) // ra
		{
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != max)
				ra(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else if (move == 3) // rra
		{
			// ft_printf("FUCK");
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != max)
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
		// ft_printf("limit: %d\n", limit);
		if (min >= dq->data[(dq->front + 1 + i) % dq->size] && dq->data[(dq->front + 1 + i) % dq->size] > limit)
		{
			// ft_printf("Tlqkfmin: %d, dq->data[(dq->front + 2 + i) %% dq->size]: %d\n", min, dq->data[(dq->front + 2 + i) % dq->size]);
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
		// ft_printf("flag4\n");
		if (min >= dq->data[(dq->front + 1 + i) % dq->size])
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
	int min;

	i = 0;
	if (is_sorted_asc1(dq_a, amt))
		while (amt-- > 0)
			pb(dq_a, dq_b,dq_a->size);
	while (i < amt)
	{
		// ft_printf("i: %d\n", i);
		if (i == 0)
		{
			min_index = get_min_index(dq_a, amt);
			move = count_moves_with_value(dq_a, min_index);
			min = dq_a->data[min_index];

			// ft_printf("amt: %d\n", amt);
			// ft_printf("min: %d\n", min);
			// ft_printf("min_index: %d\n", min_index);
		}
		else
		{
			min_index = get_min_index_with_limit(dq_a, amt, dq_b->data[(dq_b->front + 1) % dq_b->size]);
			move = count_moves_with_value(dq_a, min_index);
			min = dq_a->data[min_index];
			if (min < dq_b->data[(dq_b->front + 1) % dq_b->size])
			{
				ra(dq_a, dq_a->size);
				continue ;
			}
			// ft_printf("dq_b first element: %d\n", dq_b->data[(dq_b->front + 1) % dq_b->size]);
			// ft_printf("amt: %d\n", amt);
			// ft_printf("min: %d\n", min);
			// ft_printf("min_index: %d\n", min_index);
			// ft_printf("dq_a->front: %d\n",dq_a->front);
		}
		if (move == 1) // sa
		{
			sa(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else if (move == 2) // ra
		{
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != min)
				ra(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else if (move == 3) // rra
		{
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != min)
				rra(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else
			pb(dq_a, dq_b, dq_a->size);
		i++;
	}
}

void	decide_triangular(t_deque *dq_a, t_deque *dq_b, int depth, int amt, int dir)
{
	if (depth % 2 == 1)
	{
		if (dir == 1)
			make_asc_2_b(dq_a, dq_b, amt);
		else
			make_desc_2_b(dq_a, dq_b, amt);
		// // ft_printf("depth: %d, dir: %d, amt: %d\n", depth, dir, amt);
	}
	else
	{
		if (dir == 1)
			make_desc_2_b(dq_a, dq_b, amt);
		else
			make_asc_2_b(dq_a, dq_b, amt);
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
		decide_triangular(dq_a, dq_b, depth, amt, dir);
		i++;
	}
}


void	merge(t_deque *dq_a, t_deque *dq_b, int depth)
{
	int	i;
	int	k;
	int	limit;

	i = 0;
	// 전 단계의 설계도대로 만들어야됨 그러면 일단 현재 만들어야하는 곳이 a인지 b인지 먼저 판단해야겠지?
	//  만들어야 하는 곳의 위치는 현재 depth - 1이 홀/짝인지 먼저 검사해야겠지?
	//  그 전에 몇개의 삼각형을 만들어야하는지는 어떻게 판단할까?
	//  3의 현재 depth 승이 몇인지 알아야겠지?
	if (depth % 2 == 1)
		merge_triangle_2_a(dq_a, dq_b, depth);
	else
		merge_triangle_2_b(dq_a, dq_b, depth);
}

boolean	is_rear_bigger_opposite_rear(t_deque *dq, t_deque *opposite)
{
	if (dq->data[dq->rear % dq->size] < opposite->data[opposite->rear % opposite->size])
		return (FALSE);
	return (TRUE);
}

boolean	is_rear_bigger_opposite_front(t_deque *dq, t_deque *opposite)
{
	if (dq->data[dq->rear % dq->size] < opposite->data[(opposite->front + 1) % opposite->size])
		return (FALSE);
	return (TRUE);
}

void	merge_asc_2_a(t_deque *dq_a, t_deque *dq_b, int amt)
{
	int	i;
	element	dq_a_rear;
	element	dq_b_front;
	element	dq_b_rear;

	i = 0;
	dq_a_rear = calc_amt;
	dq_b_front = dq_b->data[(dq_b->front + 1) % dq_b->size];
	dq_b_rear = dq_b->data[dq_b->rear % dq_b->size];
	while (i < amt)
	{
		if (is_first_bigger_last(dq_b, dq_b->size))
		{
			if (is_rear_bigger_opposite_first(dq_a, dq_b))
				rra(dq_a, dq_a->size);
			else
				pa(dq_a, dq_b, dq_a->size);
		}
		else
		{
			if (is_rear_bigger_opposit_rear(dq_a, dq_b))
				rra(dq_a, dq_a->size);
			else
			{
				rrb(dq_b, dq_b->size);
				pa(dq_a, dq_b, dq_a->size);
			}
		}
	}
}

void	merge_triangle_2_a(t_deque *dq_a, t_deque *dq_b, int depth)
{
	int	i;
	int	k;
	int	dir;
	int	amt;

	i = 0;
	k = 0;
	while (k < ft_pow(3, depth - 1))
	{
		while (i++ < calc_amt(depth, k, dq_a->size - 1))
				pa(dq_a, dq_b, dq_a->size);
		i = 0;
		k++;
	}
	while (i < ft_pow(3, depth))
	{
		dir = calc_dir(depth, i);
		amt = calc_amt(depth, i, dq_a->size - 1);
		if (dir == 1)
			merge_asc_2_a(dq_a, dq_b, amt);
		else
			merge_desc_2_a(dq_a, dq_b, amt);
	}
}

void	merge_triangle_2_b(t_deque *dq_a, t_deque *dq_b, int depth)
{
	int	i;
	int	k;
	int	dir;
	int	amt;

	i = 0;
	k = 0;
	while (k < ft_pow(3, depth - 1))
	{
		while (i++ < calc_amt(depth, k, dq_a->size - 1))
				pb(dq_a, dq_b, dq_a->size);
		i = 0;
		k++;
	}
	while (i < ft_pow(3, depth))
	{
		dir = calc_dir(depth, i);
		amt = calc_amt(depth, i, dq_a->size - 1);
		if (dir == 1)
			merge_asc_2_b(dq_a, dq_b, amt);
		else
			merge_desc_2_b(dq_a, dq_b, amt);
	}
}



int main(int argc, char *argv[])
{
	t_deque dq_a;
	t_deque dq_b;
	int i;
	int amt;
	int depth;

	i = 0;
	amt = 0;
	init_dq_a_b(&dq_a, &dq_b, argc, argv);
	depth = calc_depth((&dq_a)->size - 1);
	make_triangular(&dq_a, &dq_b);
	// merge_triangle(&dq_a, &dq_b, depth);
	// while (i < ft_pow(3, depth))
	// {
	// 	ft_printf("depth: %d, dir: %d, amt: %d\n", depth , calc_dir(depth , i), calc_amt(depth, i, argc -1));
	// 	i++;
	// }
	return (0);
}
/*
void	merge()
{
	while (depth-- > 0)
		if (depth % 2 == 1)
			if (dir % 2 == 1)
				merge_asc_2_a();
			else
				merge_desc_2_a();
		else
			if (dir % 2 == 1)
				merge_asc_2_b();
			else
				merge_asc_2_b();

}
*/

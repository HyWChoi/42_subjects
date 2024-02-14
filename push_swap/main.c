#include "push_swap_devide.h"
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

int *make_amt_list(size_t size , int depth)
{
	int *lst;
	int i;
	i = 0;
	lst = (int *)malloc(sizeof(int) * ft_pow(3, depth));
	while (i < ft_pow(3, depth))
	{
		lst[i] = calc_amt(depth, i, size);
		i++;
	}
	return (lst);
}
void	merge_asc_2_b(t_deque *dq_a, t_deque *dq_b,int depth, int amt, int *amt_lst, int i)
{
	int k;
	element dq_b_rear;
	element dq_a_front;
	element dq_a_rear;
	k = 0;
	dq_b_rear = amt_lst[0 + i];
	dq_a_front = amt_lst[ft_pow(3, depth - 1) + i];
	dq_a_rear = amt_lst[ft_pow(3, depth) - i - 1];
	// ft_printf("dq_b_rear: %d, dq_a_front: %d, dq_a_rear: %d\n", dq_b_rear, dq_a_front, dq_a_rear);
	// ft_printf("k: %d, amt: %d\n", k, amt);
	while (k++ < amt)
	{
		// ft_printf("dq_a[%d]: %d, dq_b[%d]: %d, dq_b[%d]: %d\n", dq_b_rear, dq_a->data[dq_a->rear % dq_a->size], dq_a_front, dq_b->data[(dq_b->front + 1) % dq_b->size], dq_a_rear, dq_b->data[dq_b->rear % dq_b->size]);
		if (dq_b_rear > 0 && dq_a_front > 0 && dq_a_rear > 0)
		{
			if (is_rear_bigger_opposite_front(dq_b, dq_a))
			{
				if (is_rear_bigger_opposite_rear(dq_b, dq_a))
				{
					rrb(dq_b, dq_b->size);
					dq_b_rear--;
				}
				else
				{
					rra(dq_a, dq_a->size);
					pb(dq_a, dq_b, dq_a->size);
					dq_a_rear--;
				}
			}
			else
			{
				if (is_first_bigger_last(dq_a, dq_a->size))
				{
					pb(dq_a, dq_b, dq_a->size);
					dq_a_front--;
				}
				else
				{
					rra(dq_a, dq_a->size);
					pb(dq_a, dq_b, dq_a->size);
					dq_a_rear--;
				}
			}
		}
		else if (dq_b_rear <= 0 && dq_a_front > 0 && dq_a_rear > 0)
		{
			if (is_first_bigger_last(dq_a, dq_a->size))
			{
				pb(dq_a, dq_b, dq_a->size);
				dq_a_front--;
			}
			else
			{
				rra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
				dq_a_rear--;
			}
		}
		else if (dq_b_rear > 0 && dq_a_front <= 0 && dq_a_rear > 0)
		{
			if (is_rear_bigger_opposite_rear(dq_b, dq_a))
			{
				rrb(dq_b, dq_b->size);
				dq_b_rear--;
			}
			else
			{
				rra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
				dq_a_rear--;
			}
		}
		else if (dq_b_rear > 0 && dq_a_front > 0 && dq_a_rear <= 0)
		{
			if (is_rear_bigger_opposite_front(dq_b, dq_a))
			{
				rrb(dq_b, dq_b->size);
				dq_b_rear--;
			}
			else
			{
				pb(dq_a, dq_b, dq_a->size);
				dq_a_front--;
			}
		}
		else if (dq_b_rear <= 0 && dq_a_front <= 0 && dq_a_rear > 0)
		{
			rra(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
			dq_a_rear--;
		}
		else if (dq_b_rear <= 0 && dq_a_front > 0 && dq_a_rear <= 0)
		{
			pb(dq_a, dq_b, dq_a->size);
			dq_a_front--;
		}
		else if (dq_b_rear > 0 && dq_a_front <= 0 && dq_a_rear <= 0)
		{
			rrb(dq_b, dq_b->size);
			dq_b_rear--;
		}
	}
}


void	merge_desc_2_b(t_deque *dq_a, t_deque *dq_b,int depth, int amt, int *amt_lst, int i)
{
	int k;
	element dq_b_rear;
	element dq_a_front;
	element dq_a_rear;
	k = 0;
	dq_b_rear = amt_lst[0 + i];
	dq_a_front = amt_lst[ft_pow(3, depth - 1) + i];
	dq_a_rear = amt_lst[ft_pow(3, depth) - i - 1];
	// ft_printf("dq_b_rear: %d, dq_a_front: %d, dq_a_rear: %d\n", dq_b_rear, dq_a_front, dq_a_rear);
	// ft_printf("k: %d, amt: %d\n", k, amt);
	while (k++ < amt)
	{
		// ft_printf("dq_a[%d]: %d, dq_b[%d]: %d, dq_b[%d]: %d\n", dq_b_rear, dq_a->data[dq_a->rear % dq_a->size], dq_a_front, dq_b->data[(dq_b->front + 1) % dq_b->size], dq_a_rear, dq_b->data[dq_b->rear % dq_b->size]);
		if (dq_b_rear > 0 && dq_a_front > 0 && dq_a_rear > 0)
		{
			if (!is_rear_bigger_opposite_front(dq_b, dq_a))
			{
				if (!is_rear_bigger_opposite_rear(dq_b, dq_a))
				{
					rrb(dq_b, dq_b->size);
					dq_b_rear--;
				}
				else
				{
					rra(dq_a, dq_a->size);
					pb(dq_a, dq_b, dq_a->size);
					dq_a_rear--;
				}
			}
			else
			{
				if (!is_first_bigger_last(dq_a, dq_a->size))
				{
					pb(dq_a, dq_b, dq_a->size);
					dq_a_front--;
				}
				else
				{
					rra(dq_a, dq_a->size);
					pb(dq_a, dq_b, dq_a->size);
					dq_a_rear--;
				}
			}
		}
		else if (dq_b_rear <= 0 && dq_a_front > 0 && dq_a_rear > 0)
		{
			if (!is_first_bigger_last(dq_a, dq_a->size))
			{
				pb(dq_a, dq_b, dq_a->size);
				dq_a_front--;
			}
			else
			{
				rra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
				dq_a_rear--;
			}
		}
		else if (dq_b_rear > 0 && dq_a_front <= 0 && dq_a_rear > 0)
		{
			if (!is_rear_bigger_opposite_rear(dq_b, dq_a))
			{
				rrb(dq_b, dq_a->size);
				dq_b_rear--;
			}
			else
			{
				rra(dq_a, dq_a->size);
				pb(dq_a, dq_b, dq_a->size);
				dq_a_rear--;
			}
		}
		else if (dq_b_rear > 0 && dq_a_front > 0 && dq_a_rear <= 0)
		{
			if (!is_rear_bigger_opposite_front(dq_b, dq_a))
			{
				rrb(dq_b, dq_b->size);
				dq_b_rear--;
			}
			else
			{
				pb(dq_a, dq_b, dq_a->size);
				dq_a_front--;
			}
		}
		else if (dq_b_rear <= 0 && dq_a_front <= 0 && dq_a_rear > 0)
		{
			rra(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
			dq_a_rear--;
		}
		else if (dq_b_rear <= 0 && dq_a_front > 0 && dq_a_rear <= 0)
		{
			pb(dq_a, dq_b, dq_a->size);
			dq_a_front--;
		}
		else if (dq_b_rear > 0 && dq_a_front <= 0 && dq_a_rear <= 0)
		{
			rrb(dq_b, dq_b->size);
			dq_b_rear--;
		}
	}
}

void	merge_asc_2_a(t_deque *dq_a, t_deque *dq_b,int depth, int amt, int *amt_lst, int i)
{
	int k;
	element dq_a_rear;
	element dq_b_front;
	element dq_b_rear;
	k = 0;
	dq_a_rear = amt_lst[0 + i];
	dq_b_front = amt_lst[ft_pow(3, depth - 1) + i];
	dq_b_rear = amt_lst[ft_pow(3, depth) - i - 1];
	// ft_printf("dq_a_rear: %d, dq_b_front: %d, dq_b_rear: %d\n", dq_a_rear, dq_b_front, dq_b_rear);
	// ft_printf("k: %d, amt: %d\n", k, amt);
	while (k++ < amt)
	{
		// ft_printf("dq_a_rear: %d, dq_b_front: %d, dq_b_rear: %d\n", dq_a_rear, dq_b_front, dq_b_rear);
		// ft_printf("k: %d, amt: %d\n", k, amt);
		// ft_printf("dq_a[rear]: %d, dq_b[front]: %d, dq_b[rear]: %d\n", dq_a->data[dq_a->rear % dq_a->size], dq_b->data[(dq_b->front + 1) % dq_b->size], dq_b->data[dq_b->rear % dq_b->size]);
		if (dq_a_rear > 0 && dq_b_front > 0 && dq_b_rear > 0)
		{
			if (is_rear_bigger_opposite_front(dq_a, dq_b))
			{
				if (is_rear_bigger_opposite_rear(dq_a, dq_b))
				{
					rra(dq_a, dq_a->size);
					dq_a_rear--;
				}
				else
				{
					rrb(dq_b, dq_b->size);
					pa(dq_a, dq_b, dq_a->size);
					dq_b_rear--;
				}
			}
			else
			{
				if (is_first_bigger_last(dq_b, dq_b->size))
				{
					pa(dq_a, dq_b, dq_a->size);
					dq_b_front--;
				}
				else
				{
					rrb(dq_b, dq_b->size);
					pa(dq_a, dq_b, dq_a->size);
					dq_b_rear--;
				}
			}
		}
		else if (dq_a_rear <= 0 && dq_b_front > 0 && dq_b_rear > 0)
		{
			if (is_first_bigger_last(dq_b, dq_b->size))
			{
				pa(dq_a, dq_b, dq_a->size);
				dq_b_front--;
			}
			else
			{
				rrb(dq_b, dq_b->size);
				pa(dq_a, dq_b, dq_a->size);
				dq_b_rear--;
			}
		}
		else if (dq_a_rear > 0 && dq_b_front <= 0 && dq_b_rear > 0)
		{
			if (is_rear_bigger_opposite_rear(dq_a, dq_b))
			{
				rra(dq_a, dq_a->size);
				dq_a_rear--;
			}
			else
			{
				rrb(dq_b, dq_b->size);
				pa(dq_a, dq_b, dq_a->size);
				dq_b_rear--;
			}
		}
		else if (dq_a_rear > 0 && dq_b_front > 0 && dq_b_rear <= 0)
		{
			if (is_rear_bigger_opposite_front(dq_a, dq_b))
			{
				rra(dq_a, dq_a->size);
				dq_a_rear--;
			}
			else
			{
				pa(dq_a, dq_b, dq_a->size);
				dq_b_front--;
			}
		}
		else if (dq_a_rear <= 0 && dq_b_front <= 0 && dq_b_rear > 0)
		{
			rrb(dq_b, dq_b->size);
			pa(dq_a, dq_b, dq_a->size);
			dq_b_rear--;
		}
		else if (dq_a_rear <= 0 && dq_b_front > 0 && dq_b_rear <= 0)
		{
			pa(dq_a, dq_b, dq_a->size);
			dq_b_front--;
		}
		else if (dq_a_rear > 0 && dq_b_front <= 0 && dq_b_rear <= 0)
		{
			rra(dq_a, dq_a->size);
			dq_a_rear--;
		}
	}
}

void	merge_desc_2_a(t_deque *dq_a, t_deque *dq_b,int depth, int amt, int *amt_lst, int i)
{
	int k;
	element dq_a_rear;
	element dq_b_front;
	element dq_b_rear;
	k = 0;
	dq_a_rear = amt_lst[0 + i];
	dq_b_front = amt_lst[ft_pow(3, depth - 1) + i];
	dq_b_rear = amt_lst[ft_pow(3, depth) - i - 1];
	// ft_printf("dq_a_rear: %d, dq_b_front: %d, dq_b_rear: %d\n", dq_a_rear, dq_b_front, dq_b_rear);
	while (k++ < amt)
	{
		// ft_printf("dq_a_rear: %d, dq_b_front: %d, dq_b_rear: %d\n", dq_a_rear, dq_b_front, dq_b_rear);
		if (dq_a_rear > 0 && dq_b_front > 0 && dq_b_rear > 0)
		{
			if (!is_rear_bigger_opposite_front(dq_a, dq_b))
			{
				if (!is_rear_bigger_opposite_rear(dq_a, dq_b))
				{
					rra(dq_a, dq_a->size);
					dq_a_rear--;
				}
				else
				{
					rrb(dq_b, dq_b->size);
					pa(dq_a, dq_b, dq_a->size);
					dq_b_rear--;
				}
			}
			else
			{
				if (!is_first_bigger_last(dq_b, dq_b->size))
				{
					pa(dq_a, dq_b, dq_a->size);
					dq_b_front--;
				}
				else
				{
					rrb(dq_b, dq_b->size);
					pa(dq_a, dq_b, dq_a->size);
					dq_b_rear--;
				}
			}
		}
		else if (dq_a_rear <= 0 && dq_b_front > 0 && dq_b_rear > 0)
		{
			if (!is_first_bigger_last(dq_b, dq_b->size))
			{
				pa(dq_a, dq_b, dq_a->size);
				dq_b_front--;
			}
			else
			{
				rrb(dq_b, dq_b->size);
				pa(dq_a, dq_b, dq_a->size);
				dq_b_rear--;
			}
		}
		else if (dq_a_rear > 0 && dq_b_front <= 0 && dq_b_rear > 0)
		{
			if (!is_rear_bigger_opposite_rear(dq_a, dq_b))
			{
				rra(dq_a, dq_a->size);
				dq_a_rear--;
			}
			else
			{
				rrb(dq_b, dq_b->size);
				pa(dq_a, dq_b, dq_a->size);
				dq_b_rear--;
			}
		}
		else if (dq_a_rear > 0 && dq_b_front > 0 && dq_b_rear <= 0)
		{
			if (!is_rear_bigger_opposite_front(dq_a, dq_b))
			{
				rra(dq_a, dq_a->size);
				dq_a_rear--;
			}
			else
			{
				pa(dq_a, dq_b, dq_a->size);
				dq_b_front--;
			}
		}
		else if (dq_a_rear <= 0 && dq_b_front <= 0 && dq_b_rear > 0)
		{
			rrb(dq_b, dq_b->size);
			pa(dq_a, dq_b, dq_a->size);
			dq_b_rear--;
		}
		else if (dq_a_rear <= 0 && dq_b_front > 0 && dq_b_rear <= 0)
		{
			pa(dq_a, dq_b, dq_a->size);
			dq_b_front--;
		}
		else if (dq_a_rear > 0 && dq_b_front <= 0 && dq_b_rear <= 0)
		{
			rra(dq_a, dq_a->size);
			dq_a_rear--;
		}
	}
}

void	merge_triangle_2_a(t_deque *dq_a, t_deque *dq_b, int depth)
{
	int	i;
	int	k;
	int	dir;
	int	amt;
	int	*lst;

	i = 0;
	k = 0;
	lst = make_amt_list(dq_a->size - 1, depth);
	while (k < ft_pow(3, depth) / 3)
	{
		while (i++ < calc_amt(depth, k, dq_a->size - 1))
			pa(dq_a, dq_b, dq_a->size);
		i = 0;
		k++;
	}
	while (i < ft_pow(3, depth - 1))
	{
		dir = calc_dir(depth - 1, i);
		amt = calc_amt(depth - 1, i, dq_a->size - 1);
		ft_printf("dir: %d, amt: %d\n", dir, amt);
		if (dir == 1)
			merge_asc_2_a(dq_a, dq_b, depth, amt, lst, i);
		else
			merge_desc_2_a(dq_a, dq_b, depth, amt, lst, i);
		i++;
	}
	free(lst);
}

void	merge_triangle_2_b(t_deque *dq_a, t_deque *dq_b, int depth)
{
	int	i;
	int	k;
	int	dir;
	int	amt;
	int	*lst;

	i = 0;
	k = 0;
	dir = 0;
	amt = 0;
	lst = make_amt_list(dq_a->size - 1, depth);
	while (k < ft_pow(3, depth) / 3)
	{
		while (i++ < calc_amt(depth, k, dq_a->size - 1))
			pb(dq_a, dq_b, dq_a->size);
		i = 0;
		k++;
	}
	while (i < ft_pow(3, depth - 1))
	{
		dir = calc_dir(depth - 1, i);
		amt = calc_amt(depth - 1, i, dq_a->size - 1);
		if (dir == 1)
			merge_asc_2_b(dq_a, dq_b, depth, amt, lst, i);
		else
			merge_desc_2_b(dq_a, dq_b, depth, amt, lst, i);
		i++;
	}
	free(lst);
}

void	merge(t_deque *dq_a, t_deque *dq_b, int depth)
{
	int	i;

	i = 0;
	// 전 단계의 설계도대로 만들어야됨 그러면 일단 현재 만들어야하는 곳이 a인지 b인지 먼저 판단해야겠지?
	//  만들어야 하는 곳의 위치는 현재 depth - 1이 홀/짝인지 먼저 검사해야겠지?
	//  그 전에 몇개의 삼각형을 만들어야하는지는 어떻게 판단할까?
	//  3의 현재 depth 승이 몇인지 알아야겠지?
	if (depth % 2 == 1)
	{
		while (depth - i > 0)
		{
			if ((depth - i) % 2 == 1)
				merge_triangle_2_a(dq_a, dq_b, depth - i);
			else
				merge_triangle_2_b(dq_a, dq_b, depth - i);
			i++;
		}
	}
	else
	{
		while (depth - i > 0)
		{
			if ((depth - i) % 2 == 1)
				merge_triangle_2_b(dq_a, dq_b, depth - i);
			else
				merge_triangle_2_a(dq_a, dq_b, depth - i);
			i++;
		}

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
	// make_triangular(&dq_a, &dq_b);
	// ft_printf("depth: %d\n", depth);
	// while (i < ft_pow(3, depth))
	//  ft_printf("%d, ", lst[i++]);
	// ft_printf("\n");
	// merge_triangle(&dq_a, &dq_b, depth);
	// while (i < ft_pow(3, depth))
	// {
	//  ft_printf("depth: %d, dir: %d, amt: %d\n", depth , calc_dir(depth , i), calc_amt(depth, i, argc -1));
	//  i++;
	// }
	make_triangular(&dq_a, &dq_b);
	merge(&dq_a,&dq_b,depth);
	// while (i < 3)
	//  pa(&dq_a, &dq_b, dq_a.size);
	// merge_asc_2_a(&dq_a, &dq_b, depth, lst[0], lst, 0);
	return (0);
}

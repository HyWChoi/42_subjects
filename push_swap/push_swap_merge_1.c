#include "push_swap_merge.h"

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

void	merge_desc_2_a(t_deque *dq_a, t_deque *dq_b, int depth, int amt, int *amt_lst, int i)
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
		// ft_printf("dir: %d, amt: %d\n", dir, amt);
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


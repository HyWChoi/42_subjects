#include "push_swap_merge.h"

void	merge_triangle_2_a_even(t_deque *dq_a, t_deque *dq_b, int depth)
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
		dir = !calc_dir(depth - 1, i);
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

void	merge_triangle_2_b_even(t_deque *dq_a, t_deque *dq_b, int depth)
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
		dir = !calc_dir(depth - 1, i);
		amt = calc_amt(depth - 1, i, dq_a->size - 1);
		if (dir == 1)
			merge_asc_2_b(dq_a, dq_b, depth, amt, lst, i);
		else
			merge_desc_2_b(dq_a, dq_b, depth, amt, lst, i);
		i++;
	}
	free(lst);
}

void	merge_triangle(t_deque *dq_a, t_deque *dq_b, int depth)
{
	int	i;

	i = 0;
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
				merge_triangle_2_b_even(dq_a, dq_b, depth - i);
			else
				merge_triangle_2_a_even(dq_a, dq_b, depth - i);
			i++;
		}
	}
}

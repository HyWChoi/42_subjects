/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:00:40 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:05:52 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

void	merge_triangle_2_a_even(t_deque *dq_a, t_deque *dq_b, int depth)
{
	int		i;
	int		k;
	t_merge	merge;

	i = 0;
	k = 0;
	init_merge(&merge, depth, dq_a->size - 1);
	while (k < ft_pow(3, depth) / 3)
	{
		while (i++ < calc_amt(depth, k, dq_a->size - 1))
			pa(dq_a, dq_b, dq_a->size);
		i = 0;
		k++;
	}
	while (i < ft_pow(3, depth - 1))
	{
		merge.dir = !calc_dir(depth - 1, i);
		merge.amt = calc_amt(depth - 1, i, dq_a->size - 1);
		if (merge.dir == 1)
			merge_asc_2_a(dq_a, dq_b, &merge, i);
		else
			merge_desc_2_a(dq_a, dq_b, &merge, i);
		i++;
	}
	free(merge.amt_lst);
}

void	merge_triangle_2_b_even(t_deque *dq_a, t_deque *dq_b, int depth)
{
	int		i;
	int		k;
	t_merge	merge;

	i = 0;
	k = 0;
	init_merge(&merge, depth, dq_a->size - 1);
	while (k < ft_pow(3, depth) / 3)
	{
		while (i++ < calc_amt(depth, k, dq_a->size - 1))
			pb(dq_a, dq_b, dq_a->size);
		i = 0;
		k++;
	}
	while (i < ft_pow(3, depth - 1))
	{
		merge.dir = !calc_dir(depth - 1, i);
		merge.amt = calc_amt(depth - 1, i, dq_a->size - 1);
		if (merge.dir == 1)
			merge_asc_2_b(dq_a, dq_b, &merge, i++);
		else
			merge_desc_2_b(dq_a, dq_b, &merge, i++);
	}
	free(merge.amt_lst);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:24:52 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/04 16:27:10 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

int	check_amt_state(t_amt_count *amt_count)
{
	t_element	dq_a_rear;
	t_element	dq_a_front;
	t_element	dq_b_rear;

	dq_a_rear = amt_count->dq_a_rear;
	dq_a_front = amt_count->dq_a_front;
	dq_b_rear = amt_count->dq_b_rear;
	if (dq_b_rear > 0 && dq_a_front > 0 && dq_a_rear > 0)
		return (1);
	else if (dq_b_rear <= 0 && dq_a_front > 0 && dq_a_rear > 0)
		return (2);
	else if (dq_b_rear > 0 && dq_a_front <= 0 && dq_a_rear > 0)
		return (3);
	else if (dq_b_rear > 0 && dq_a_front > 0 && dq_a_rear <= 0)
		return (4);
	else if (dq_b_rear <= 0 && dq_a_front <= 0 && dq_a_rear > 0)
		return (5);
	else if (dq_b_rear <= 0 && dq_a_front > 0 && dq_a_rear <= 0)
		return (6);
	else if (dq_b_rear > 0 && dq_a_front <= 0 && dq_a_rear <= 0)
		return (7);
	return (0);
}

int	check_amt_state2(t_amt_count_2 *amt_count)
{
	t_element	dq_a_rear;
	t_element	dq_b_front;
	t_element	dq_b_rear;

	dq_a_rear = amt_count->dq_a_rear;
	dq_b_front = amt_count->dq_b_front;
	dq_b_rear = amt_count->dq_b_rear;
	if (dq_a_rear > 0 && dq_b_front > 0 && dq_b_rear > 0)
		return (1);
	else if (dq_a_rear <= 0 && dq_b_front > 0 && dq_b_rear > 0)
		return (2);
	else if (dq_a_rear > 0 && dq_b_front <= 0 && dq_b_rear > 0)
		return (3);
	else if (dq_a_rear > 0 && dq_b_front > 0 && dq_b_rear <= 0)
		return (4);
	else if (dq_a_rear <= 0 && dq_b_front <= 0 && dq_b_rear > 0)
		return (5);
	else if (dq_a_rear <= 0 && dq_b_front > 0 && dq_b_rear <= 0)
		return (6);
	else if (dq_a_rear > 0 && dq_b_front <= 0 && dq_b_rear <= 0)
		return (7);
	return (0);
}

void	merge_triangle_2_a(t_deque *dq_a, t_deque *dq_b, int depth)
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
		merge.dir = calc_dir(depth - 1, i);
		merge.amt = calc_amt(depth - 1, i, dq_a->size - 1);
		if (merge.dir == 1)
			merge_asc_2_a(dq_a, dq_b, &merge, i);
		else
			merge_desc_2_a(dq_a, dq_b, &merge, i);
		i++;
	}
	free(merge.amt_lst);
}

void	merge_triangle_2_b(t_deque *dq_a, t_deque *dq_b, int depth)
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
		merge.dir = calc_dir(depth - 1, i);
		merge.amt = calc_amt(depth - 1, i, dq_a->size - 1);
		if (merge.dir == 1)
			merge_asc_2_b(dq_a, dq_b, &merge, i);
		else
			merge_desc_2_b(dq_a, dq_b, &merge, i);
		i++;
	}
	free(merge.amt_lst);
}

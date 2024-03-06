/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:58:33 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/06 18:51:17 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

int	*make_amt_list(size_t size, int depth)
{
	int	*lst;
	int	i;

	i = 0;
	lst = (int *)malloc(sizeof(int) * ft_pow(3, depth));
	while (i < ft_pow(3, depth))
	{
		lst[i] = calc_amt(depth, i, size);
		i++;
	}
	return (lst);
}

void	init_amt_count(t_amt_count *amt_count, int depth, int *amt_lst, int i)
{
	amt_count->dq_b_rear = amt_lst[0 + i];
	amt_count->dq_a_front = amt_lst[ft_pow(3, depth - 1) + i];
	amt_count->dq_a_rear = amt_lst[ft_pow(3, depth) - i - 1];
}

void	init_amt_count_2(t_amt_count_2 *amt_count, int depth,
							int *amt_lst, int i)
{
	amt_count->dq_a_rear = amt_lst[0 + i];
	amt_count->dq_b_front = amt_lst[ft_pow(3, depth - 1) + i];
	amt_count->dq_b_rear = amt_lst[ft_pow(3, depth) - i - 1];
}

void	init_merge(t_merge *merge, int depth, int amt)
{
	merge->amt_lst = make_amt_list(amt, depth);
	merge->depth = depth;
}

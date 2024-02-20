/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_devide_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:36:21 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/20 19:20:18 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_devide.h"

void	decide_triangular(t_deque *dq_a, t_deque *dq_b, int amt, int dir)
{
	if (dir == 1)
		make_asc_2_b(dq_a, dq_b, amt);
	else
		make_desc_2_b(dq_a, dq_b, amt);
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
		if (depth % 2 == 1)
			dir = calc_dir(depth, i);
		else
			dir = !calc_dir(depth, i);
		amt = calc_amt(depth, i, dq_a->size - 1);
		decide_triangular(dq_a, dq_b, amt, dir);
		i++;
	}
}

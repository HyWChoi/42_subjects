/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_under6_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:48:37 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/06 18:48:38 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_under6.h"

void	size_6(t_deque *dq_a, t_deque *dq_b)
{
	pb(dq_a, dq_b, dq_a->size);
	pb(dq_a, dq_b, dq_a->size);
	pb(dq_a, dq_b, dq_a->size);
	size_3(dq_a);
	size_rev_3(dq_b);
	merge_under_6(dq_a, dq_b);
}

void	is_argc_under_6(t_deque *dq_a, t_deque *dq_b)
{
	if (dq_a->size - 1 == 2)
		size_2(dq_a);
	else if (dq_a->size - 1 == 3)
		size_3(dq_a);
	else if (dq_a->size - 1 == 4)
		size_4(dq_a, dq_b);
	else if (dq_a->size - 1 == 5)
		size_5(dq_a, dq_b);
	else if (dq_a->size - 1 == 6)
		size_6(dq_a, dq_b);
}

void	merge_under_6(t_deque *dq_a, t_deque *dq_b)
{
	size_t	count;
	size_t	count_a;
	size_t	count_b;

	count_a = count_dq(dq_a, dq_a->size);
	count_b = count_dq(dq_b, dq_b->size);
	count = 0;
	while (count++ < dq_a->size - 1)
	{
		decide_move_under_6(&count_a, &count_b, dq_a, dq_b);
	}
}

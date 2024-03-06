/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_under6_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:48:31 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/06 18:48:32 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_under6.h"

void	size_2(t_deque *dq_a)
{
	if (is_first_bigger_second(dq_a, dq_a->size))
		sa(dq_a, dq_a->size);
}

void	size_rev_3(t_deque *dq_b)
{
	if (is_sorted_desc(dq_b, count_dq(dq_b, dq_b->size)))
		return ;
	sort_rev_first(dq_b);
	if (is_sorted_desc(dq_b, count_dq(dq_b, dq_b->size)))
		return ;
	sort_rev_second(dq_b);
}

void	size_3(t_deque *dq_a)
{
	if (is_sorted_asc(dq_a, count_dq(dq_a, dq_a->size)))
		return ;
	sort_first(dq_a);
	if (is_sorted_asc(dq_a, count_dq(dq_a, dq_a->size)))
		return ;
	sort_second(dq_a);
}

void	size_4(t_deque *dq_a, t_deque *dq_b)
{
	pb(dq_a, dq_b, dq_a->size);
	size_3(dq_a);
	merge_under_6(dq_a, dq_b);
}

void	size_5(t_deque *dq_a, t_deque *dq_b)
{
	pb(dq_a, dq_b, dq_a->size);
	pb(dq_a, dq_b, dq_a->size);
	size_3(dq_a);
	if (!is_first_bigger_last(dq_b, dq_b->size))
		sb(dq_b, dq_b->size);
	merge_under_6(dq_a, dq_b);
}

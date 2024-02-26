/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:01:17 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:21:37 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

void	action_desc_1(t_deque *dq_a, t_deque *dq_b, int *dq_b_rear)
{
	rrb(dq_b, dq_a->size);
	(*dq_b_rear)--;
}

void	action_desc_2(t_deque *dq_a, t_deque *dq_b, int *dq_a_rear)
{
	rra(dq_a, dq_a->size);
	pb(dq_a, dq_b, dq_a->size);
	(*dq_a_rear)--;
}

void	action_desc_3(t_deque *dq_a, t_deque *dq_b, int *dq_a_front)
{
	pb(dq_a, dq_b, dq_a->size);
	(*dq_a_front)--;
}

void	decide_and_act_desc_1(t_deque *dq_a, t_deque *dq_b,
								t_amt_count *amt_count)
{
	int	condition;

	if (!is_rear_bigger_opposite_front(dq_b, dq_a))
	{
		if (!is_rear_bigger_opposite_rear(dq_b, dq_a))
			condition = 1;
		else
			condition = 2;
	}
	else
	{
		if (!is_first_bigger_last(dq_a, dq_a->size))
			condition = 3;
		else
			condition = 2;
	}
	if (condition == 1)
		action_desc_1(dq_a, dq_b, &amt_count->dq_b_rear);
	else if (condition == 2)
		action_desc_2(dq_a, dq_b, &amt_count->dq_a_rear);
	else if (condition == 3)
		action_desc_3(dq_a, dq_b, &amt_count->dq_a_front);
}

void	decide_and_act_desc_2(t_deque *dq_a, t_deque *dq_b,
								t_amt_count *amt_count)
{
	if (!is_first_bigger_last(dq_a, dq_a->size))
		action_desc_3(dq_a, dq_b, &amt_count->dq_a_front);
	else
		action_desc_2(dq_a, dq_b, &amt_count->dq_a_rear);
}
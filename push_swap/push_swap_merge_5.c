/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:23:17 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:23:18 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

void	action_desc_a_1(t_deque *dq_a, t_deque *dq_b, int *dq_a_rear)
{
	rra(dq_a, dq_b->size);
	(*dq_a_rear)--;
}

void	action_desc_a_2(t_deque *dq_a, t_deque *dq_b, int *dq_b_rear)
{
	rrb(dq_b, dq_b->size);
	pa(dq_a, dq_b, dq_a->size);
	(*dq_b_rear)--;
}

void	action_desc_a_3(t_deque *dq_a, t_deque *dq_b, int *dq_b_front)
{
	pa(dq_a, dq_b, dq_a->size);
	(*dq_b_front)--;
}

void	decide_and_act_desc_a_1(t_deque *dq_a, t_deque *dq_b,
								t_amt_count_2 *amt_count)
{
	int	condition;

	if (!is_rear_bigger_opposite_front(dq_a, dq_b))
	{
		if (!is_rear_bigger_opposite_rear(dq_a, dq_b))
			condition = 1;
		else
			condition = 2;
	}
	else
	{
		if (!is_first_bigger_last(dq_b, dq_b->size))
			condition = 3;
		else
			condition = 2;
	}
	if (condition == 1)
		action_desc_a_1(dq_a, dq_b, &amt_count->dq_a_rear);
	else if (condition == 2)
		action_desc_a_2(dq_a, dq_b, &amt_count->dq_b_rear);
	else if (condition == 3)
		action_desc_a_3(dq_a, dq_b, &amt_count->dq_b_front);
}

void	decide_and_act_desc_a_2(t_deque *dq_a, t_deque *dq_b,
								t_amt_count_2 *amt_count)
{
	if (!is_first_bigger_last(dq_b, dq_b->size))
		action_desc_a_3(dq_a, dq_b, &amt_count->dq_b_front);
	else
		action_desc_a_2(dq_a, dq_b, &amt_count->dq_b_rear);
}

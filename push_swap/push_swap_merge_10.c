/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:23:17 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/04 18:23:52 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

void	action_desc_a_1(t_deque *dq_a, t_deque *dq_b, int *dq_a_rear, int *flag)
{
	if (*flag == 1)
		ft_printf("rra\n");
	rra(dq_a, dq_b->size);
	(*dq_a_rear)--;
	*flag = 1;
}

void	action_desc_a_2(t_deque *dq_a, t_deque *dq_b, int *dq_b_rear, int *flag)
{
	if (*flag == 1)
	{
		rrb(dq_b, dq_b->size);
		ft_printf("rrr\n");
	}
	else
	{
		ft_printf("rrb\n");
		rrb(dq_b, dq_b->size);
	}
	pa(dq_a, dq_b, dq_a->size);
	*flag = 0;
	(*dq_b_rear)--;
}

void	action_desc_a_3(t_deque *dq_a, t_deque *dq_b, int *dq_b_front,
						int *flag)
{
	if (*flag == 1)
		ft_printf("rra\n");
	pa(dq_a, dq_b, dq_a->size);
	*flag = 0;
	(*dq_b_front)--;
}

void	decide_and_act_desc_a_1(t_deque *dq_a, t_deque *dq_b,
								t_amt_count_2 *amt_count, int *flag)
{
	if (!is_rear_bigger_opposite_front(dq_a, dq_b))
	{
		if (!is_rear_bigger_opposite_rear(dq_a, dq_b))
			action_desc_a_1(dq_a, dq_b, &amt_count->dq_a_rear, flag);
		else
			action_desc_a_2(dq_a, dq_b, &amt_count->dq_b_rear, flag);
	}
	else
	{
		if (!is_first_bigger_last(dq_b, dq_b->size))
			action_desc_a_3(dq_a, dq_b, &amt_count->dq_b_front, flag);
		else
			action_desc_a_2(dq_a, dq_b, &amt_count->dq_b_rear, flag);
	}
}

void	decide_and_act_desc_a_2(t_deque *dq_a, t_deque *dq_b,
								t_amt_count_2 *amt_count, int *flag)
{
	if (!is_first_bigger_last(dq_b, dq_b->size))
		action_desc_a_3(dq_a, dq_b, &amt_count->dq_b_front, flag);
	else
		action_desc_a_2(dq_a, dq_b, &amt_count->dq_b_rear, flag);
}

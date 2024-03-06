/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:01:17 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/06 18:51:26 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

void	decide_and_act_desc_3(t_deque *dq_a, t_deque *dq_b,
								t_amt_count *amt_count, int *flag)
{
	if (!is_rear_bigger_opposite_rear(dq_b, dq_a))
		action_desc_1(dq_a, dq_b, &amt_count->dq_b_rear, flag);
	else
		action_desc_2(dq_a, dq_b, &amt_count->dq_a_rear, flag);
}

void	decide_and_act_desc_4(t_deque *dq_a, t_deque *dq_b,
								t_amt_count *amt_count, int *flag)
{
	if (!is_rear_bigger_opposite_front(dq_b, dq_a))
		action_desc_1(dq_a, dq_b, &amt_count->dq_b_rear, flag);
	else
		action_desc_3(dq_a, dq_b, &amt_count->dq_a_front, flag);
}

void	merge_desc_2_b(t_deque *dq_a, t_deque *dq_b,
						t_merge *merge, int i)
{
	t_amt_count	amt_count;
	int			k;
	int			flag;

	k = 0;
	flag = 0;
	init_amt_count(&amt_count, merge->depth, merge->amt_lst, i);
	while (k++ < merge->amt)
	{
		if (check_amt_state(&amt_count) == 1)
			decide_and_act_desc_1(dq_a, dq_b, &amt_count, &flag);
		else if (check_amt_state(&amt_count) == 2)
			decide_and_act_desc_2(dq_a, dq_b, &amt_count, &flag);
		else if (check_amt_state(&amt_count) == 3)
			decide_and_act_desc_3(dq_a, dq_b, &amt_count, &flag);
		else if (check_amt_state(&amt_count) == 4)
			decide_and_act_desc_4(dq_a, dq_b, &amt_count, &flag);
		else if (check_amt_state(&amt_count) == 5)
			action_desc_2(dq_a, dq_b, &amt_count.dq_a_rear, &flag);
		else if (check_amt_state(&amt_count) == 6)
			action_desc_3(dq_a, dq_b, &amt_count.dq_a_front, &flag);
		else if (check_amt_state(&amt_count) == 7)
			action_desc_1(dq_a, dq_b, &amt_count.dq_b_rear, &flag);
	}
	chk_flag_rrb(&flag);
}

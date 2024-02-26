/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_4.5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:22:00 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:22:01 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

void	decide_and_act_asc_a_3(t_deque *dq_a, t_deque *dq_b,
								t_amt_count_2 *amt_count)
{
	if (is_rear_bigger_opposite_rear(dq_a, dq_b))
		action_asc_a_1(dq_a, dq_b, &amt_count->dq_a_rear);
	else
		action_asc_a_2(dq_a, dq_b, &amt_count->dq_b_rear);
}

void	decide_and_act_asc_a_4(t_deque *dq_a, t_deque *dq_b,
								t_amt_count_2 *amt_count)
{
	if (is_rear_bigger_opposite_front(dq_a, dq_b))
		action_asc_a_1(dq_a, dq_b, &amt_count->dq_a_rear);
	else
		action_asc_a_3(dq_a, dq_b, &amt_count->dq_b_front);
}

void	merge_asc_2_a(t_deque *dq_a, t_deque *dq_b, t_merge *merge, int i)
{
	t_amt_count_2	amt_count;
	int				k;

	k = 0;
	init_amt_count_2(&amt_count, merge->depth, merge->amt_lst, i);
	while (k++ < merge->amt)
	{
		if (check_amt_state2(&amt_count) == 1)
			decide_and_act_asc_a_1(dq_a, dq_b, &amt_count);
		else if (check_amt_state2(&amt_count) == 2)
			decide_and_act_asc_a_2(dq_a, dq_b, &amt_count);
		else if (check_amt_state2(&amt_count) == 3)
			decide_and_act_asc_a_3(dq_a, dq_b, &amt_count);
		else if (check_amt_state2(&amt_count) == 4)
			decide_and_act_asc_a_4(dq_a, dq_b, &amt_count);
		else if (check_amt_state2(&amt_count) == 5)
			action_asc_a_2(dq_a, dq_b, &amt_count.dq_b_rear);
		else if (check_amt_state2(&amt_count) == 6)
			action_asc_a_3(dq_a, dq_b, &amt_count.dq_b_front);
		else if (check_amt_state2(&amt_count) == 7)
			action_asc_a_1(dq_a, dq_b, &amt_count.dq_a_rear);
	}
}

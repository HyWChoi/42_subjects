/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge_2.5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:00:43 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/04 18:24:03 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

void	decide_and_act_asc_3(t_deque *dq_a, t_deque *dq_b,
					t_amt_count *amt_count, int *flag)
{
	if (is_rear_bigger_opposite_rear(dq_b, dq_a))
		action_asc_1(dq_a, dq_b, &amt_count->dq_b_rear, flag);
	else
		action_asc_2(dq_a, dq_b, &amt_count->dq_a_rear, flag);
}

void	decide_and_act_asc_4(t_deque *dq_a, t_deque *dq_b,
					t_amt_count *amt_count, int *flag)
{
	if (is_rear_bigger_opposite_front(dq_b, dq_a))
		action_asc_1(dq_a, dq_b, &amt_count->dq_b_rear, flag);
	else
		action_asc_3(dq_a, dq_b, &amt_count->dq_a_front, flag);
}

void	chk_flag_rrb(int *flag)
{
	if (*flag == 1)
		ft_printf("rrb\n");
}

void	merge_asc_2_b(t_deque *dq_a, t_deque *dq_b, t_merge *merge, int i)
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
			decide_and_act_asc_1(dq_a, dq_b, &amt_count, &flag);
		else if (check_amt_state(&amt_count) == 2)
			decide_and_act_asc_2(dq_a, dq_b, &amt_count, &flag);
		else if (check_amt_state(&amt_count) == 3)
			decide_and_act_asc_3(dq_a, dq_b, &amt_count, &flag);
		else if (check_amt_state(&amt_count) == 4)
			decide_and_act_asc_4(dq_a, dq_b, &amt_count, &flag);
		else if (check_amt_state(&amt_count) == 5)
			action_asc_2(dq_a, dq_b, &amt_count.dq_a_rear, &flag);
		else if (check_amt_state(&amt_count) == 6)
			action_asc_3(dq_a, dq_b, &amt_count.dq_a_front, &flag);
		else if (check_amt_state(&amt_count) == 7)
			action_asc_1(dq_a, dq_b, &amt_count.dq_b_rear, &flag);
	}
	chk_flag_rrb(&flag);
}

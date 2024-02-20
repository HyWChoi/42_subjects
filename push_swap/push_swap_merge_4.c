#include "push_swap_merge.h"

void action_asc_a_1(t_deque *dq_a, t_deque *dq_b, int *dq_a_rear)
{
	rra(dq_a, dq_b->size);
	(*dq_a_rear)--;
}

void action_asc_a_2(t_deque *dq_a, t_deque *dq_b, int *dq_b_rear)
{
	rrb(dq_b, dq_b->size);
	pa(dq_a, dq_b, dq_a->size);
	(*dq_b_rear)--;
}

void action_asc_a_3(t_deque *dq_a, t_deque *dq_b, int *dq_b_front)
{
	pa(dq_a, dq_b, dq_a->size);
	(*dq_b_front)--;
}

void decide_and_act_asc_a(t_deque *dq_a, t_deque *dq_b, int *dq_a_rear, int *dq_b_front, int *dq_b_rear)
{
	int condition;

	if (is_rear_bigger_opposite_front(dq_a, dq_b))
	{
		if (is_rear_bigger_opposite_rear(dq_a, dq_b))
			condition = 1;
		else
			condition = 2;
	}
	else
	{
		if (is_first_bigger_last(dq_b, dq_b->size))
			condition = 3;
		else
			condition = 2;
	}

	if (condition == 1)
		action_asc_a_1(dq_a, dq_b, dq_a_rear);
	else if (condition == 2)
		action_asc_a_2(dq_a, dq_b, dq_b_rear);
	else if (condition == 3)
		action_asc_a_3(dq_a, dq_b, dq_b_front);
}

void merge_asc_2_a(t_deque *dq_a, t_deque *dq_b, t_merge *merge, int i)
{
	int		k;
	t_amt_count_2 amt_count;

	k = 0;
	init_amt_count_2(&amt_count, merge->depth, merge->amt_lst, i);
	while (k++ < merge->amt)
	{
		if (check_amt_state2(&amt_count) == 1)
			decide_and_act_asc_a(dq_a, dq_b, &amt_count.dq_a_rear,
					&amt_count.dq_b_front, &amt_count.dq_b_rear);
		else if (check_amt_state2(&amt_count) == 2)
			action_asc_a_2(dq_a, dq_b, &amt_count.dq_b_rear);
		else if (check_amt_state2(&amt_count) == 3)
			action_asc_a_1(dq_a, dq_b, &amt_count.dq_a_rear);
		else if (check_amt_state2(&amt_count) == 4)
			action_asc_a_3(dq_a, dq_b, &amt_count.dq_b_front);
		else if (check_amt_state2(&amt_count) == 5)
			action_asc_a_2(dq_a, dq_b, &amt_count.dq_b_rear);
		else if (check_amt_state2(&amt_count) == 6)
			action_asc_a_3(dq_a, dq_b, &amt_count.dq_b_front);
		else if (check_amt_state2(&amt_count) == 7)
			action_asc_a_1(dq_a, dq_b, &amt_count.dq_a_rear);
	}
}

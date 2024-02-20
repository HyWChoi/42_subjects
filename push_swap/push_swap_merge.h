#ifndef PUSH_SWAP_MERGE_H
# define PUSH_SWAP_MERGE_H
# include "push_swap_devide.h"

typedef struct s_merge
{
	int		*amt_lst;
	int		amt;
	int		dir;
	int		depth;
}	t_merge;

typedef struct s_amt_count
{
	element	dq_b_rear;
	element	dq_a_front;
	element	dq_a_rear;
}	t_amt_count;

typedef struct s_amt_count_2
{
	element	dq_a_rear;
	element	dq_b_front;
	element	dq_b_rear;
}	t_amt_count_2;

int		*make_amt_list(size_t size , int depth);
void	init_amt_count(t_amt_count *amt_count, int depth, int *amt_lst, int i);
void	init_amt_count_2(t_amt_count_2 *amt_count, int depth, int *amt_lst, int i);
void	init_merge(t_merge *merge, int depth, int amt);
void	action_asc_1(t_deque *dq_a, t_deque *dq_b, int *dq_b_rear);
void	action_asc_2(t_deque *dq_a, t_deque *dq_b, int *dq_a_rear);
void	action_asc_3(t_deque *dq_a, t_deque *dq_b, int *dq_a_front);
void	decide_and_act_asc(t_deque *dq_a, t_deque *dq_b, int *dq_a_front, int *dq_a_rear, int *dq_b_rear);
void	merge_asc_2_b(t_deque *dq_a, t_deque *dq_b, t_merge *merge, int i);
void	action_desc_1(t_deque *dq_a, t_deque *dq_b, int *dq_b_rear);
void	action_desc_2(t_deque *dq_a, t_deque *dq_b, int *dq_a_rear);
void	action_desc_3(t_deque *dq_a, t_deque *dq_b, int *dq_a_front);
void	decide_and_act_desc(t_deque *dq_a, t_deque *dq_b, int *dq_a_front, int *dq_a_rear, int *dq_b_rear);
void	merge_desc_2_b(t_deque *dq_a, t_deque *dq_b, t_merge *merge, int i);
void	action_asc_a_1(t_deque *dq_a, t_deque *dq_b, int *dq_a_rear);
void	action_asc_a_2(t_deque *dq_a, t_deque *dq_b, int *dq_b_rear);
void	action_asc_a_3(t_deque *dq_a, t_deque *dq_b, int *dq_b_front);
void	decide_and_act_asc_a(t_deque *dq_a, t_deque *dq_b, int *dq_a_rear, int *dq_b_front, int *dq_b_rear);
void	merge_asc_2_a(t_deque *dq_a, t_deque *dq_b, t_merge *merge, int i);
void	action_desc_a_1(t_deque *dq_a, t_deque *dq_b, int *dq_a_rear);
void	action_desc_a_2(t_deque *dq_a, t_deque *dq_b, int *dq_b_rear);
void	action_desc_a_3(t_deque *dq_a, t_deque *dq_b, int *dq_b_front);
void	decide_and_act_desc_a(t_deque *dq_a, t_deque *dq_b, int *dq_a_rear, int *dq_b_front, int *dq_b_rear);
void	merge_desc_2_a(t_deque *dq_a, t_deque *dq_b, t_merge *merge, int i);
int		check_amt_state(t_amt_count *amt_count);
int		check_amt_state2(t_amt_count_2 *amt_count);
void	merge_triangle_2_a(t_deque *dq_a, t_deque *dq_b, int depth);
void	merge_triangle_2_b(t_deque *dq_a, t_deque *dq_b, int depth);
void	merge_triangle_2_a_even(t_deque *dq_a, t_deque *dq_b, int depth);
void	merge_triangle_2_b_even(t_deque *dq_a, t_deque *dq_b, int depth);
void	merge_triangle(t_deque *dq_a, t_deque *dq_b, int depth);
#endif

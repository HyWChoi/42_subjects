#ifndef PUSH_SWAP_MERGE_H
# define PUSH_SWAP_MERGE_H
# include "push_swap_devide.h"

int		*make_amt_list(size_t size , int depth);
void	merge_asc_2_b(t_deque *dq_a, t_deque *dq_b,int depth, int amt, int *amt_lst, int i);
void	merge_desc_2_b(t_deque *dq_a, t_deque *dq_b,int depth, int amt, int *amt_lst, int i);
void	merge_asc_2_a(t_deque *dq_a, t_deque *dq_b,int depth, int amt, int *amt_lst, int i);
void	merge_desc_2_a(t_deque *dq_a, t_deque *dq_b,int depth, int amt, int *amt_lst, int i);
void	merge_triangle_2_a(t_deque *dq_a, t_deque *dq_b, int depth);
void	merge_triangle_2_b(t_deque *dq_a, t_deque *dq_b, int depth);
void	merge_triangle_2_a_even(t_deque *dq_a, t_deque *dq_b, int depth);
void	merge_triangle_2_b_even(t_deque *dq_a, t_deque *dq_b, int depth);
void	merge_triangle(t_deque *dq_a, t_deque *dq_b, int depth);
#endif

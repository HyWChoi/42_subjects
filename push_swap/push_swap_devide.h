#ifndef PUSH_SWAP_DEVIDE_H
# define PUSH_SWAP_DEVIDE_H
# include "push_swap_calcs.h"

int		get_max_index_index_with_limit(t_deque *dq, int amt, element limit);
int		get_max_index(t_deque *dq, int amt);
int		get_min_index_with_limit(t_deque *dq, int amt, element limit);
int		get_min_index(t_deque *dq, int amt);
boolean	is_closer_front(t_deque *dq, int value_index);
int		count_moves_with_value(t_deque *dq, int value_index);
void	make_asc_2_b(t_deque *dq_a, t_deque *dq_b, int amt);
void	make_desc_2_b(t_deque *dq_a, t_deque *dq_b, int amt);
void	decide_triangular(t_deque *dq_a, t_deque *dq_b, int amt, int dir);
void	make_triangular(t_deque *dq_a, t_deque *dq_b);
void	rotate_and_push(t_deque *dq_a, t_deque *dq_b, int move, int target);
void	move_elements(t_deque *dq_a, t_deque *dq_b, int move, int target);
#endif

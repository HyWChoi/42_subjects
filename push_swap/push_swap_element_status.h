#ifndef PUSH_SWAP_ELEMENT_SATUS_H
# define PUSH_SWAP_ELEMENT_SATUS_H
# include "push_swap_checker.h"

int	is_first_bigger_second(t_deque *dq, size_t size);
int	is_first_bigger_last(t_deque *dq, size_t size);
int	is_second_bigger_last(t_deque *dq, size_t size);
boolean	is_sorted_desc1(t_deque *dq, int amt);
boolean	is_sorted_asc1(t_deque *dq, int amt);
boolean	is_rear_bigger_opposite_rear(t_deque *dq, t_deque *opposite);
boolean	is_rear_bigger_opposite_front(t_deque *dq, t_deque *opposite);
#endif

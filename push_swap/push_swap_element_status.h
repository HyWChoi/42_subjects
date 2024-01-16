#ifndef PUSH_SWAP_ELEMENT_SATUS_H
# define PUSH_SWAP_ELEMENT_SATUS_H
# include "push_swap_checker.h"

int		is_first_bigger_second(t_deque *dq, size_t size);
int		is_first_bigger_last(t_deque *dq, size_t size);
void	push_element(t_deque *start, t_deque *destination, size_t size, void f(t_deque *dq_a, t_deque *dq_b, size_t size));

#endif

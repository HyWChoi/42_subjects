#ifndef PUSH_SWAP_MERGE_H
# define PUSH_SWAP_MERGE_H
# include "push_swap_element_status.h"

void    push_asc_a2b(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
void    push_asc_b2a(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
void    push_desc_a2b(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
void    push_desc_b2a(t_deque *dq_a, t_deque *dq_b, size_t size, size_t target_size);
void    make_triangles_a2b(t_deque *dq_a, t_deque *dq_b, size_t size);
void    make_triangles_b2a(t_deque *dq_a, t_deque *dq_b, size_t size);
void	divide_triangle(t_deque *start, t_deque *dest, size_t size, int depth);
#endif

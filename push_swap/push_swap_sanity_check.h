#ifndef PUSH_SWAP_SANITY_CHECK_H
# define PUSH_SWAP_SANITY_CHECK_H
# include "watch_deque.h"

int		ft_atoi_push_swap(char *str, t_deque *dq_a, t_deque *dq_b);
int		ft_is_number(char *str);
void	error_exit(t_deque *dq_a, t_deque *dq_b);

#endif

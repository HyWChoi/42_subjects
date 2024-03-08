/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_under6.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:48:40 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/06 19:04:05 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UNDER6_H
# define PUSH_SWAP_UNDER6_H
# include "push_swap_merge.h"

void	size_2(t_deque *dq_a);
void	sort_first(t_deque *dq_a);
void	sort_second(t_deque *dq_a);
void	size_3(t_deque *dq_a);
void	sort_rev_first(t_deque *dq_b);
void	sort_rev_second(t_deque *dq_b);
void	size_rev_3(t_deque *dq_b);
void	decide_move_under_6(size_t *count_a, size_t *count_b,
			t_deque *dq_a, t_deque *dq_b);
void	merge_under_6(t_deque *dq_a, t_deque *dq_b);
void	size_4(t_deque *dq_a, t_deque *dq_b);
void	size_5(t_deque *dq_a, t_deque *dq_b);
void	size_6(t_deque *dq_a, t_deque *dq_b);
void	is_argc_under_6(t_deque *dq_a, t_deque *dq_b);

#endif

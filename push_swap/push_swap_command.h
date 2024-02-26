/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:43:32 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:43:33 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_COMMAND_H
# define PUSH_SWAP_COMMAND_H
# include "push_swap_deque.h"

void	sa(t_deque *dq_a, size_t size);
void	sb(t_deque *dq_b, size_t size);
void	ss(t_deque *dq_a, t_deque *dq_b, size_t size);
void	pa(t_deque *dq_a, t_deque *dq_b, size_t size);
void	pb(t_deque *dq_a, t_deque *dq_b, size_t size);
void	ra(t_deque *dq_a, size_t size);
void	rb(t_deque *dq_b, size_t size);
void	rr(t_deque *dq_a, t_deque *dq_b, size_t size);
void	rra(t_deque *dq_a, size_t size);
void	rrb(t_deque *dq_b, size_t size);
void	rrr(t_deque *dq_a, t_deque *dq_b, size_t size);

#endif

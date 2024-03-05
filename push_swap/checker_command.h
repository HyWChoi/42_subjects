/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_command.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:43:32 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/05 21:00:37 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_COMMAND_H
# define CHECKER_COMMAND_H
# include "push_swap_deque.h"

void	checker_sa(t_deque *dq_a, size_t size);
void	checker_sb(t_deque *dq_b, size_t size);
void	checker_pa(t_deque *dq_a, t_deque *dq_b, size_t size);
void	checker_pb(t_deque *dq_a, t_deque *dq_b, size_t size);
void	checker_ra(t_deque *dq_a, size_t size);
void	checker_rb(t_deque *dq_b, size_t size);
void	checker_rra(t_deque *dq_a, size_t size);
void	checker_rrb(t_deque *dq_b, size_t size);
void	checker_rrr(t_deque *dq_a, t_deque *dq_b, size_t size);

#endif

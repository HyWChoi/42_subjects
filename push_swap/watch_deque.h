/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_deque.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:28:04 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:28:05 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATCH_DEQUE_H
# define WATCH_DEQUE_H
# include "push_swap_command.h"

void	watch_dq_a_state(t_deque *a, size_t size);
void	watch_dq_b_state(t_deque *b, size_t size);
void	watch_dq_a_b_state(t_deque *a, t_deque *b, size_t size);

#endif

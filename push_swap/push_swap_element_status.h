/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_element_status.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:35:42 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:40:47 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ELEMENT_STATUS_H
# define PUSH_SWAP_ELEMENT_STATUS_H
# include "push_swap_checker.h"

int			is_first_bigger_second(t_deque *dq, size_t size);
int			is_first_bigger_last(t_deque *dq, size_t size);
int			is_second_bigger_last(t_deque *dq, size_t size);
t_boolean	is_sorted_desc1(t_deque *dq, int amt);
t_boolean	is_sorted_asc1(t_deque *dq, int amt);
t_boolean	is_rear_bigger_opposite_rear(t_deque *dq, t_deque *opposite);
t_boolean	is_rear_bigger_opposite_front(t_deque *dq, t_deque *opposite);
#endif

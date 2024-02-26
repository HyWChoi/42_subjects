/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:43:39 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:51:05 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H
# include "push_swap_sanity_check.h"

t_boolean	checker(t_deque *dq_a, t_deque *dq_b);
t_boolean	is_sorted_asc(t_deque *dq, size_t size);
t_boolean	is_sorted_desc(t_deque *dq, size_t size);
#endif

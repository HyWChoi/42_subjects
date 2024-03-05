/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_command_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:48:29 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/05 16:40:17 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_command.h"

void	checker_ra(t_deque *dq_a, size_t size)
{
	push_rear(dq_a, pop_front(dq_a, size), size);
}

void	checker_rb(t_deque *dq_b, size_t size)
{
	push_rear(dq_b, pop_front(dq_b, size), size);
}

void	checker_rra(t_deque *dq_a, size_t size)
{
	push_front(dq_a, pop_rear(dq_a, size), size);
}

void	checker_rrb(t_deque *dq_b, size_t size)
{
	push_front(dq_b, pop_rear(dq_b, size), size);
}

void	checker_rrr(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	checker_rra(dq_a, size);
	checker_rrb(dq_b, size);
}

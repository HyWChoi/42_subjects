/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:48:29 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/04 18:24:44 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_command.h"

void	ra(t_deque *dq_a, size_t size)
{
	push_rear(dq_a, pop_front(dq_a, size), size);
	ft_printf("ra\n");
}

void	rb(t_deque *dq_b, size_t size)
{
	push_rear(dq_b, pop_front(dq_b, size), size);
	ft_printf("rb\n");
}

void	rr(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	ra(dq_a, size);
	rb(dq_b, size);
	ft_printf("rr\n");
}

void	rra(t_deque *dq_a, size_t size)
{
	push_front(dq_a, pop_rear(dq_a, size), size);
}

void	rrb(t_deque *dq_b, size_t size)
{
	push_front(dq_b, pop_rear(dq_b, size), size);
}

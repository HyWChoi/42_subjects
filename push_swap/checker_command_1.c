/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_command_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:48:09 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/12 14:45:46 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_command.h"

void	checker_sa(t_deque *dq_a, size_t size)
{
	t_element	temp;

	temp = dq_a->data[(dq_a->front + 1) % size];
	dq_a->data[(dq_a->front + 1) % size] = dq_a->data[(dq_a->front + 2) % size];
	dq_a->data[(dq_a->front + 2) % size] = temp;
}

void	checker_sb(t_deque *dq_b, size_t size)
{
	t_element	temp;

	temp = dq_b->data[(dq_b->front + 1) % size];
	dq_b->data[(dq_b->front + 1) % size] = dq_b->data[(dq_b->front + 2) % size];
	dq_b->data[(dq_b->front + 2) % size] = temp;
}

void	checker_ss(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	checker_sa(dq_a, size);
	checker_sb(dq_b, size);
}

void	checker_pa(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	push_front(dq_a, pop_front(dq_b, size), size);
}

void	checker_pb(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	push_front(dq_b, pop_front(dq_a, size), size);
}

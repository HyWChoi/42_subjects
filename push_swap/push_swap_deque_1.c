/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:13:12 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:38:15 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_deque.h"

void	init_deque(t_deque *dq, size_t size)
{
	dq->data = (t_element *)malloc(sizeof(t_element) * size);
	dq->size = size;
	dq->front = 0;
	dq->rear = 0;
}

t_boolean	is_empty(t_deque *dq)
{
	return (dq->front == dq->rear);
}

t_boolean	is_full(t_deque *dq, size_t size)
{
	return ((dq->rear + 1) % size == dq->front);
}

void	push_front(t_deque *dq, int num, size_t size)
{
	if (is_full(dq, size))
		return ;
	dq->data[dq->front] = num;
	dq->front = (dq->front - 1 + size) % size;
}

void	push_rear(t_deque *dq, int num, size_t size)
{
	if (is_full(dq, size))
		return ;
	dq->rear = (dq->rear + 1) % size;
	dq->data[dq->rear] = num;
}

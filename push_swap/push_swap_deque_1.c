/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:13:12 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/01/10 20:01:47 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_deque.h"

void	init_deque(t_deque *dq, size_t size)
{
	dq->data = (element*)malloc(sizeof(element) * size);
	dq->front = 0;
	dq->rear = 0;
}

boolean is_empty(t_deque *dq)
{
	return (dq->front == dq->rear);
}

boolean	is_full(t_deque *dq, size_t size)
{
	return ((dq->rear + 1) % size == dq->front);
}

element get_rear(t_deque *dq)
{
	if (is_empty(dq))
	{
		ft_printf("This t_deque is full");
		return (ERROR);
	}
	return (dq->data[dq->rear]);
}

void	push_front(t_deque *dq, int num, size_t size)
{
	if (is_full(dq, size))
	{
		ft_printf("que is full");
		return ;
	}
	dq->data[dq->front] = num;
	dq->front = (dq->front - 1 + size) % size;
}

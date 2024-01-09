/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:13:12 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/01/09 20:06:00 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_deque *dq)
{
	dq->data = (element*)malloc(sizeof(element));
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
	dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
	dq->data[dq->front] = num;
}

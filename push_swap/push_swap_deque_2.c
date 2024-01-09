/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:14:20 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/01/09 20:05:51 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_rear(t_deque *dq, int num, size_t size)
{
	if (is_full(dq, size))
	{
		ft_printf("que is full");
		return ;
	}
	dq->rear = (dq->rear + 1) % MAX_SIZE;
	dq->data[dq->rear] = num;
}

element	pop_front(t_deque *dq)
{
	element tmp;

	if (is_empty(dq))
	{
		ft_printf("que is empty");
		return (ERROR);
	}
	tmp = dq->data[(dq->front + 1) % MAX_SIZE];
	dq->front = (dq->front + 1) % MAX_SIZE;
	return (tmp);
}

element	pop_rear(t_deque *dq)
{
	element tmp;

	if (is_empty(dq))
	{
		ft_printf("que is empty");
		return (ERROR);
	}
	tmp = dq->data[dq->rear];
	dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
	return (tmp);
}

void	print_dq(t_deque *dq)
{
	int i;

	i = dq->front;
	ft_printf("t_deque(fornt = %d rear= %d)=", dq->front, dq->rear);
	if (is_empty(dq))
	{
		ft_printf("que is empty");
		return ;
	}
	while (i != dq->rear)
	{
		ft_printf("%d |", dq->data[i]);
		i = (i + 1) % MAX_SIZE;
	}
	ft_printf("%d\n", dq->data[i]);
}

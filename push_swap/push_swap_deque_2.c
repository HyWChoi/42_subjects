/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:14:20 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/01/10 20:09:51 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_deque.h"

void	push_rear(t_deque *dq, int num, size_t size)
{
	if (is_full(dq, size))
	{
		ft_printf("que is full");
		return ;
	}
	dq->rear = (dq->rear + 1) % size;
	dq->data[dq->rear] = num;
}

element	pop_front(t_deque *dq, size_t size)
{
	element tmp;

	if (is_empty(dq))
	{
		ft_printf("que is empty");
		return (ERROR);
	}
	tmp = dq->data[(dq->front + 1) % size];
	dq->front = (dq->front + 1) % size;
	return (tmp);
}

element	pop_rear(t_deque *dq, size_t size)
{
	element tmp;

	if (is_empty(dq))
	{
		ft_printf("que is empty");
		return (ERROR);
	}
	tmp = dq->data[dq->rear];
	dq->rear = (dq->rear - 1 + size) % size;
	return (tmp);
}

void	print_dq(t_deque *dq, size_t size)
{
	int i;

	i = (dq->front + 1) % size;
	ft_printf("t_deque(fornt = %d rear= %d)=", dq->front, dq->rear);
	if (is_empty(dq))
	{
		ft_printf("que is empty");
		return ;
	}
	while (i != dq->rear)
	{
		ft_printf("%d |", dq->data[i]);
		i = (i + 1) % size;
	}
	ft_printf("%d\n", dq->data[i]);
}

int	count_dq(t_deque *dq, size_t size)
{
	int i;
	int	count;

	i = (dq->front + 1) % size;
	count = 0;
	if (is_empty(dq))
	{
		ft_printf("que is empty");
		return (0);
	}
	while (i != dq->rear)
	{
		i = (i + 1) % size;
		count++;
	}
	return (count + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:14:20 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/12 11:44:47 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_deque.h"

t_element	pop_front(t_deque *dq, size_t size)
{
	t_element	tmp;

	if (is_empty(dq))
		return (ERROR);
	tmp = dq->data[(dq->front + 1) % size];
	dq->front = (dq->front + 1) % size;
	return (tmp);
}

t_element	pop_rear(t_deque *dq, size_t size)
{
	t_element	tmp;

	if (is_empty(dq))
		return (ERROR);
	tmp = dq->data[dq->rear];
	dq->rear = (dq->rear - 1 + size) % size;
	return (tmp);
}

void	print_dq(t_deque *dq, size_t size)
{
	int	i;

	i = (dq->front + 1) % size;
	ft_printf("t_deque(fornt = %d rear= %d)=", dq->front, dq->rear);
	if (is_empty(dq))
		return ;
	while (i != dq->rear)
	{
		ft_printf("%d |", dq->data[i]);
		i = (i + 1) % size;
	}
	ft_printf("%d\n", dq->data[i]);
}

int	count_dq(t_deque *dq, size_t size)
{
	if (is_empty(dq))
		return (ERROR);
	return ((dq->rear - dq->front + size) % size);
}

void	free_deque_a_b(t_deque *dq_a, t_deque *dq_b)
{
	free(dq_a->data);
	free(dq_b->data);
}

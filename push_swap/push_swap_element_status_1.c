/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_element_status_1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:53:57 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:39:56 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_element_status.h"

int	is_first_bigger_second(t_deque *dq, size_t size)
{
	if (dq->data[(dq->front + 1) % size] < dq->data[(dq->front + 2) % size])
		return (FALSE);
	return (TRUE);
}

int	is_first_bigger_last(t_deque *dq, size_t size)
{
	if (dq->data[(dq->front + 1) % size] < dq->data[(dq->rear) % size])
		return (FALSE);
	return (TRUE);
}

int	is_second_bigger_last(t_deque *dq, size_t size)
{
	if (dq->data[(dq->front + 2) % size] < dq->data[(dq->rear) % size])
		return (FALSE);
	return (TRUE);
}

t_boolean	is_sorted_desc1(t_deque *dq, int amt)
{
	int	i;
	int	k;

	i = (dq->front + 1) % dq->size;
	k = 0;
	while ((i != dq->rear % dq->size) && (k++ < amt - 1))
	{
		if (dq->data[i % dq->size] < dq->data[(i + 1) % dq->size])
			return (FALSE);
		i = (i + 1) % dq->size;
	}
	return (TRUE);
}

t_boolean	is_sorted_asc1(t_deque *dq, int amt)
{
	int	i;
	int	k;

	i = (dq->front + 1) % dq->size;
	k = 0;
	while ((i != dq->rear % dq->size) && (k++ < amt - 1))
	{
		if (dq->data[i % dq->size] > dq->data[(i + 1) % dq->size])
			return (FALSE);
		i = (i + 1) % dq->size;
	}
	return (TRUE);
}

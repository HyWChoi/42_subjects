/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:47:30 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:51:28 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

t_boolean	is_sorted_asc(t_deque *dq, size_t size)
{
	int		i;
	size_t	k;

	i = (dq->front + 1) % size;
	k = 0;
	while ((i != dq->rear) && (k++ < size - 1))
	{
		if (dq->data[i] > dq->data[(i + 1)])
			return (FALSE);
		i = (i + 1) % size;
	}
	return (TRUE);
}

t_boolean	is_sorted_desc(t_deque *dq, size_t size)
{
	int		i;
	size_t	k;

	i = (dq->front + 1) % size;
	k = 0;
	while ((i != dq->rear) && (k++ < size - 1))
	{
		if (dq->data[i] > dq->data[(i + 1)])
			return (FALSE);
		i = (i + 1) % size;
	}
	return (TRUE);
}

t_boolean	checker(t_deque *dq_a, t_deque *dq_b)
{
	if (is_sorted_asc(dq_a, dq_a->size) && is_empty(dq_b))
		return (TRUE);
	else
		return (FALSE);
}

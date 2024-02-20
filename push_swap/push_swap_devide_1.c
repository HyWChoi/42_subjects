/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_devide_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:40:55 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/20 19:20:47 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_devide.h"

int	get_max_index_index_with_limit(t_deque *dq, int amt, element limit)
{
	int		i;
	element	max;
	size_t	index;

	i = 0;
	max = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt)
	{
		if (max <= dq->data[(dq->front + 1 + i) % dq->size]
			&& dq->data[(dq->front + 1 + i) % dq->size] < limit)
		{
			max = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	return (index);
}

int	get_max_index(t_deque *dq, int amt)
{
	int		i;
	element	max;
	size_t	index;

	i = 0;
	max = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt)
	{
		if (max <= dq->data[(dq->front + 1 + i) % dq->size])
		{
			max = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	return (index);
}

int	get_min_index_with_limit(t_deque *dq, int amt, element limit)
{
	int		i;
	element	min;
	size_t	index;

	i = 0;
	min = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt)
	{
		if (min >= dq->data[(dq->front + 1 + i) % dq->size]
			&& dq->data[(dq->front + 1 + i) % dq->size] > limit)
		{
			min = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	return (index);
}

int	get_min_index(t_deque *dq, int amt)
{
	int		i;
	element	min;
	size_t	index;

	i = 0;
	min = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt)
	{
		if (min >= dq->data[(dq->front + 1 + i) % dq->size])
		{
			min = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	return (index);
}

boolean	is_closer_front(t_deque *dq, int value_index)
{
	int	front_distance;
	int	rear_distance;

	front_distance = (value_index - dq->front + dq->size) % dq->size;
	rear_distance = (dq->rear - value_index + dq->size) % dq->size;
	if (front_distance <= rear_distance)
		return (TRUE);
	else
		return (FALSE);
}

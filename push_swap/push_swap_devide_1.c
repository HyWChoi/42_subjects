#include "push_swap_devide.h"

int	get_max_index_index_with_limit(t_deque *dq, int amt, element limit)
{
	int i;
	element max;
	size_t index;

	i = 0;
	max = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt - 1)
	{
		// ft_printf("flag1\n");
		if (max <= dq->data[(dq->front + 1 + i) % dq->size] && dq->data[(dq->front + 1 + i) % dq->size] < limit)
		{
			max = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	if (dq->data[(dq->rear) % dq->size] > max && dq->data[(dq->rear) % dq->size] < limit)
		index = dq->rear % dq->size;
	return (index);
}

int	get_max_index(t_deque *dq, int amt)
{
	int i;
	element max;
	size_t index;

	i = 0;
	max = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt - 1)
	{
		// ft_printf("flag2\n");
		if (max <= dq->data[(dq->front + 1 + i) % dq->size])
		{
			max = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	if (dq->data[(dq->rear) % dq->size] > max)
		index = dq->rear % dq->size;
	// ft_printf("max: %d, index: %d\n", max, index);
	return (index);
}


int	get_min_index_with_limit(t_deque *dq, int amt, element limit)
{
	int i;
	element min;
	size_t index;

	i = 0;
	min = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt - 1)
	{
		// ft_printf("limit: %d\n", limit);
		if (min >= dq->data[(dq->front + 1 + i) % dq->size] && dq->data[(dq->front + 1 + i) % dq->size] > limit)
		{
			// ft_printf("Tlqkfmin: %d, dq->data[(dq->front + 2 + i) %% dq->size]: %d\n", min, dq->data[(dq->front + 2 + i) % dq->size]);
			min = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	if (dq->data[(dq->rear) % dq->size] < min && dq->data[(dq->rear) % dq->size] > limit)
		index = dq->rear % dq->size;
	return (index);
}

int	get_min_index(t_deque *dq, int amt)
{
	int i;
	element min;
	size_t index;

	i = 0;
	min = dq->data[(dq->front + 1) % dq->size];
	index = (dq->front + 1) % dq->size;
	while (i < amt - 1)
	{
		// ft_printf("flag4\n");
		if (min >= dq->data[(dq->front + 1 + i) % dq->size])
		{
			min = dq->data[(dq->front + 1 + i) % dq->size];
			index = (dq->front + 1 + i) % dq->size;
		}
		i++;
	}
	if (dq->data[(dq->rear) % dq->size] < min)
		index = dq->rear % dq->size;
	return (index);
}

boolean	is_closer_front(t_deque *dq, int value_index)
{
	int front_distance, rear_distance;

	front_distance = (value_index - dq->front + dq->size) % dq->size;
	rear_distance = (dq->rear - value_index + dq->size) % dq->size;

	if (front_distance <= rear_distance)
		return (TRUE);
	else
		return (FALSE);
}

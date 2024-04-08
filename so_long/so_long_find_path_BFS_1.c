/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_find_path_BFS_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:07:06 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 23:07:08 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_find_path_BFS.h"

t_queue	*create_queue(t_coordinate loc)
{
	t_queue	*q;

	q = (t_queue *)malloc(sizeof(t_queue));
	if (q == NULL)
		exit(1);
	q->front = NULL;
	q->rear = NULL;
	enqueue(q, loc);
	return (q);
}

void	enqueue(t_queue *q, t_coordinate loc)
{
	t_queue_node	*new_node;

	new_node = (t_queue_node *)malloc(sizeof(t_queue_node));
	if (new_node == NULL)
		exit(1);
	new_node->loc = loc;
	new_node->next = NULL;
	if (is_queue_empty(q))
	{
		q->front = new_node;
		q->rear = new_node;
		return ;
	}
	q->rear->next = new_node;
	q->rear = new_node;
}

t_coordinate	dequeue(t_queue *q)
{
	t_queue_node	*temp;
	t_coordinate	loc;

	if (is_queue_empty(q))
		exit(1);
	temp = q->front;
	loc = temp->loc;
	q->front = q->front->next;
	if (is_queue_empty(q))
		q->rear = NULL;
	free(temp);
	return (loc);
}

int	is_queue_empty(t_queue *q)
{
	return (q->front == NULL);
}

int	**init_direction_arr(void)
{
	int	**direction;
	int	i;

	i = 0;
	direction = (int **)malloc(sizeof(int *) * 4);
	if (direction == NULL)
		exit(1);
	while (i < 4)
	{
		direction[i] = (int *)malloc(sizeof(int) * 2);
		if (direction[i] == NULL)
			exit(1);
		i++;
	}
	direction[0][0] = 0;
	direction[0][1] = 1;
	direction[1][0] = 0;
	direction[1][1] = -1;
	direction[2][0] = 1;
	direction[2][1] = 0;
	direction[3][0] = -1;
	direction[3][1] = 0;
	return (direction);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_find_path_BFS_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:45:45 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 22:48:30 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_find_path_BFS.h"

void	free_direction_arr(int **direction)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(direction[i]);
		i++;
	}
	free(direction);
}

void	free_queue(t_queue *q)
{
	t_queue_node	*temp;

	while (q->front)
	{
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}
	free(q);
}

t_boolean	check_and_clean_resources(int collectible_count,
		int exit_count, t_queue *queue)
{
	if (!collectible_count && !exit_count)
	{
		free_queue(queue);
		return (TRUE);
	}
	return (FALSE);
}

void	modify_map(t_coordinate next, char **copid_map,
		int *counts, t_queue *queue)
{
	if (is_possible_to_go(copid_map, &next))
	{
		if (copid_map[next.y][next.x] == MAP_EXIT)
			counts[1]--;
		if (copid_map[next.y][next.x] == MAP_COLLECTIBLE)
			counts[0]--;
		copid_map[next.y][next.x] = MAP_VISITED;
		enqueue(queue, next);
	}
}

t_boolean	bfs_find_path(char **copid_map, t_coordinate start,
		int *counts)
{
	t_queue			*queue;
	t_coordinate	current;
	t_coordinate	next;
	int				**direction;
	int				i;

	queue = create_queue(start);
	direction = init_direction_arr();
	while (!is_queue_empty(queue))
	{
		current = dequeue(queue);
		i = -1;
		while (++i < 4)
		{
			next.x = current.x + direction[i][0];
			next.y = current.y + direction[i][1];
			modify_map(next, copid_map, counts, queue);
		}
		if (check_and_clean_resources(counts[0], counts[1], queue))
			return (TRUE);
	}
	free_queue(queue);
	free_direction_arr(direction);
	return (FALSE);
}

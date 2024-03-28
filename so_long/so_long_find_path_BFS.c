#include "so_long_find_path_BFS.h"

t_queue	*createQueue() {
	t_queue	*q;

	q = (t_queue *)malloc(sizeof(t_queue));
	q->front = NULL;
	q->rear = NULL;
	return (q);
}

void	enqueue(t_queue *q, t_coordinate loc) {
	t_queue_node	*newNode;

	newNode = (t_queue_node *)malloc(sizeof(t_queue_node));
	if (newNode == NULL)
		exit(1);
	newNode->loc = loc;
	newNode->next = NULL;
	if (is_queue_empty(q)) {
		q->front = newNode;
		q->rear = newNode;
		return ;
	}
	q->rear->next = newNode;
	q->rear = newNode;
}

t_coordinate	dequeue(t_queue *q) {
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

int	is_queue_empty(t_queue *q) {
	return q->front == NULL;
}

t_boolean	bfs_find_path(char **copid_map, t_coordinate start, int collectible_count, int exit_count) {
	t_queue			*queue;
	t_coordinate	current;
	t_coordinate	next;
	int				direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	int				i;

	queue = createQueue();
	enqueue(queue, start);
	while (!is_queue_empty(queue)) {
		current = dequeue(queue);
		i = 0;
		while (i < 4) {
			next.x = current.x + direction[i][0];
			next.y = current.y + direction[i][1];
			if (is_possible_to_go(copid_map, &next))
			{
				if (copid_map[next.y][next.x] == MAP_EXIT)
					exit_count--;
				if (copid_map[next.y][next.x] == MAP_COLLECTIBLE)
					collectible_count--;
				copid_map[next.y][next.x] = MAP_VISITED;
				enqueue(queue, next);
			}
			i++;
		}
		if (!collectible_count && !exit_count)
		{
			free(queue);
			return (TRUE);
		}
	}
	free(queue);
	return (FALSE);
}

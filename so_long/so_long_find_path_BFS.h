#ifndef SO_LONG_FIND_PATH_H
# define SO_LONG_FIND_PATH_H
# include "so_long_init_map.h"

typedef struct s_queue_node {
	t_coordinate loc;
	struct s_queue_node *next;
}	t_queue_node;

typedef struct s_queue {
	t_queue_node *front;
	t_queue_node *rear;
}	t_queue;

t_queue			*createQueue();
void			enqueue(t_queue *q, t_coordinate loc);
t_coordinate	dequeue(t_queue *q);
int				is_queue_empty(t_queue *q);
t_boolean		bfs_find_path(char **copid_map, t_coordinate start, int collectible_count, int exit_count);
#endif

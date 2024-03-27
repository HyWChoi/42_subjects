#ifndef SO_LONG_FIND_PATH_H
# define SO_LONG_FIND_PATH_H
# include "so_long_valid_check.h"

typedef struct s_queue_node {
    t_coordinate loc;
    struct s_queue_node *next;
} t_queue_node;

typedef struct s_queue {
    t_queue_node *front;
    t_queue_node *rear;
} t_queue;

void enqueue(t_queue *q, t_coordinate loc);
t_coordinate dequeue(t_queue *q);
int is_queue_empty(t_queue *q);
void find_path(t_map *map, t_coordinate start);
#endif

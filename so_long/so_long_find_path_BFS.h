/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_find_path_BFS.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:06:54 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 23:09:29 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_FIND_PATH_BFS_H
# define SO_LONG_FIND_PATH_BFS_H
# include "so_long_init_map.h"

typedef struct s_queue_node {
	t_coordinate		loc;
	struct s_queue_node	*next;
}	t_queue_node;

typedef struct s_queue {
	t_queue_node	*front;
	t_queue_node	*rear;
}	t_queue;

t_queue			*create_queue(t_coordinate loc);
void			enqueue(t_queue *q, t_coordinate loc);
t_coordinate	dequeue(t_queue *q);
int				is_queue_empty(t_queue *q);
int				**init_direction_arr(void);
void			free_direction_arr(int **direction);
void			free_queue(t_queue *q);
t_boolean		check_and_clean_resources(int collectible_count,
					int exit_count, t_queue *queue);
void			modify_map(t_coordinate next, char **copid_map,
					int *counts, t_queue *queue);
t_boolean		bfs_find_path(char **copid_map, t_coordinate start,
					int *counts);
#endif

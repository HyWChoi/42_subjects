/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:07:41 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 23:07:41 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H
# include "so_long.h"

void			free_map(char **map);
char			**read_map(int fd);
char			**copy_map(t_map *map);
t_boolean		is_possible_to_go(char **map, t_coordinate *loc);
void			count_map_element(t_map *map);

#endif

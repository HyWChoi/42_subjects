/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_valid_check.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:07:44 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 23:10:04 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_VALID_CHECK_H
# define SO_LONG_VALID_CHECK_H
# include "so_long_find_path_BFS.h"

t_boolean	check_rectangular_map(t_map *map);
t_boolean	check_wrrapped_by_wall(t_map *map);
t_boolean	check_vaild_elem_in_map(t_map *map);
t_boolean	map_validation_check(t_map *map, char *file_name);
#endif

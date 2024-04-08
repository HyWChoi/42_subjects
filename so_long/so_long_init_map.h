/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_map.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:07:29 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 23:11:18 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_INIT_MAP_H
# define SO_LONG_INIT_MAP_H
# include "so_long_utils.h"

t_map			*init_map(void);
t_map_element	*init_map_element(void);
void			init_player_loc(t_map *map, t_coordinate *player_loc);
void			set_map(t_map *map, char **map_str);
void			free_t_map(t_map *map);

#endif

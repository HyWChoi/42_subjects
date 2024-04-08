/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_game_graphics.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:11:25 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 23:12:14 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_INIT_GAME_GRAPHICS_H
# define SO_LONG_INIT_GAME_GRAPHICS_H
# include "so_long_valid_check.h"

void		init_img_info(t_game_info *game_info,
				t_game_img *img_info, char *path);
t_game_img	*init_img_info_arr(t_game_info *game_info, char *path);
t_game_imgs	init_imgs(t_game_info *game_info);
void		init_game_info(t_game_info **game_info, t_map *map);

#endif

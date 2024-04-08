/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_set_graphics_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:57:54 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 21:13:30 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_set_graphics.h"

void	set_img_to_map(t_game_info *game_info)
{
	t_coordinate	pos;
	t_map			*map;

	pos.x = 0;
	pos.y = 0;
	map = game_info->map;
	while (pos.y < map->height)
	{
		while (pos.x < map->width)
		{
			mlx_put_image_to_window(game_info->mlx, game_info->win,
				game_info->imgs.tile[0].img_ptr,
				pos.x * IMG_SIZE, pos.y * IMG_SIZE);
			decide_img(game_info, pos);
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
}

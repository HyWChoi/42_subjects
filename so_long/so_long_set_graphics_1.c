/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_set_graphics_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:57:54 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 21:07:00 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_set_graphics.h"

void	repaint_area(t_game_info *game_info, int x, int y)
{
	t_map	*map;

	map = game_info->map;
	mlx_put_image_to_window(game_info->mlx, game_info->win,
		game_info->imgs.tile[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	if (map->map[y][x] == MAP_EXIT)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.exit_imgs[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (map->map[y][x] == MAP_COLLECTIBLE_COLLECTED)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.collectible[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
}

void	set_left_bounder(t_game_info *game_info, int x, int y)
{
	if (y == 0)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_width[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == 1)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_height[2].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == game_info->map->height - 2)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_height[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == game_info->map->height - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_width[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_height[1].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
}

void	set_right_bounder(t_game_info *game_info, int x, int y)
{
	if (y == 0)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_width[2].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == 1)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_height[2].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == game_info->map->height - 2)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_height[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == game_info->map->height - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_width[2].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_height[1].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
}

void	set_bounder(t_game_info *game_info, int x, int y)
{
	if (x == 0)
		set_left_bounder(game_info, x, y);
	else if (x == game_info->map->width - 1)
		set_right_bounder(game_info, x, y);
	else if (x > 0 && x < game_info->map->width - 1 && y == 0)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_width[1].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (x > 0 && x < game_info->map->width - 1
		&& y == game_info->map->height - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_width[1].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.wall_normal[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
}

void	decide_img(t_game_info *game_info, t_coordinate pos)
{
	t_map	*map;

	map = game_info->map;
	if (map->map[pos.y][pos.x] == MAP_WALL)
		set_bounder(game_info, pos.x, pos.y);
	else if (map->map[pos.y][pos.x] == MAP_COLLECTIBLE)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.collectible[1].img_ptr,
			pos.x * IMG_SIZE, pos.y * IMG_SIZE);
	else if (map->map[pos.y][pos.x] == MAP_EXIT)
		mlx_put_image_to_window(game_info->mlx, game_info->win,
			game_info->imgs.exit_imgs[0].img_ptr,
			pos.x * IMG_SIZE, pos.y * IMG_SIZE);
}

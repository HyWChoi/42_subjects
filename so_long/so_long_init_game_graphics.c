/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_game_graphics.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:58:35 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 18:01:14 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_init_game_graphics.h"

void	init_img_info(t_game_info *game_info, t_game_img *img_info, char *path)
{
	img_info->path = path;
	img_info->width = IMG_SIZE;
	img_info->height = IMG_SIZE;
	img_info->img_ptr = mlx_xpm_file_to_image(game_info->mlx, path,
			&img_info->width, &img_info->height);
	if (img_info->img_ptr == NULL)
	{
		ft_printf("Error: mlx_xpm_file_to_image\n");
		exit(1);
	}
	else
		ft_printf("Success: mlx_xpm_file_to_image Path: %s\n", path);
}

t_game_img	*init_img_info_arr(t_game_info *game_info, char *path)
{
	int			count;
	char		**img_paths;
	t_game_img	*imgs;

	img_paths = ft_split(path, ' ');
	count = ft_strslen(img_paths);
	imgs = (t_game_img *)malloc(sizeof(t_game_img) * count);
	if (imgs == NULL)
		return (NULL);
	while (count--)
		init_img_info(game_info, &imgs[count], img_paths[count]);
	ft_free_split(img_paths);
	return (imgs);
}

t_game_imgs	init_imgs(t_game_info *game_info)
{
	t_game_imgs	imgs;

	imgs.wall_width = init_img_info_arr(game_info, WALL_IMG_WIDTH_PATHS);
	imgs.wall_height = init_img_info_arr(game_info, WALL_IMG_HEIGHT_PATHS);
	imgs.wall_normal = init_img_info_arr(game_info, WALL_IMG_NORMAL_WALL_PATHS);
	imgs.tile = init_img_info_arr(game_info, TILE_IMG_PATHS);
	imgs.player_stay = init_img_info_arr(game_info, PLAYER_STAY_IMG_PATHS);
	imgs.player_move_left = init_img_info_arr(game_info,
			PLAYER_MOVE_LEFT_IMG_PATHS);
	imgs.player_move_right = init_img_info_arr(game_info,
			PLAYER_MOVE_RIGHT_IMG_PATHS);
	imgs.player_move_up = init_img_info_arr(game_info,
			PLAYER_MOVE_UP_IMG_PATHS);
	imgs.player_move_down = init_img_info_arr(game_info,
			PLAYER_MOVE_DOWN_IMG_PATHS);
	imgs.collectible = init_img_info_arr(game_info, COLLECTIBLE_IMG_PATHS);
	imgs.exit_imgs = init_img_info_arr(game_info, EXIT_IMG_PATHS);
	return (imgs);
}

void	init_game_info(t_game_info **game_info, t_map *map)
{
	int	size_x;
	int	size_y;

	size_x = map->width * IMG_SIZE;
	size_y = map->height * IMG_SIZE;
	ft_printf("size_x, size_y: %d, %d\n", size_x, size_y);
	*game_info = (t_game_info *)malloc(sizeof(t_game_info));
	if (*game_info == NULL)
		exit(1);
	(*game_info)->mlx = mlx_init();
	(*game_info)->win = mlx_new_window((*game_info)->mlx,
			size_x, size_y, "putImage");
	(*game_info)->map = map;
	init_player_loc(map, &(*game_info)->player_loc);
	(*game_info)->imgs = init_imgs(*game_info);
	(*game_info)->move_count = 0;
	(*game_info)->character_loop_control_value = 0;
}

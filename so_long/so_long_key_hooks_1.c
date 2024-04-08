/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_hooks_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:55:29 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 22:58:45 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_key_hooks.h"

void	init_pos(t_coordinate *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

int	handle_collectible_interaction(t_game_info *game_info,
		t_coordinate current, t_coordinate next)
{
	t_map	*map;

	map = game_info->map;
	if (map->map[current.y][current.x] != MAP_COLLECTIBLE_COLLECTED &&
			map->map[current.y][current.x] != MAP_EXIT)
			map->map[current.y][current.x] = MAP_EMPTY;
	map->map[next.y][next.x] = MAP_COLLECTIBLE_COLLECTED;
	game_info->player_loc.x = next.x;
	game_info->player_loc.y = next.y;
	repaint_area(game_info, current.x, current.y);
	repaint_area(game_info, next.x, next.y);
	game_info->move_count++;
	game_info->map->map_elem->collectible--;
	ft_printf("total steps: %d", game_info->move_count);
	return (0);
}

int	handle_exit_condition(t_game_info *game_info)
{
	t_map	*map;

	map = game_info->map;
	if (map->map_elem->collectible == 0)
	{
		ft_printf("total steps: %d", game_info->move_count);
		ft_printf("remained collectibles: %d", map->map_elem->collectible);
		exit(1);
	}
	ft_printf("remained collectibles: %d", map->map_elem->collectible);
	return (0);
}

void	handle_movement_condition(t_game_info *game_info,
		t_coordinate current, t_coordinate next)
{
	t_map	*map;

	map = game_info->map;
	if (map->map[current.y][current.x] != MAP_COLLECTIBLE_COLLECTED &&
			map->map[current.y][current.x] != MAP_EXIT)
		map->map[current.y][current.x] = MAP_EMPTY;
	game_info->player_loc.x = next.x;
	game_info->player_loc.y = next.y;
	repaint_area(game_info, current.x, current.y);
}

int	handle_player_movement(t_game_info *game_info, int dx, int dy)
{
	t_coordinate	next;
	t_coordinate	current;
	t_map			*map;

	map = game_info->map;
	init_pos(&current, game_info->player_loc.x, game_info->player_loc.y);
	init_pos(&next, game_info->player_loc.x + dx, game_info->player_loc.y + dy);
	if (map->map[next.y][next.x] == MAP_WALL)
		return (0);
	if (map->map[next.y][next.x] == MAP_COLLECTIBLE)
		return (handle_collectible_interaction(game_info, current, next));
	if (map->map[next.y][next.x] == MAP_EXIT)
		handle_exit_condition(game_info);
	handle_movement_condition(game_info, current, next);
	game_info->move_count++;
	ft_printf("total steps: %d", game_info->move_count);
	return (0);
}

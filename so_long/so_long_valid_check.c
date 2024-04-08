/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_valid_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:10:17 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 22:56:16 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_valid_check.h"

t_boolean	check_file_ext(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 5)
		return (FALSE);
	if (ft_strncmp(file_name + len - 4, ".ber", 4) != 0)
		return (FALSE);
	return (TRUE);
}

t_boolean	check_rectangular_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) - 1 != (size_t)map->width)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_boolean	check_wrrapped_by_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != MAP_WALL
			|| map->map[map->height - 1][i] != MAP_WALL)
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != MAP_WALL
			|| map->map[i][map->width - 1] != MAP_WALL)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_boolean	check_vaild_elem_in_map(t_map *map)
{
	if (map->map_elem->player != 1 || map->map_elem->exit != 1)
		return (FALSE);
	return (TRUE);
}

t_boolean	map_validation_check(t_map *map, char *file_name)
{
	t_coordinate	player_loc;
	int				*counts;
	t_boolean		flag;

	counts = (int *)malloc(sizeof(int) * 2);
	counts[0] = map->map_elem->collectible;
	counts[1] = map->map_elem->exit;
	flag = TRUE;
	if (counts == NULL)
		flag = FALSE;
	init_player_loc(map, &player_loc);
	if (flag && !check_file_ext(file_name))
		flag = FALSE;
	if (flag && !check_rectangular_map(map))
		flag = FALSE;
	if (flag && !check_wrrapped_by_wall(map))
		flag = FALSE;
	if (flag && !check_vaild_elem_in_map(map))
		flag = FALSE;
	if (flag && !bfs_find_path(copy_map(map),
			player_loc, counts))
		flag = FALSE;
	return (flag);
}

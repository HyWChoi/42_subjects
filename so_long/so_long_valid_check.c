# include "so_long_valid_check.h"

t_boolean check_rectangular_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) - 1 != (size_t)map->width)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_boolean check_wrrapped_by_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width - 1)
	{
		if (map->map[0][i] != MAP_WALL || map->map[map->height - 1][i] != MAP_WALL)
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < map->height - 1)
	{
		if (map->map[i][0] != MAP_WALL || map->map[i][map->width - 1] != MAP_WALL)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_boolean check_vaild_elem_in_map(t_map *map)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < map->height - 1)
	{
		while (x < map->width - 1)
		{
			if (map->map[y][x] == MAP_COLLECTIBLE)
				map->map_elem->collectible++;
			else if (map->map[y][x] == MAP_EXIT)
				map->map_elem->exit++;
			else if (map->map[y][x] == MAP_PLAYER)
				map->map_elem->player++;
			else if (map->map[y][x] != MAP_EMPTY && map->map[y][x] != MAP_WALL)
				return (FALSE);
			x++;
		}
		x = 0;
		y++;
	}
	if (map->map_elem->exit != 1 || map->map_elem->player != 1)
		return (FALSE);
	return (TRUE);
}

t_boolean	is_possible_to_go(t_map *map, t_coordinate *loc)
{
	char	status;

	status = map->map[loc->y][loc->x];
	if (status == MAP_WALL || status == MAP_PLAYER)
		return (FALSE);
	return (TRUE);
}

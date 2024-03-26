# include "so_long_valid_check.h"

t_boolean check_rectangular_map(t_map *map)
{
	int i;

	i = 0;
	if (map->width < 4 || map->height < 4)
		return (FALSE);
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) != (size_t)map->width)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_boolean check_wrrapped_by_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
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
			if (map->map[y][x] == 'C')
				map->map_elem->collectible++;
			else if (map->map[y][x] == 'E')
				map->map_elem->exit++;
			else if (map->map[y][x] == 'P')
				map->map_elem->player++;
			else if (map->map[y][x] != '0' && map->map[y][x] != '1')
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
	if (status == '1' || status == 'P')
		return (FALSE);
	return (TRUE);
}

// void	find_path(t_map *map, t_coordinate *loc)
// {
// 	if (map->map_elem->collectible == 0 && map->map[loc->x][loc->y] == 'E')
// 		return ;
// 	else
// 	{
// 		if (map->map[loc->x][loc->y] == 'C')
// 			map->map_elem->collectible--;
// 		if (map->map[loc->x + 1][loc->y] != '1')

// 	}
// }

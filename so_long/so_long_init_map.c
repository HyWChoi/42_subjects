# include "so_long_init_map.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->map_elem = init_map_element();
	return (map);
}

t_map_element	*init_map_element(void)
{
	t_map_element	*map_elem;

	map_elem = (t_map_element *)malloc(sizeof(t_map_element));
	map_elem->player = 0;
	map_elem->collectible = 0;
	map_elem->exit = 0;
	return (map_elem);
}

void	init_player_loc(t_map *map, t_coordinate *player_loc)
{
	int				x;
	int				y;

	x = 1;
	y = 1;
	while (y < map->height - 1)
	{
		while (x < map->width - 1)
		{
			if (map->map[y][x] == 'P')
			{
				player_loc->x = x;
				player_loc->y = y;
				return ;
			}
			x++;
		}
		x = 1;
		y++;
	}
}

void	set_map(t_map *map, char **map_str)
{
	map->map = map_str;
	map->width = ft_strlen(map_str[0]) - 1;
	map->height = ft_strslen(map_str);
	count_map_element(map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}


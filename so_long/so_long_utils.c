#include "so_long_utils.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (i < MAX_MAP_SIZE)
	{
		free(map[i]);
		i++;
	}
	free(map);
	free(map);
}

char	**read_map(int fd)
{
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * MAX_MAP_SIZE);
	if (map == NULL)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (i == MAX_MAP_SIZE)
		{
			free_map(map);
			return (NULL);
		}
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

t_boolean	is_possible_to_go(char **map, t_coordinate *loc)
{
	char	status;

	status = map[loc->y][loc->x];
	if (status == MAP_WALL || status == MAP_VISITED)
		return (FALSE);
	return (TRUE);
}

char	**copy_map(t_map *map)
{
	char	**copied_map;
	int		i;

	i = 0;
	copied_map = (char **)malloc(sizeof(char *) * map->height + 1);
	if (copied_map == NULL)
		return (NULL);
	while (i < map->height)
	{
		copied_map[i] = ft_strdup(map->map[i]);
		i++;
	}
	return (copied_map);
}

void	count_map_element(t_map *map)
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
			x++;
		}
		x = 1;
		y++;
	}
}

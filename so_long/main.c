#include "so_long_valid_check.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	map = init_map();
	if (argc != 2)
		return (1);
	if (map == NULL)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	set_map(map, read_map(fd));
	close(fd);
	// print_map(map);
	// if (check_wrrapped_by_wall(map) == FALSE)
	// 	ft_printf("Error: Map is not wrapped by wall\n");
	// else
	// 	ft_printf("Map is wrapped by wall\n");
	return (0);
}

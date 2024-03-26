#include "so_long.h"

char	**read_map(int fd)
{
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * 100);
	if (map == NULL)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

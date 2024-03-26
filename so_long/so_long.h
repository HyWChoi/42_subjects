#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef int	t_boolean;
typedef struct s_map_element
{
	int	collectible;
	int	exit;
	int	player;
}	t_map_element;
typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;
typedef struct s_map
{
	t_map_element	*map_elem;
	char			**map;
	int				width;
	int				height;
	int				player;
	int				collectible;
	int				exit;
}	t_map;
char	**read_map(int fd);
#endif

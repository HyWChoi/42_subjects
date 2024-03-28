#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"
# define TRUE 1
# define FALSE 0
# define ERROR -1
#define MAP_WALL '1'
#define MAP_COLLECTIBLE 'C'
#define MAP_EXIT 'E'
#define MAP_PLAYER 'P'
#define MAP_EMPTY '0'
#define MAP_VISITED 'V'
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
}	t_map;

typedef struct s_game_info
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_coordinate	player_loc;
	t_game_img		img_character;
	t_game_img		img_floor;
	t_game_img		img_wall;
	t_game_img		img_collectible_open;
	t_game_img		img_collectible_close;
	t_game_img		img_exit_open;
	t_game_img		img_exit_close;
}	t_game_info;

typedef struct s_game_img
{
	char	*path;
	int		width;
	int		height;
}	t_game_img;
#endif

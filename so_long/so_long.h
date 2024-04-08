/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:07:46 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 23:07:47 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"
# define TRUE 1
# define FALSE 0
# define ERROR -1
#define MAP_WALL '1'
#define MAP_COLLECTIBLE 'C'
#define MAP_COLLECTIBLE_COLLECTED 'c'
#define MAP_EXIT 'E'
#define MAP_PLAYER 'P'
#define MAP_EMPTY '0'
#define MAP_VISITED 'V'
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define IMG_SIZE 32
#define MAX_MAP_SIZE 101
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define WALL_IMG_NORMAL_WALL_PATHS "img_xpms/walls/wall_normal.xpm"
# define WALL_IMG_WIDTH_PATHS "img_xpms/walls/wall_width_left.xpm img_xpms/walls/wall_width_mid.xpm img_xpms/walls/wall_width_right.xpm"
# define WALL_IMG_HEIGHT_PATHS "img_xpms/walls/wall_height_bottom.xpm img_xpms/walls/wall_height_mid.xpm img_xpms/walls/wall_height_top.xpm"
# define TILE_IMG_PATHS "img_xpms/ground.xpm"
# define PLAYER_STAY_IMG_PATHS "img_xpms/player_stay_up.xpm img_xpms/player_stay_donw.xpm"
# define PLAYER_MOVE_UP_IMG_PATHS "img_xpms/player_move/player_move_up_1.xpm img_xpms/player_move/player_move_up_2.xpm"
# define PLAYER_MOVE_DOWN_IMG_PATHS "img_xpms/player_move/player_move_down_1.xpm img_xpms/player_move/player_move_down_2.xpm"
# define PLAYER_MOVE_LEFT_IMG_PATHS "img_xpms/player_move/player_move_left_1.xpm img_xpms/player_move/player_move_left_2.xpm img_xpms/player_move/player_move_left_3.xpm img_xpms/player_move/player_move_left_4.xpm"
# define PLAYER_MOVE_RIGHT_IMG_PATHS "img_xpms/player_move/palyer_move_right_1.xpm img_xpms/player_move/palyer_move_right_2.xpm img_xpms/player_move/palyer_move_right_3.xpm img_xpms/player_move/palyer_move_right_4.xpm"
# define COLLECTIBLE_IMG_PATHS "img_xpms/collectible_obj/collected_done.xpm img_xpms/collectible_obj/collected_non.xpm"
# define EXIT_IMG_PATHS "img_xpms/exit.xpm"
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

typedef struct s_game_img
{
	char	*path;
	int		width;
	int		height;
	void	*img_ptr;
}	t_game_img;

typedef struct s_game_imgs
{
	t_game_img		*wall_width;
	t_game_img		*wall_height;
	t_game_img		*wall_normal;
	t_game_img		*tile;
	t_game_img		*player_stay;
	t_game_img		*player_move_left;
	t_game_img		*player_move_right;
	t_game_img		*player_move_up;
	t_game_img		*player_move_down;
	t_game_img		*collectible;
	t_game_img		*exit_imgs;
}	t_game_imgs;

typedef struct s_game_info
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_coordinate	player_loc;
	t_game_imgs		imgs;
	int				move_count;
	int				character_loop_control_value;
}	t_game_info;
#endif

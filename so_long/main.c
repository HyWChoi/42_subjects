#include "so_long_valid_check.h"

void	init_img_info(t_img_info *img_info)
{
	img_info->img = NULL;
	img_info->img_width = 0;
	img_info->img_height = 0;
}

void	init_game_info(t_game_info *game_info, t_map *map)
{
	t_game_info	*game_info;

	game_info = (t_game_info *)malloc(sizeof(t_game_info));
	if (game_info == NULL)
		return (NULL);
	game_info->mlx = mlx_init();
	game_info->win = mlx_new_window(game_info->mlx, 1000, 1000, "putImage");
	game_info->map = map;
	init_player_loc(map, &game_info->player_loc);
	game_info->img_character
	return (game_info);
}

void	set_img_to_map(t_map *map, t_game_info *game_info)
{
	int		x;
	int		y;

	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->img, 50, 50);
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->img, 50, 50);
			else if (map->map[y][x] == 'P')
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->img, 50, 50);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->img, 50, 50);
			else if (map->map[y][x] == 'E')
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->img, 50, 50);
			x++;
		}
		x = 0;
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;

	argc = 0;
	argv = 0;
	if (argc != 2)
	{
		ft_printf("Error: invalid argument\n");
		exit(1);
	}
	map = init_map();
	if (map == NULL)
		exit(1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	set_map(map, read_map(fd));
	close(fd);
	if (!map_validation_check(map, argv[1]))
	{
		ft_printf("Error: Invaild map\n");
		exit(1);
	}
	ft_printf("Valid map\n");
	t_game_info	*game_info;
	init_game_info(&game_info, map);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "putImage");
	img = mlx_xpm_file_to_image(mlx, "ow7.xpm", &img_width, &img_height);
    //xpm 파일을 불러와 이미지로 변환하고 img에 저장해줌
	mlx_put_image_to_window(mlx, win, img, 50, 50);
    // xpm에서 이미지로 변환한 img를 화면에 (50,50)위치에 띄워줌
	mlx_loop(mlx);
	return (0);
}

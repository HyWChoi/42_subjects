#include "so_long_valid_check.h"

void	init_img_info(t_game_info *game_info,t_game_img *img_info, char *path)
{
	img_info->path = path;
	img_info->width = IMG_SIZE;
	img_info->height = IMG_SIZE;
	img_info->img_ptr = mlx_xpm_file_to_image(game_info->mlx, path, &img_info->width, &img_info->height);
	if (img_info->img_ptr == NULL)
	{
		ft_printf("Error: mlx_xpm_file_to_image\n");
		exit(1);
	}
	else
		ft_printf("Success: mlx_xpm_file_to_image Path: %s\n", path);
}

void	repaint_area(t_game_info *game_info, int x, int y)
{
	t_map	*map;

	map = game_info->map;
	ft_printf("x, y: %d, %d\n", x, y);
	ft_printf("map->map[y][x]: %c\n", map->map[y][x]);
	if (map->map[y][x] == MAP_COLLECTIBLE_COLLECTED)
	{
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.tile[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.collectible[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	}
	else if (map->map[y][x] == MAP_EXIT)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.exit_imgs[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.tile[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
}

t_game_img	*init_img_info_arr(t_game_info *game_info, char *path)
{
	int			count;
	char		**img_paths;
	t_game_img	*imgs;

	img_paths = ft_split(path, ' ');
	count = ft_strslen(img_paths);
	imgs = (t_game_img *)malloc(sizeof(t_game_img) * count);
	if (imgs == NULL)
		return (NULL);
	while (count--)
		init_img_info(game_info, &imgs[count], img_paths[count]);
	ft_free_split(img_paths);
	return (imgs);
}

t_game_imgs	init_imgs(t_game_info *game_info)
{
	t_game_imgs	imgs;

	imgs.wall_width = init_img_info_arr(game_info, WALL_IMG_WIDTH_PATHS);
	imgs.wall_height = init_img_info_arr(game_info, WALL_IMG_HEIGHT_PATHS);
	imgs.wall_normal = init_img_info_arr(game_info, WALL_IMG_NORMAL_WALL_PATHS);
	imgs.tile = init_img_info_arr(game_info, TILE_IMG_PATHS);
	imgs.player_stay = init_img_info_arr(game_info, PLAYER_STAY_IMG_PATHS);
	imgs.player_move_left = init_img_info_arr(game_info, PLAYER_MOVE_LEFT_IMG_PATHS);
	imgs.player_move_right = init_img_info_arr(game_info, PLAYER_MOVE_RIGHT_IMG_PATHS);
	imgs.player_move_up = init_img_info_arr(game_info, PLAYER_MOVE_UP_IMG_PATHS);
	imgs.player_move_down = init_img_info_arr(game_info, PLAYER_MOVE_DOWN_IMG_PATHS);
	imgs.collectible = init_img_info_arr(game_info, COLLECTIBLE_IMG_PATHS);
	imgs.exit_imgs = init_img_info_arr(game_info, EXIT_IMG_PATHS);
	return (imgs);
}

void	init_game_info(t_game_info **game_info, t_map *map) {
	int	size_x;
	int	size_y;

	size_x = map->width * IMG_SIZE;
	size_y = map->height * IMG_SIZE;
	ft_printf("size_x, size_y: %d, %d\n", size_x, size_y);
	*game_info = (t_game_info *)malloc(sizeof(t_game_info));
	if (*game_info == NULL)
		return; // 오류 처리
	(*game_info)->mlx = mlx_init();
	(*game_info)->win = mlx_new_window((*game_info)->mlx, size_x, size_y, "putImage");
	(*game_info)->map = map;
	init_player_loc(map, &(*game_info)->player_loc);
	ft_printf("player_loc.x, player_loc.y: %d, %d\n", (*game_info)->player_loc.x, (*game_info)->player_loc.y);
	(*game_info)->imgs = init_imgs(*game_info);
	(*game_info)->move_count = 0;
	(*game_info)->character_loop_control_value = 0;
}

void	set_left_bounder(t_game_info *game_info, int x, int y)
{
	if (y == 0)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_width[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == 1)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_height[2].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == game_info->map->height - 2)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_height[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == game_info->map->height - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_width[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_height[1].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
}

void	set_right_bounder(t_game_info *game_info, int x, int y)
{
	if (y == 0)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_width[2].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == 1)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_height[2].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == game_info->map->height - 2)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_height[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (y == game_info->map->height - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_width[2].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_height[1].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
}

void	set_bounder(t_game_info *game_info, int x, int y)
{
	if (x == 0)
		set_left_bounder(game_info, x, y);
	else if (x == game_info->map->width - 1)
		set_right_bounder(game_info, x, y);
	else if (x > 0 && x < game_info->map->width - 1 && y == 0)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_width[1].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else if (x > 0 && x < game_info->map->width - 1 && y == game_info->map->height - 1)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_width[1].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
	else
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.wall_normal[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
}

void	set_img_to_map(t_game_info *game_info)
{
	int		x;
	int		y;
	t_map	*map;

	x = 0;
	y = 0;
	map = game_info->map;
	while (y < map->height)
	{
		while (x < map->width)
		{
			mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.tile[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
			ft_printf("map[%d][%d]: %c\n", y, x, map->map[y][x]);
			if (map->map[y][x] == MAP_WALL)
				set_bounder(game_info, x, y);
			else if (map->map[y][x] == MAP_COLLECTIBLE)
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.collectible[1].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
			else if (map->map[y][x] == MAP_EXIT)
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.exit_imgs[0].img_ptr, x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		x = 0;
		y++;
	}
}

t_map	*create_map(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Error: invalid argument\n");
		return (NULL);
	}
	map = init_map();
	if (map == NULL)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	set_map(map, read_map(fd));
	close(fd);
	if (!map_validation_check(map, argv[1]))
	{
		ft_printf("Error: Invaild map\n");
		return (NULL);
	}
	ft_printf("Valid map\n");
	return (map);
}

t_game_info	*create_game(t_map *map)
{
	t_game_info	*game_info;
	init_game_info(&game_info, map);
	set_img_to_map(game_info);
	ft_printf("set_img_to_map\n");
	return (game_info);
}

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

int	press_W(t_game_info *game_info)
{
	int		x;
	int		y;
	t_map	*map;

	map = game_info->map;
	ft_printf("player_loc.x, player_loc.y: %d, %d\n", game_info->player_loc.x, game_info->player_loc.y);
	x = game_info->player_loc.x;
	y = game_info->player_loc.y;
	ft_printf("press_W\n");
	if (map->map[y - 1][x] == MAP_WALL)
		return (0);
	if (map->map[y - 1][x] == MAP_COLLECTIBLE)
	{
		if (map->map[y][x] != MAP_COLLECTIBLE_COLLECTED)
			map->map[y][x] = MAP_EMPTY;
		map->map[y - 1][x] = MAP_COLLECTIBLE_COLLECTED;
		game_info->player_loc.y = y - 1;
		repaint_area(game_info, x, y);
		repaint_area(game_info, x, y - 1);
		game_info->move_count++;
		game_info->map->map_elem->collectible--;
		return (0);
	}
	if (map->map[y - 1][x] == MAP_EXIT)
	{
		if (game_info->map->map_elem->collectible == 0)
		{
			ft_printf("total steps: %d", game_info->move_count);
			ft_printf("remained collectibles: %d", game_info->map->map_elem->collectible);
			exit(0);
		}
		ft_printf("remained collectibles: %d", game_info->map->map_elem->collectible);
	}
	if (map->map[y][x] != MAP_COLLECTIBLE_COLLECTED && map->map[y][x] != MAP_EXIT)
		map->map[y][x] = MAP_EMPTY;
	game_info->player_loc.y = y - 1;
	repaint_area(game_info, x, y);
	return (0);
}

int	press_A(t_game_info *game_info)
{
	int		x;
	int		y;
	t_map	*map;

	map = game_info->map;
	x = game_info->player_loc.x;
	y = game_info->player_loc.y;
	ft_printf("press_A\n");
	if (map->map[y][x - 1] == MAP_WALL)
		return (0);
	if (map->map[y][x - 1] == MAP_COLLECTIBLE)
	{
		if (map->map[y][x] != MAP_COLLECTIBLE_COLLECTED)
			map->map[y][x] = MAP_EMPTY;
		map->map[y][x - 1] = MAP_COLLECTIBLE_COLLECTED;
		game_info->player_loc.x = x - 1;
		repaint_area(game_info, x, y);
		repaint_area(game_info, x - 1, y);
		game_info->move_count++;
		game_info->map->map_elem->collectible--;
		return (0);
	}
	if (map->map[y][x - 1] == MAP_EXIT)
	{
		if (game_info->map->map_elem->collectible == 0)
		{
			ft_printf("total steps: %d", game_info->move_count);
			ft_printf("remained collectibles: %d", game_info->map->map_elem->collectible);
			exit(0);
		}
		ft_printf("remained collectibles: %d", game_info->map->map_elem->collectible);
	}
	if (map->map[y][x] != MAP_COLLECTIBLE_COLLECTED && map->map[y][x] != MAP_EXIT)
		map->map[y][x] = MAP_EMPTY;
	game_info->player_loc.x = x - 1;
	repaint_area(game_info, x, y);
	return (0);
}

int	press_S(t_game_info *game_info)
{
	int		x;
	int		y;
	t_map	*map;

	map = game_info->map;
	x = game_info->player_loc.x;
	y = game_info->player_loc.y;
	ft_printf("press_S\n");
	if (map->map[y + 1][x] == MAP_WALL)
		return (0);
	if (map->map[y + 1][x] == MAP_COLLECTIBLE)
	{
		if (map->map[y][x] != MAP_COLLECTIBLE_COLLECTED)
			map->map[y][x] = MAP_EMPTY;
		map->map[y + 1][x] = MAP_COLLECTIBLE_COLLECTED;
		game_info->player_loc.y = y + 1;
		repaint_area(game_info, x, y);
		repaint_area(game_info, x, y + 1);
		game_info->move_count++;
		game_info->map->map_elem->collectible--;
		return (0);
	}
	if (map->map[y + 1][x] == MAP_EXIT)
	{
		if (game_info->map->map_elem->collectible == 0)
		{
			ft_printf("total steps: %d", game_info->move_count);
			ft_printf("remained collectibles: %d", game_info->map->map_elem->collectible);
			exit(0);
		}
		ft_printf("remained collectibles: %d", game_info->map->map_elem->collectible);
	}
	if (map->map[y][x] != MAP_COLLECTIBLE_COLLECTED && map->map[y][x] != MAP_EXIT)
		map->map[y][x] = MAP_EMPTY;
	game_info->player_loc.y = y + 1;
	repaint_area(game_info, x, y);
	return (0);
}

int	press_D(t_game_info *game_info)
{
	int		x;
	int		y;
	t_map	*map;

	x = game_info->player_loc.x;
	y = game_info->player_loc.y;
	map = game_info->map;
	print_map(map);
	if (map->map[y][x + 1] == MAP_WALL)
		return (0);
	if (map->map[y][x + 1] == MAP_COLLECTIBLE)
	{
		if (map->map[y][x] != MAP_COLLECTIBLE_COLLECTED)
			map->map[y][x] = MAP_EMPTY;
		map->map[y][x + 1] = MAP_COLLECTIBLE_COLLECTED;
		game_info->player_loc.x = x + 1;
		repaint_area(game_info, x, y);
		repaint_area(game_info, x + 1, y);
		game_info->move_count++;
		game_info->map->map_elem->collectible--;
		return (0);
	}
	if (map->map[y][x + 1] == MAP_EXIT)
	{
		if (game_info->map->map_elem->collectible == 0)
		{
			ft_printf("total steps: %d", game_info->move_count);
			ft_printf("remained collectibles: %d", game_info->map->map_elem->collectible);
			exit(0);
		}
		ft_printf("remained collectibles: %d", game_info->map->map_elem->collectible);
	}
	if (map->map[y][x] != MAP_COLLECTIBLE_COLLECTED && map->map[y][x] != MAP_EXIT)
		map->map[y][x] = MAP_EMPTY;
	game_info->player_loc.x = x + 1;
	repaint_area(game_info, x, y);
	return (0);
}

int	press_key(int key, t_game_info *game_info)
{
	ft_printf("key: %d\n", key);
	if (key == KEY_W)
		press_W(game_info);
	else if (key == KEY_A)
		press_A(game_info);
	else if (key == KEY_S)
		press_S(game_info);
	else if (key == KEY_D)
		press_D(game_info);
	else if (key == KEY_ESC)
		exit(0);
	return (0);
}

int	render_next_frame(t_game_info *game_info)
{
	t_map	*map;
	int		total_frame;

	total_frame = 40;
	map = game_info->map;
	if (map->map[game_info->player_loc.y][game_info->player_loc.x] == MAP_COLLECTIBLE_COLLECTED)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.collectible[0].img_ptr, game_info->player_loc.x * IMG_SIZE, game_info->player_loc.y * IMG_SIZE);
	else if (map->map[game_info->player_loc.y][game_info->player_loc.x] == MAP_EXIT)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.exit_imgs[0].img_ptr, game_info->player_loc.x * IMG_SIZE, game_info->player_loc.y * IMG_SIZE);
	else
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.tile[0].img_ptr, game_info->player_loc.x * IMG_SIZE, game_info->player_loc.y * IMG_SIZE);
	if (total_frame - game_info->character_loop_control_value++ > 20)
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.player_stay[0].img_ptr, game_info->player_loc.x * IMG_SIZE, game_info->player_loc.y * IMG_SIZE);
	else
		mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->imgs.player_stay[1].img_ptr, game_info->player_loc.x * IMG_SIZE, game_info->player_loc.y * IMG_SIZE);
	if (game_info->character_loop_control_value == total_frame)
		game_info->character_loop_control_value = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_game_info	*game_info;

	game_info = NULL;
	map = create_map(argc, argv);
	if (map == NULL)
		exit(1);
	game_info = create_game(map);
	mlx_loop_hook(game_info->mlx, render_next_frame, game_info);
	mlx_key_hook(game_info->win, press_key, game_info);
	mlx_loop(game_info->mlx);
	return (0);
}

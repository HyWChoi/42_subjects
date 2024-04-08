#include "so_long_key_hooks.h"

static t_map	*create_map(int argc, char **argv)
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

static t_game_info	*create_game(t_map *map)
{
	t_game_info	*game_info;
	init_game_info(&game_info, map);
	set_img_to_map(game_info);
	ft_printf("set_img_to_map\n");
	return (game_info);
}

static int	render_next_frame(t_game_info *game_info)
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

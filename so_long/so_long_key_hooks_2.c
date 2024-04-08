/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_hooks_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:57:14 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 20:57:14 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_key_hooks.h"

int	press_w(t_game_info *game_info)
{
	handle_player_movement(game_info, 0, -1);
	return (0);
}

int	press_a(t_game_info *game_info)
{
	handle_player_movement(game_info, -1, 0);
	return (0);
}

int	press_s(t_game_info *game_info)
{
	handle_player_movement(game_info, 0, 1);
	return (0);
}

int	press_d(t_game_info *game_info)
{
	handle_player_movement(game_info, 1, 0);
	return (0);
}

int	press_key(int key, t_game_info *game_info)
{
	ft_printf("key: %d\n", key);
	if (key == KEY_W)
		press_w(game_info);
	else if (key == KEY_A)
		press_a(game_info);
	else if (key == KEY_S)
		press_s(game_info);
	else if (key == KEY_D)
		press_d(game_info);
	else if (key == KEY_ESC)
		exit(1);
	return (0);
}

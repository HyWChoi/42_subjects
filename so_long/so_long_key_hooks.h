/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_hooks.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:07:23 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 23:10:54 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_KEY_HOOKS_H
# define SO_LONG_KEY_HOOKS_H
# include "so_long_set_graphics.h"

void	init_pos(t_coordinate *pos, int x, int y);
int		handle_collectible_interaction(t_game_info *game_info,
			t_coordinate current, t_coordinate next);
int		handle_exit_condition(t_game_info *game_info);
void	handle_movement_condition(t_game_info *game_info,
			t_coordinate current, t_coordinate next);
int		handle_player_movement(t_game_info *game_info, int dx, int dy);
int		press_w(t_game_info *game_info);
int		press_a(t_game_info *game_info);
int		press_s(t_game_info *game_info);
int		press_d(t_game_info *game_info);
int		press_key(int key, t_game_info *game_info);

#endif

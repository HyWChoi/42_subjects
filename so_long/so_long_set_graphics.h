/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_set_graphics.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:07:36 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/04/08 23:10:18 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_SET_GRAPHICS_H
# define SO_LONG_SET_GRAPHICS_H
# include "so_long_init_game_graphics.h"

void	repaint_area(t_game_info *game_info, int x, int y);
void	set_left_bounder(t_game_info *game_info, int x, int y);
void	set_right_bounder(t_game_info *game_info, int x, int y);
void	set_bounder(t_game_info *game_info, int x, int y);
void	decide_img(t_game_info *game_info, t_coordinate pos);
void	set_img_to_map(t_game_info *game_info);

#endif

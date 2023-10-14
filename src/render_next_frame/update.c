/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:35:09 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/03 19:35:11 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	update_angle(t_cubed *cubed)
{
	read_key_input(cubed);
	read_mouse_input(cubed);
	mlx_mouse_move(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, \
		WIN_W / 2, WIN_H / 2);
}

void	update_player_pos(t_cubed *cubed, t_keys *keys, t_player *player)
{
	move_player(player, keys);
	check_borders(player);
	player->pos_x_array = player->pos_x * cubed->map_width / WIN_W;
	player->pos_y_array = player->pos_y * cubed->map_height / WIN_H;
	update_player_dir(cubed, player);
}

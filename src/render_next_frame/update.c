/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:35:09 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/28 20:17:29 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	update_angle(t_cubed *cubed)
{
	read_key_input(cubed);
	if (cubed->keys->mouse_movement)
	{
		mlx_mouse_hide(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr);
		read_mouse_input(cubed);
		mlx_mouse_move(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, \
			WIN_W / 2, WIN_H / 2);
	}
	else
		mlx_mouse_show(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr);
}

static void	move_player(t_player *player, t_keys *keys)
{
	player_walk(player, keys);
	player_strafe(player, keys);
}

void	update_player_pos(t_cubed *cubed, t_keys *keys, t_player *player)
{
	float	prev_x;
	float	prev_y;


	prev_x = player->pos_x_array;
	prev_y = player->pos_y_array;
	move_player(player, keys);
	check_borders(cubed, player, prev_x, prev_y);
	// check_borders(cubed, player, prev_x, prev_y);
	player->pos_x = player->pos_x_array * WIN_W / cubed->map_width;
	player->pos_y = player->pos_y_array * WIN_H / cubed->map_height;
	update_player_dir(cubed, player);
}

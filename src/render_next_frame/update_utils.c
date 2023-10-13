/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:24:24 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/13 20:26:18 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	read_mouse_input(t_cubed *cubed)
{
	int	mouse_x;
	int	mouse_y;

	mlx_mouse_get_pos(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, \
		&mouse_x, &mouse_y);
	if (mouse_x > WIN_W / 2)
	{
		cubed->player->angle -= SENSITIVITY;
		if (cubed->player->angle < 0)
			cubed->player->angle = 360;
	}
	else if (mouse_x < WIN_W / 2)
	{
		cubed->player->angle += SENSITIVITY;
		if (cubed->player->angle > 360)
			cubed->player->angle = 0;
	}
}

void	read_key_input(t_cubed *cubed)
{
	if (cubed->keys->right && !cubed->keys->left)
	{
		cubed->player->angle -= SENSITIVITY * 0.1;
		if (cubed->player->angle < 0)
			cubed->player->angle = 360;
	}
	else if (cubed->keys->left && !cubed->keys->right)
	{
		cubed->player->angle += SENSITIVITY * 0.1;
		if (cubed->player->angle > 360)
			cubed->player->angle = 0;
	}
}

void	update_player_dir(t_cubed *cubed, t_player *player)
{
	player->dir_x = cos(player->angle * M_PI / 180);
	player->dir_y = -sin(player->angle * M_PI / 180);
	player->dir_x_pos = player->pos_x + player->dir_x * RAY_LENGHT;
	player->dir_y_pos = player->pos_y + player->dir_y * RAY_LENGHT;
	player->left_plane_x = cos((player->angle + 45) * M_PI / 180);
	player->left_plane_y = -sin((player->angle + 45) * M_PI / 180);
	player->left_plane_x_pos = player->pos_x + player->left_plane_x \
								* (RAY_LENGHT + RAY_LENGHT * 0.4);
	player->left_plane_y_pos = player->pos_y + player->left_plane_y \
								* (RAY_LENGHT + RAY_LENGHT * 0.4);
	player->right_plane_x = cos((player->angle - 45) * M_PI / 180);
	player->right_plane_y = -sin((player->angle - 45) * M_PI / 180);
	player->right_plane_x_pos = player->pos_x + player->right_plane_x \
								* (RAY_LENGHT + RAY_LENGHT * 0.4);
	player->right_plane_y_pos = player->pos_y + player->right_plane_y \
								* (RAY_LENGHT + RAY_LENGHT * 0.4);
	(void)cubed;
}

void	check_borders(t_player *player)
{
	if (player->pos_y < 0)
		player->pos_y = 0;
	if (player->pos_y > WIN_H)
		player->pos_y = WIN_H;
	if (player->pos_x < 0)
		player->pos_x = 0;
	if (player->pos_x > WIN_W)
		player->pos_x = WIN_W;
}

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
	int	mouse_x;
	int	mouse_y;

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
	mlx_mouse_get_pos(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, &mouse_x, &mouse_y);
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
	mlx_mouse_move(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, WIN_W / 2, WIN_H / 2);
}

static void	update_player_dir(t_cubed *cubed, t_player *player)
{
	player->dir_x = cos(player->angle * M_PI / 180);
	player->dir_y = -sin(player->angle * M_PI / 180);
	player->dir_x_pos = player->pos_x + player->dir_x * RAY_LENGHT;
	player->dir_y_pos = player->pos_y + player->dir_y * RAY_LENGHT;
	player->left_plane_x = cos((player->angle + 45) * M_PI / 180);
	player->left_plane_y = -sin((player->angle + 45) * M_PI / 180);
	player->left_plane_x_pos = player->pos_x + player->left_plane_x * (RAY_LENGHT + RAY_LENGHT * 0.4);
	player->left_plane_y_pos = player->pos_y + player->left_plane_y * (RAY_LENGHT + RAY_LENGHT * 0.4);
	player->right_plane_x = cos((player->angle - 45) * M_PI / 180);
	player->right_plane_y = -sin((player->angle - 45) * M_PI / 180);
	player->right_plane_x_pos = player->pos_x + player->right_plane_x * (RAY_LENGHT + RAY_LENGHT * 0.4);
	player->right_plane_y_pos = player->pos_y + player->right_plane_y * (RAY_LENGHT + RAY_LENGHT * 0.4);
	(void)cubed;
}

void	update_player_pos(t_cubed *cubed, t_keys *keys, t_player *player)
{
	if (keys->w && !keys->s)
	{
		player->pos_x += cos(player->angle * M_PI / 180) * VELOCITY;
		player->pos_y -= sin(player->angle * M_PI / 180) * VELOCITY;
	}
	if (keys->s && !keys->w)
	{
		player->pos_x -= cos(player->angle * M_PI / 180) * VELOCITY;
		player->pos_y += sin(player->angle * M_PI / 180) * VELOCITY;
	}
	if (keys->a && !keys->d)
	{
		player->pos_x += cos((player->angle + 90) * M_PI / 180) * VELOCITY;
		player->pos_y -= sin((player->angle + 90) * M_PI / 180) * VELOCITY;
	}
	if (keys->d && !keys->a)
	{
		player->pos_x -= cos((player->angle + 90) * M_PI / 180) * VELOCITY;
		player->pos_y += sin((player->angle + 90) * M_PI / 180) * VELOCITY;
	}
	if (player->pos_y < 0)
		player->pos_y = 0;
	if (player->pos_y > WIN_H)
		player->pos_y = WIN_H;
	if (player->pos_x < 0)
		player->pos_x = 0;
	if (player->pos_x > WIN_W)
		player->pos_x = WIN_W;
	player->pos_x_array = player->pos_x * cubed->map_width / WIN_W;
	player->pos_y_array = player->pos_y * cubed->map_height / WIN_H;
	update_player_dir(cubed, player);
}

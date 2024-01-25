/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:24:24 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/25 23:56:15 by hiper            ###   ########.fr       */
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
	player->plane_vector_x = cos((player->angle + 90) * M_PI / 180);
	player->plane_vector_y = -sin((player->angle + 90) * M_PI / 180);
	(void)cubed;
}

void	move_player(t_player *player, t_keys *keys)
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
}

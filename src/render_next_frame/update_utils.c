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

//	need to redo map allocation, otherwise this can segfault
void	check_borders(t_cubed *cubed, t_player *player, float prev_x, float prev_y)
{
	char	**map;

	map = cubed->map;
	if ((int)player->pos_y_array < cubed->map_height \
		&& (int)player->pos_x_array <= (int)ft_strlen(map[(int)player->pos_y_array]) \
		&& map[(int)player->pos_y_array][(int)player->pos_x_array] == '1')
	{
		if ((int)prev_x != (int)player->pos_x_array && (int)prev_y != (int)player->pos_y_array)
		{
			ft_printf_fd(1, "hit on xy\n");
		}
		else if ((int)prev_x != (int)player->pos_x_array)
		{
			ft_printf_fd(1, "hit on x\n");
		}
		else if ((int)prev_y != (int)player->pos_y_array)
		{
			ft_printf_fd(1, "hit on y\n");
		}
	}
}

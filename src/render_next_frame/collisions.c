/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:42:51 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/17 16:43:22 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	check_borders(t_cubed *cubed, t_player *player, \
// 	double prev_x, double prev_y)
// {
// 	char	**map;

// 	map = cubed->map;
// 	if (prev_y != player->pos_y_array \
// 		&& map[(int)player->pos_y_array][(int)prev_x] == '1')
// 	{
// 		if (player->pos_y_array > prev_y)
// 			prev_y = (int)player->pos_y_array - 0.1;
// 		else
// 			prev_y = (int)prev_y + 0.1;
// 		player->pos_y_array = prev_y;
// 	}
// 	if (prev_x != player->pos_x_array \
// 		&& map[(int)player->pos_y_array][(int)player->pos_x_array] == '1')
// 	{
// 		if (player->pos_x_array > prev_x)
// 			prev_x = (int)player->pos_x_array - 0.1;
// 		else
// 			prev_x = (int)prev_x + 0.1;
// 		player->pos_x_array = prev_x;
// 	}
// }

void	check_borders(t_cubed *cubed, t_player *player, \
	double prev_x, double prev_y)
{
	if (cubed->map[(int)player->pos_y_array][(int)player->pos_x_array] == '1')
	{
		if (cubed->keys->w && !cubed->keys->s)
		{
			player->pos_x_array -= (cos(player->angle * M_PI / 180) \
									* VELOCITY) / 30;
			player->pos_y_array += (sin(player->angle * M_PI / 180) \
									* VELOCITY) / 30;
		}
		if (cubed->keys->s && !cubed->keys->w)
		{
			player->pos_x_array += (cos(player->angle * M_PI / 180) \
									* VELOCITY) / 30;
			player->pos_y_array -= (sin(player->angle * M_PI / 180) \
									* VELOCITY) / 30;
		}
		if (cubed->keys->a && !cubed->keys->d)
		{
			player->pos_x_array -= (cos((player->angle + 90) * M_PI / 180) \
									* VELOCITY) / 30;
			player->pos_y_array += (sin((player->angle + 90) * M_PI / 180) \
									* VELOCITY) / 30;
		}
		if (cubed->keys->d && !cubed->keys->a)
		{
			player->pos_x_array += (cos((player->angle + 90) * M_PI / 180) \
									* VELOCITY) / 30;
			player->pos_y_array -= (sin((player->angle + 90) * M_PI / 180) \
									* VELOCITY) / 30;
		}
	}
	(void)prev_x;
	(void)prev_y;
}

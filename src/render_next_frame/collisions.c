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

static void	check_walk(t_player *player, t_keys *keys)
{
	if (keys->w && !keys->s)
	{
		player->pos_x_array -= (cos(player->angle * M_PI / 180) \
								* VELOCITY) / 30;
		player->pos_y_array += (sin(player->angle * M_PI / 180) \
								* VELOCITY) / 30;
	}
	if (keys->s && !keys->w)
	{
		player->pos_x_array += (cos(player->angle * M_PI / 180) \
								* VELOCITY) / 30;
		player->pos_y_array -= (sin(player->angle * M_PI / 180) \
								* VELOCITY) / 30;
	}
}

static void	check_strafe(t_player *player, t_keys *keys)
{
	if (keys->a && !keys->d)
	{
		player->pos_x_array -= (cos((player->angle + 90) * M_PI / 180) \
								* VELOCITY) / 30;
		player->pos_y_array += (sin((player->angle + 90) * M_PI / 180) \
								* VELOCITY) / 30;
	}
	if (keys->d && !keys->a)
	{
		player->pos_x_array += (cos((player->angle + 90) * M_PI / 180) \
								* VELOCITY) / 30;
		player->pos_y_array -= (sin((player->angle + 90) * M_PI / 180) \
								* VELOCITY) / 30;
	}
}

void	check_borders(t_cubed *cubed, t_player *player, t_keys *keys)
{
	if (cubed->map[(int)player->pos_y_array][(int)player->pos_x_array] == '1')
	{
		check_walk(player, keys);
		check_strafe(player, keys);
	}
}

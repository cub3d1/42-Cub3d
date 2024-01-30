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

void	check_borders(t_cubed *cubed, t_player *player, \
	double prev_x, double prev_y)
{
	char	**map;

	map = cubed->map;
	if (map[(int)player->pos_y_array][(int)prev_x] == '1')
	{
		if (player->pos_y_array > prev_y)
			prev_y = (int)player->pos_y_array - 0.1;
		else
			prev_y = (int)prev_y + 0.1;
		player->pos_y_array = prev_y;
	}
	if (map[(int)prev_y][(int)player->pos_x_array] == '1')
	{
		if (player->pos_x_array > prev_x)
			prev_x = (int)player->pos_x_array - 0.1;
		else
			prev_x = (int)prev_x + 0.1;
		player->pos_x_array = prev_x;
	}
}

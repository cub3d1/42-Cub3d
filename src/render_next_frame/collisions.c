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
/*
static void	collide_on_x(t_cubed *cubed, t_player *player, float prev_x)
{
	printf("collision on X\n");
	if ((int)player->pos_x_array < (int)prev_x)
	{
		if (prev_x != (int)player->pos_x_array + 1.1)
			player->pos_x_array = (int)player->pos_x_array + 1.1;
		else
			player->pos_x_array = prev_x;
	}
	else
	{
		if (prev_x != (int)player->pos_x_array - 0.1)
			player->pos_x_array = (int)player->pos_x_array - 0.1;
		else
			player->pos_x_array = prev_x;
	}
	player->pos_x = player->pos_x_array / cubed->map_width * WIN_W;
}

static void	collide_on_y(t_cubed *cubed, t_player *player, float prev_y)
{
	printf("collision on Y\n");
	if ((int)player->pos_y_array < (int)prev_y)
	{
		if (prev_y != (int)player->pos_y_array + 1.1)
			player->pos_y_array = (int)player->pos_y_array + 1.1;
	}
	else
	{
		if (prev_y != (int)player->pos_y_array - 0.1)
			player->pos_y_array = (int)player->pos_y_array - 0.1;
	}
	player->pos_y = player->pos_y_array / cubed->map_height * WIN_H;
}
*/
void	check_borders(t_cubed *cubed, t_player *player, \
	double prev_x, double prev_y)
{
	char	**map;
//	int		line_len;

	map = cubed->map;
//	line_len = (int)ft_strlen(map[(int)player->pos_y_array]);
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
//	(void)prev_x;
//	(void)prev_y;
//	(void)map;
/*
	if (player->pos_y_array < 0)
		player->pos_x_array = 0;
	if (player->pos_y_array < 0)
		player->pos_y_array = 0;
*/
/*
	if (player->pos_x >= 0 && player->pos_y >= 0 \
		&& (int)player->pos_y_array < cubed->map_height)
	{
		line_len = (int)ft_strlen(map[(int)player->pos_y_array]);
		if ((int)player->pos_y_array < cubed->map_height \
			&& (int)player->pos_x_array <= line_len \
			&& map[(int)player->pos_y_array][(int)player->pos_x_array] == '1')
		{
			if ((int)prev_x != (int)player->pos_x_array)
				collide_on_x(cubed, player, prev_x);
			if ((int)prev_y != (int)player->pos_y_array)
				collide_on_y(cubed, player, prev_y);
		}
	}
*/
}

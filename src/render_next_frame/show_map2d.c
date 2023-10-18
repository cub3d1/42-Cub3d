/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:52:05 by ddantas-          #+#    #+#             */
/*   Updated: 2023/10/14 23:44:53 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
static void	draw_map_to_canvas(t_cubed *cubed)
{
	draw_walls(cubed->map, cubed->mlx->automap);
	(void)cubed;
}
*/
void	show_player(t_cubed *cubed, t_our_img *player, t_canvas *map)
{
	t_mlx	*mlx;
	int		pos_x;
	int		pos_y;

	mlx = cubed->mlx;
	pos_x = map->pos_x + ((int)cubed->player->pos_x / map->scale) \
						- (player->w / 2);
	pos_y = map->pos_y + ((int)cubed->player->pos_y / map->scale) \
						- (player->h / 2);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	player->img, pos_x, pos_y);
	pos_x = map->pos_x + ((int)cubed->player->dir_x_pos / map->scale \
						- player->w / 2);
	pos_y = map->pos_y + ((int)cubed->player->dir_y_pos / map->scale \
						- player->h / 2);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	player->img, pos_x, pos_y);
}

void	show_map2d(t_cubed *cubed, t_canvas *canvas)
{
	mlx_put_image_to_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, \
		canvas->map_img->img, canvas->pos_x, canvas->pos_y);
}

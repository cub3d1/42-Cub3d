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
void	show_map2d(t_cubed *cubed, t_canvas *canvas)
{

	mlx_put_image_to_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, \
		canvas->map_img->img, 0, 0);
	mlx_put_image_to_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, \
		cubed->mlx->minimap_player->img, (int)cubed->player->pos_x, \
		(int)cubed->player->pos_y);
}

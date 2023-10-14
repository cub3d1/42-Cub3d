/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_canvases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:44:03 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/14 18:44:17 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_automap(t_cubed *cubed, t_map2d *automap)
{
	t_our_img	*map_img;

	map_img = automap->map_img;
	map_img->w = WIN_W;
	map_img->h = WIN_H;
	automap->wall_w = (WIN_W / cubed->map_width) + 1;
	automap->wall_h = WIN_H / cubed->map_height;
	map_img->img = mlx_new_image(cubed->mlx->mlx_ptr, map_img->w, map_img->h);
	map_img->addr = mlx_get_data_addr(map_img->img, &map_img->bpp, \
			&map_img->line_length, &map_img->endian);
}

void	init_canvases(t_cubed *cubed)
{
	init_automap(cubed, cubed->mlx->automap);
}
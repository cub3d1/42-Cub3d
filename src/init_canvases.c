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

static void	init_canvas(t_cubed *cubed, t_canvas *canvas, int scale)
{
	t_our_img	*map_img;

	map_img = canvas->map_img;
	map_img->w = WIN_W / scale;
	map_img->h = WIN_H / scale;
	canvas->wall_w = (map_img->w / cubed->map_width);
	canvas->wall_h = (map_img->h / cubed->map_height);
	canvas->pos_x = 0;
	canvas->pos_y = 0;
	canvas->scale = scale;
	map_img->img = mlx_new_image(cubed->mlx->mlx_ptr, map_img->w, map_img->h);
	map_img->addr = mlx_get_data_addr(map_img->img, &map_img->bpp, \
			&map_img->line_length, &map_img->endian);
	if (!map_img->img || !map_img->addr)
		exit_err(cubed, 6);
}

static void	init_sprite(t_cubed *cubed, t_our_img *sprite)
{
	sprite->w = 1;
	sprite->h = 1;
	sprite->img = mlx_new_image(cubed->mlx->mlx_ptr, sprite->w, sprite->h);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp, \
		&sprite->line_length, &sprite->endian);
	if (!sprite->img || !sprite->addr)
		exit_err(cubed, 6);
	*(unsigned int *)sprite->addr = 0x00ffffff;
}

void	init_pre_render(t_cubed *cubed)
{
	t_mlx	*mlx;

	mlx = cubed->mlx;
	init_canvas(cubed, mlx->surfaces, 1);
	init_canvas(cubed, mlx->automap, 1);
//	mlx->automap->wall_w++;
//	mlx->automap->wall_h++;
	init_canvas(cubed, mlx->minimap, 10);
	mlx->minimap->pos_y = WIN_H - (WIN_H / 10);
	init_sprite(cubed, mlx->automap_player);
	init_sprite(cubed, mlx->minimap_player);
	draw_ceiling(mlx->ceiling_color, mlx->surfaces->map_img);
	draw_floor(mlx->floor_color, mlx->surfaces->map_img);
	draw_map2d(cubed->map, mlx->automap);
	draw_map2d(cubed->map, mlx->minimap);
}
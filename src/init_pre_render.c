/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pre_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:44:03 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/17 22:30:01 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_canvas_image(t_cubed *cubed, t_canvas *canvas)
{
	t_our_img	*map_img;

	map_img = canvas->map_img;
	map_img->img = mlx_new_image(cubed->mlx->mlx_ptr, map_img->w, map_img->h);
	map_img->addr = mlx_get_data_addr(map_img->img, &map_img->bpp, \
			&map_img->line_length, &map_img->endian);
	if (!map_img->img || !map_img->addr)
		exit_err(cubed, 6);
}

static void	init_canvas(t_cubed *cubed, t_canvas *canvas, int scale)
{
	t_our_img	*map_img;

	map_img = canvas->map_img;
	canvas->wall_w = ((WIN_W / scale) / cubed->map_width);
	canvas->wall_h = ((WIN_H / scale) / cubed->map_height + 1);
	map_img->w = canvas->wall_w * (cubed->map_width - 1);
	map_img->h = canvas->wall_h * cubed->map_height;
	canvas->pos_x = 0;
	canvas->pos_y = 0;
	canvas->scale = scale;
}

static void	draw_sprite(t_our_img *sprite)
{
	char	*pixel;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < sprite->h)
	{
		while (x < sprite->w)
		{
			pixel = sprite->addr + ((y * sprite->line_length) \
									+ x * (sprite->bpp / 8));
			*(unsigned int *)pixel = 0xffff0000;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	init_sprite(t_cubed *cubed, t_our_img *sprite, t_canvas *map)
{
	sprite->w = (map->wall_w / 8) + 1;
	sprite->h = (map->wall_h / 8) + 1;
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
	mlx->surfaces->map_img->w = WIN_W;
	mlx->surfaces->map_img->h = WIN_H;
	init_canvas(cubed, mlx->automap, 1);
	mlx->automap->pos_x = (WIN_W - mlx->automap->map_img->w) / 2;
	init_canvas(cubed, mlx->minimap, 4);
	mlx->minimap->pos_y = WIN_H - mlx->minimap->map_img->h;
	init_canvas_image(cubed, mlx->surfaces);
	init_canvas_image(cubed, mlx->automap);
	init_canvas_image(cubed, mlx->minimap);
	init_sprite(cubed, mlx->automap_player, mlx->automap);
	init_sprite(cubed, mlx->minimap_player, mlx->minimap);
	draw_map2d(cubed->map, mlx->automap);
	draw_map2d(cubed->map, mlx->minimap);
	draw_sprite(cubed->mlx->automap_player);
	draw_sprite(cubed->mlx->minimap_player);
}

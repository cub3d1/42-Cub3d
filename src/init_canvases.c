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

static void	init_image(t_cubed *cubed, t_canvas *canvas, unsigned int scale)
{
	t_our_img	*map_img;

	map_img = canvas->map_img;
	map_img->w = WIN_W / scale;
	map_img->h = WIN_H / scale;
	canvas->wall_w = (map_img->w / cubed->map_width) + 1;
	canvas->wall_h = (map_img->h / cubed->map_height) + 1;
	map_img->img = mlx_new_image(cubed->mlx->mlx_ptr, map_img->w, map_img->h);
	map_img->addr = mlx_get_data_addr(map_img->img, &map_img->bpp, \
			&map_img->line_length, &map_img->endian);
	if (!map_img->img || !map_img->addr)
		exit_err(cubed, 6);
}

static void	set_map_alpha(t_our_img *map2d)
{
	char	*pixel;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map2d->h)
	{
		while (x < map2d->w)
		{
			pixel = map2d->addr;
			pixel += (y * map2d->line_length) + (x * (map2d->bpp / 8));
			*(unsigned int *)pixel = 0xff000000;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	put_pixels_to_map(t_canvas *map2d, int y, int x)
{
	char	*img_addr;
	int		pix_x;
	int		pix_y;

	img_addr = map2d->map_img->addr;
	pix_x = x;
	pix_y = y;
	while (pix_y < y + map2d->wall_h)
	{
		while (pix_x < x + map2d->wall_w)
		{
			img_addr = map2d->map_img->addr;
			img_addr += (pix_y * map2d->map_img->line_length) + \
			(pix_x * (map2d->map_img->bpp / 8));
			*(unsigned int *)img_addr = 0x00ffffff;
			pix_x++;
		}
		pix_x = x;
		pix_y++;
	}
}

static void	draw_map2d(char **map, t_canvas *map2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	set_map_alpha(map2d->map_img);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
				put_pixels_to_map(map2d, map2d->wall_h * i, map2d->wall_w * j);
			j++;
		}
		j = 0;
		i++;
	}
}

static unsigned int	get_rgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	draw_ceiling(int *ceiling, t_our_img *canvas)
{
	unsigned int	color;
	char *pixel;
	int	x;
	int	y;

	color = get_rgb(0, ceiling[0], ceiling[1], ceiling[2]);
	x = 0;
	y = 0;
	while (y < WIN_H / 2)
	{
		while (x < WIN_W)
		{
			pixel = canvas->addr;
			pixel += (y * canvas->line_length) + (x * (canvas->bpp / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	draw_floor(int *floor, t_our_img *canvas)
{
	unsigned int	color;
	char *pixel;
	int	x;
	int	y;

	color = get_rgb(0, floor[0], floor[1], floor[2]);
	x = 0;
	y = WIN_H / 2;
	while (y < WIN_H)
	{
		while (x < WIN_W)
		{
			pixel = canvas->addr;
			pixel += (y * canvas->line_length) + (x * (canvas->bpp / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		x = 0;
		y++;
	}
}

void	init_canvases(t_cubed *cubed)
{
	t_mlx	*mlx;

	mlx = cubed->mlx;
	init_image(cubed, mlx->surfaces, 1);
	init_image(cubed, mlx->automap, 1);
	init_image(cubed, mlx->minimap, 10);
	draw_ceiling(mlx->ceiling_color, mlx->surfaces->map_img);
	draw_floor(mlx->floor_color, mlx->surfaces->map_img);
	draw_map2d(cubed->map, mlx->automap);
	draw_map2d(cubed->map, mlx->minimap);
}
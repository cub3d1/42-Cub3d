/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:52:25 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/15 12:53:16 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
			img_addr = map2d->map_img->addr + \
			(pix_y * map2d->map_img->line_length) + \
			(pix_x * (map2d->map_img->bpp / 8));
			*(unsigned int *)img_addr = 0x00ffffff;
			pix_x++;
		}
		pix_x = x;
		pix_y++;
	}
}

void	draw_map2d(char **map, t_canvas *map2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

static unsigned int	get_rgb(unsigned char t, unsigned char r, \
	unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	draw_ceiling(int *ceiling, t_our_img *canvas)
{
	unsigned int	color;
	char			*pixel;
	int				x;
	int				y;

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
	char			*pixel;
	int				x;
	int				y;

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

t_our_img	*select_texture(t_mlx *mlx, t_render *ray)
{
	if (ray->hit == 'x')
	{
		if (ray->wall_x < ray->plane_x)
			return (mlx->text_w);
		else if (ray->wall_x > ray->plane_x)
			return (mlx->text_e);
	}
	else if (ray->hit == 'y')
	{
		if (ray->wall_y < ray->plane_y)
			return (mlx->text_n);
		else if (ray->wall_y > ray->plane_y)
			return (mlx->text_s);
	}
}

static void	draw_walls(t_mlx *mlx, t_list *ray)
{
	t_our_img	*texture;

	while (ray)
	{
		texture = select_texture(mlx, ray->content);
/*
		get from render struct:
			section of the texture to extract
			ex:
				if hit == x
					it's (int)(texture->w * (ray->wall_x - (int)ray->wall_x)
			size of column to pre render
		copy pixels from texture to wall
*/
		ray = ray->next;
	}
}

void	pre_render(t_mlx *mlx)
{
	//	pre render floor + ceiling + walls
	draw_ceiling(mlx->ceiling_color, mlx->surfaces->map_img);
	draw_floor(mlx->floor_color, mlx->surfaces->map_img);
	draw_walls(mlx, mlx->renderer);
}
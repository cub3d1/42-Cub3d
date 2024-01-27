/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:14:58 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/25 15:54:49 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	copy_to_buffer(t_our_img *texture, unsigned int *buffer, \
							t_ray *ray, int size)
{
	int		i;
	double	y;
	char	*dst;

	i = 0;
	y = (double)ray->texture_y;
	while (i < size)
	{
		dst = texture->addr + ((int)y * texture->line_length + \
								ray->texture_x * (texture->bpp / 8));
		buffer[i] = *(unsigned int *)dst;
		i++;
		y += ray->render_step;
		if ((int)y > texture->h)
			y = (double)texture->h - 1;
	}
}

static int	slice_on_y(int render_h, int texture_h)
{
	int		render_start;
	double	height_ratio;

	render_start = (render_h / 2) - (WIN_H / 2);
	height_ratio = render_start / render_h;
	return ((int)((double)texture_h * height_ratio));
}

static void	copy_to_canvas(t_canvas *canvas, unsigned int *buffer, 
							t_ray *ray, int size)
{
	int		i;
	int		y;

	i = 0;
	y = ray->canvas_start;
	while (i < size)
	{
		my_mlx_pixel_put(canvas->map_img, ray->canvas_x, y, buffer[i]);
		i++;
		y++;
	}
}

void	pre_render_slice(t_canvas *canvas, t_our_img *texture, t_ray *ray)
{
	int		copy_size;

	copy_size = ray->render_h;
	if (copy_size >= WIN_H)
	{
		copy_size = WIN_H - 1;
		ray->texture_y = slice_on_y(ray->render_h, texture->h);
	}
	ray->texture_y = 0;
	ray->render_step = (double)texture->h / (double)ray->render_h;
	copy_to_buffer(texture, canvas->buffer_array[copy_size - 1], \
					ray, copy_size);
	ray->canvas_start = WIN_H / 2 - copy_size / 2;
	copy_to_canvas(canvas, canvas->buffer_array[copy_size - 1], \
					ray, copy_size);
}

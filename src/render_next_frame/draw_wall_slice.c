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

static int	slice_on_y(int render_h, int texture_h, t_ray *ray)
{
//	int		render_start;
//	double	height_ratio;

	(void)texture_h;
//	render_start = (render_h / 2) - (WIN_H / 2);
//	printf("render_h: %d\nrender_start: %d\n", render_h, render_start);
//	height_ratio = (double)render_start / (double)render_h;
	return ((render_h - WIN_H) / 2 * ray->render_step);
}

static void	copy_to_canvas(t_canvas *canvas, unsigned int *buffer, 
							t_ray *ray, int size)
{
	int		i;
	int		y;

	i = 0;
	y = ray->canvas_start;
	if (y < 0)
		y = 0;
	while (i < size)
	{
//		printf("copying from buffer index: %d\n", i);
//		printf("copying to pixel %d\n", y);
		my_mlx_pixel_put(canvas->map_img, ray->canvas_x, y, buffer[i]);
		i++;
		y++;
	}
//	printf("ray->canvas_start: %d\n", ray->canvas_start);
//	printf("size: %d\n", size);
//	sleep(5);
}

void	pre_render_slice(t_canvas *canvas, t_our_img *texture, t_ray *ray)
{
	int		copy_size;

	copy_size = ray->render_h;
	ray->texture_y = 0;
//	printf("ray->render_h: %d\n", ray->render_h);
	ray->render_step = 1.0 * (double)texture->h / (double)ray->render_h;
	if (copy_size > WIN_H)
	{
		copy_size = WIN_H;
		ray->texture_y = slice_on_y(ray->render_h, texture->h, ray);
	}
//	printf("ray->texture_y: %d\n", ray->texture_y);
	copy_to_buffer(texture, canvas->buffer_array[copy_size - 1], \
					ray, copy_size);
	ray->canvas_start = (WIN_H - 1) / 2 - copy_size / 2;
//	printf("copy_size: %d\n]", copy_size);
	copy_to_canvas(canvas, canvas->buffer_array[copy_size - 1], \
					ray, copy_size);
}

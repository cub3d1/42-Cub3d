/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_slice_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:00:19 by fmouronh          #+#    #+#             */
/*   Updated: 2023/12/29 19:00:34 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	copy_pixels(t_ray *ray, t_canvas *surfaces, t_our_img *texture)
{
	t_our_img		*map_img;
	char			*pixel;

	map_img = surfaces->map_img;
	pixel = map_img->addr + (ray->canvas_y * map_img->line_length) + \
			(ray->canvas_x * (map_img->bpp / 8));
	*(unsigned int *)pixel = *(unsigned int *)(texture->addr + \
			(ray->texture_y * texture->line_length) + \
			(ray->texture_x * (texture->bpp / 8)));
}

void	interpolate_texture(t_ray *ray, t_canvas *surfaces, \
								t_our_img *texture, float ratio)
{
	int	count;
	int	step;

	step = texture->h * (ratio - (int)ratio);
	count = 0;
	while (ray->canvas_y < ray->canvas_end)
	{
		copy_pixels(ray, surfaces, texture);
		ray->canvas_y++;
		count++;
		if (count == step)
		{
			ray->texture_y++;
			count = 0;
		}
	}
}

void	copy_to_canvas(t_ray *ray, t_canvas *surfaces, \
							t_our_img *texture)
{
	while (ray->canvas_y < ray->canvas_end)
	{
		copy_pixels(ray, surfaces, texture);
		ray->texture_y++;
		ray->canvas_y++;
	}
}

void	skip_texture_pixels(t_ray *ray, t_canvas *surfaces, \
						t_our_img *texture, float ratio)
{
	int	step;

	step = (int)ratio;
	if (ratio - (int)ratio <= 0.2f)
		step--;
	if (step == 0 || ratio - (int)ratio >= 0.8f)
		step++;
	while (ray->canvas_y < ray->canvas_end)
	{
		copy_pixels(ray, surfaces, texture);
		ray->texture_y += step;
		if (ray->texture_y > texture->h)
			ray->texture_y = texture->h;
		ray->canvas_y++;
	}
}

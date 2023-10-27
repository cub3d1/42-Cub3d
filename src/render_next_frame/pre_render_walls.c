/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_render_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:24:23 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/27 18:30:25 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	copy_pixels(t_render *ray, t_canvas *surfaces, t_our_img *texture)
{
	t_our_img		*map_img;
	char			*pixel;

	map_img = surfaces->map_img;
	pixel = map_img->addr + (ray->canvas_y * map_img->line_length) + 
			(ray->col * (map_img->bpp / 8));
	*(unsigned int *)pixel = *(unsigned int *)(texture->addr + \
			(ray->texture_y * texture->line_length) + \
			(ray->tex_x * (texture->bpp / 8)));
}

static void	interpolate_texture(t_render *ray, t_canvas *surfaces, \
								t_our_img *texture, float ratio)
{
	int	count;

	ray->step = texture->h / (int)(ratio * 100);
	count = 0;
	while (ray->canvas_y < ray->end_y)
	{
		copy_pixels(ray, surfaces, texture);
		count++;
		if (count == ray->step)
		{
			ray->texture_y++;
			count = 0;
		}
		ray->canvas_y++;
	}
}
static void	copy_to_canvas(t_render *ray, t_canvas *surfaces, \
							t_our_img *texture)
{
	while (ray->canvas_y < ray->end_y)
	{
		copy_pixels(ray, surfaces, texture);
		ray->texture_y++;
		ray->canvas_y++;
	}
}

static void	skip_pixels(t_render *ray, t_canvas *surfaces, \
						t_our_img *texture, float ratio)
{
	int	step;

	step = (int)ratio;
	if (ratio - (int)ratio <= 0.2f)
		step--;
	if (step == 0 || ratio - (int)ratio >= 0.8f)
		step++;
	//	copy pixels
	while (ray->canvas_y < ray->end_y)
	{
		copy_pixels(ray, surfaces, texture);
		ray->texture_y += step;
		if (ray->texture_y > texture->h)
			ray->texture_y = texture->h;
		ray->canvas_y++;
	}
}

void	draw_wall_slice(t_render *ray, t_canvas *surfaces, t_our_img *texture)
{
	float	ratio;

	ray->start_y = (WIN_H / 2) - (ray->render_h / 2);
	ray->end_y = (WIN_H / 2) + (ray->render_h / 2);
	ray->canvas_y = ray->start_y;
	ray->texture_y = 0;
	ratio = (float)texture->h / (float)ray->render_h;
	if (ratio < 1.0f)
		interpolate_texture(ray, surfaces, texture, ratio);
	else if (ratio > 0.8f && ratio < 1.2f)
		copy_to_canvas(ray, surfaces, texture);
	else
		skip_pixels(ray, surfaces, texture, ratio);
	//	fuck... how do I do this without fucking up with the norm?

	//	if pix_step < 1, interpolate texture:

	//	else (ie pix_step >= 1)
	//		copy each y in texture to canvas & add pix_step - (int)pix_step to iterator
	//		when iterator >= 1, skip row
	//	that should work...
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:14:58 by fmouronh          #+#    #+#             */
/*   Updated: 2023/12/29 18:15:18 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_our_img	*select_texture(t_ray *ray, t_mlx *mlx)
{
	if (ray->hit == 'n')
		return (mlx->text_n);
	else if (ray->hit == 's')
		return (mlx->text_s);
	else if (ray->hit == 'e')
		return (mlx->text_e);
	else if (ray->hit == 'w')
		return (mlx->text_w);
	else
		return (NULL);
}

void	set_render_height(t_mlx *mlx, t_ray *ray)
{
	ray->render_h = mlx->proj_plane_height - \
					(mlx->proj_plane_height / ray->wall_dist);
	ray->canvas_start = (WIN_H / 2) - (ray->render_h / 2);
	ray->canvas_end = ray->canvas_start + ray->render_h;
	ray->canvas_y = ray->canvas_start;
}

int	find_texture_x(t_ray *ray, t_our_img *texture)
{
	if (ray->hit == 'n')
		return ((int)(texture->w * (ray->wall_x - (int)ray->wall_x)));
	else if (ray->hit == 's')
		return ((int)(texture->w * (1 - (ray->wall_x - (int)ray->wall_x))));
	else if (ray->hit == 'e')
		return ((int)(texture->w * (1 - (ray->wall_y - (int)ray->wall_y))));
	else if (ray->hit == 'w')
		return ((int)(texture->w * (ray->wall_y - (int)ray->wall_y)));
	else
		return (0);
}

void	pre_render_slice(t_ray *ray, t_our_img *texture, t_canvas *canvas)
{
	float	ratio;

	ratio = (float)texture->h / (float)ray->render_h;
	if (ratio < 1.0f)
		interpolate_texture(ray, canvas, texture, ratio);
	else if (ratio > 0.8f && ratio < 1.2f)
		copy_to_canvas(ray, canvas, texture);
	else
		skip_texture_pixels(ray, canvas, texture, ratio);
}

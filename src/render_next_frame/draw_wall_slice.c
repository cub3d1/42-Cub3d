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

t_our_img	select_texture(t_ray *ray, t_mlx *mlx)
{
	
}

void	set_render_height(t_ray *ray, t_canvas *canvas)
{

}

int	find_texture_x(t_ray *ray, t_our_img *texture)
{

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

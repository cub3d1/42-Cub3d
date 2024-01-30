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

t_our_img	*select_texture(t_ray *ray, t_mlx *mlx)
{
	if (ray->current_wall == 'n')
		return (mlx->text_n);
	else if (ray->current_wall == 's')
		return (mlx->text_s);
	else if (ray->current_wall == 'e')
		return (mlx->text_e);
	else if (ray->current_wall == 'w')
		return (mlx->text_w);
	else
		return (NULL);
}

void	my_mlx_pixel_put(t_our_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

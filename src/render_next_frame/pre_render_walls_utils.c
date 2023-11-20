/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_render_walls_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:31:19 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/27 18:31:51 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_our_img	*select_texture(t_player *player, t_mlx *mlx, t_render *ray)
{
	if (ray->hit == 'x')
	{
		if (ray->wall_x < player->pos_x_array)
			return (mlx->text_w);
		else if (ray->wall_x > player->pos_x_array)
			return (mlx->text_e);
	}
	else if (ray->hit == 'y')
	{
		if (ray->wall_y < player->pos_y_array)
			return (mlx->text_n);
		else if (ray->wall_y > player->pos_y_array)
			return (mlx->text_s);
	}
	return (NULL);
}

//	needs improvement
int	find_tex_x(t_render *ray, t_our_img *texture)
{
	if (ray->hit == 'x')
		return ((int)(texture->w * (ray->wall_x - (int)ray->wall_x)));
	else if (ray->hit == 'y')
		return ((int)(texture->w * (ray->wall_y - (int)ray->wall_y)));
	return (0);
}

float	find_render_h(t_mlx *mlx, t_render *ray, \
							t_our_img *texture, t_player *player)
{
	float	wall_dist;

	wall_dist = sqrt((ray->wall_x - player->pos_x_array) * \
					(ray->wall_x - player->pos_x_array) + \
					(ray->wall_y - player->pos_y_array) * \
					(ray->wall_y - player->pos_y_array));
	(void) texture;
	return (mlx->proj_plane_height - (mlx->proj_plane_height / wall_dist));
}

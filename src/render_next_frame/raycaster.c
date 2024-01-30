/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:38:47 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/29 23:27:34 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	reset_ray(t_ray *ray, t_player *player, int x)
{
	ray->pos_x = (int)player->pos_x_array;
	ray->pos_y = (int)player->pos_y_array;
	ray->hit = '\0';
	ray->canvas_x = x;
	ray->camera_x = (2 * x / (double)WIN_W - 1) * -1;
	ray->ray_dir_x = player->dir_x + player->plane_vector_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_vector_y * ray->camera_x;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->texture_y = 0;
	ray->wall_x = 0;
}

static void	draw_wall_slice(t_ray *ray, t_mlx *mlx)
{
	t_our_img	*texture;

	ray->render_h = (int)(WIN_H / ray->wall_dist);
	if (ray->render_h < 0)
		ray->render_h = INT_MAX;
	texture = select_texture(ray, mlx);
	ray->texture_x = texture->w * ray->wall_x;
	pre_render_slice(mlx->surfaces, texture, ray);
}

void	raycaster(t_cubed *cubed)
{
	t_ray	ray;
	int		x;

	ft_bzero(&ray, sizeof(t_ray));
	x = 0;
	while (x < WIN_W)
	{
		reset_ray(&ray, cubed->player, x);
		cast_ray(cubed, &ray, cubed->player, cubed->map);
		draw_wall_slice(&ray, cubed->mlx);
		x++;
	}
}

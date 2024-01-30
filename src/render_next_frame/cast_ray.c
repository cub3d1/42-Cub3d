/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:38:47 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/29 23:43:31 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_current_wall(t_ray *ray, t_player *player, int side)
{
	if (side == 0)
	{
		if (ray->step_x == -1)
			ray->current_wall = 'w';
		else
			ray->current_wall = 'e';
		ray->wall_x = (player->pos_y_array + ray->wall_dist \
			* ray->ray_dir_y) - (int)(player->pos_y_array + ray->wall_dist \
			* ray->ray_dir_y);
	}
	else
	{
		if (ray->step_y == -1)
			ray->current_wall = 'n';
		else
			ray->current_wall = 's';
		ray->wall_x = (player->pos_x_array + ray->wall_dist \
			* ray->ray_dir_x) - (int)(player->pos_x_array + ray->wall_dist \
			* ray->ray_dir_x);
	}
	if (ray->current_wall == 's' || ray->current_wall == 'w')
		ray->wall_x = 1 - ray->wall_x;
}

static void	find_wall(t_ray *ray, int *side)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->pos_x += ray->step_x;
		*side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->pos_y += ray->step_y;
		*side = 1;
	}
}

void	cast_ray(t_cubed *cubed, t_ray *ray, t_player *player, char **map)
{
	int	side;

	init_delta_dist(ray);
	init_step_side(ray, player);
	side = 0;
	ray->hit = 1;
	while (ray->hit)
	{
		find_wall(ray, &side);
		if (ray->pos_x <= 0 || ray->pos_y <= 0 \
			|| ray->pos_x >= cubed->map_width \
			|| ray->pos_y >= cubed->map_height)
		{
			ray->hit = 0;
			break ;
		}
		if (map[ray->pos_y][ray->pos_x] == '1')
			ray->hit = 0;
	}
	if (!side)
		ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
	get_current_wall(ray, player, side);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:38:47 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/26 00:48:59 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	zero_div_guard(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->ray_dir_x = DBL_MIN;
	if (ray->ray_dir_y == 0)
		ray->ray_dir_y = DBL_MIN;
}

static void	init_delta_dist(t_ray *ray)
{
	zero_div_guard(ray);
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void init_step_side(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x_array - ray->pos_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->pos_x + 1.0 - player->pos_x_array) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y_array - ray->pos_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->pos_y + 1.0 - player->pos_y_array) * ray->delta_dist_y;
	}
}

void get_current_wall(t_ray *ray, t_player *player, int side)
{
	if (side == 0)
	{
		if (ray->step_x == -1)
			ray->current_wall = 'w';
		else
			ray->current_wall = 'e';
		ray->wall_x = (player->pos_y_array + ray->wall_dist * ray->ray_dir_y) - (int)(player->pos_y_array + ray->wall_dist * ray->ray_dir_y);	

	}
	else
	{
		if (ray->step_y == -1)
			ray->current_wall = 'n';
		else
			ray->current_wall = 's';
		ray->wall_x = (player->pos_x_array + ray->wall_dist * ray->ray_dir_x) - (int)(player->pos_x_array + ray->wall_dist * ray->ray_dir_x);	
	}

	printf("ray->wall_x = %lf\n", ray->wall_x);
}

void	cast_ray(t_ray *ray, t_player *player, char **map)
{
	int	side = 0;

	init_delta_dist(ray);
	// printf("ray->delta_dist_x = %lf\n", ray->delta_dist_x);
	// printf("ray->delta_dist_y = %lf\n", ray->delta_dist_y);
	// sleep(1);
	init_step_side(ray, player);
	// printf("ray->side_dist_x = %lf\n", ray->side_dist_x);
	// printf("ray->side_dist_y = %lf\n", ray->side_dist_y);
	
	ray->hit = 1;
	while (ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->pos_x += ray->step_x;
			side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->pos_y += ray->step_y;
			side = 1;
		}
		// printf("step: %d Ray(%d,%d), map = %c\n",++step, ray->pos_x, ray->pos_y, map[ray->pos_y][ray->pos_x]);
		if (map[ray->pos_y][ray->pos_x] == '1')
			ray->hit = 0;
	}
	if (!side)
		ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
	get_current_wall(ray, player, side);
	(void)map;
	(void)player;
}

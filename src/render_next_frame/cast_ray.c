/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:38:47 by fmouronh          #+#    #+#             */
/*   Updated: 2023/12/07 23:26:54 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
/*
static void	init_side_dist(t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->side_dist_x = 1 - (ray->pos_x - (int)ray->pos_x);
		ray->step_x = -1;
	}
	else
	{
		ray->side_dist_x = ray->pos_x - (int)ray->pos_x;
		ray->step_x = 1;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->side_dist_y = 1 - (ray->pos_y - (int)ray->pos_y);
		ray->step_y = -1;
	}
	else
	{
		ray->side_dist_y = ray->pos_y - (int)ray->pos_y;
		ray->step_y = 1;
	}
}

static char	set_ray_pos(t_ray *ray)
{
	if (fabs(ray->delta_dist_x) > fabs(ray->delta_dist_y))
	{
		//	place ray->pos(x,y) at the end of ray->delta_dist_y
		ray->pos_y += step_x;
		ray->pos_x = 
		return ('y');
	}
	else
	{
		//	place ray->pos(x,y) at the end of ray->delta_dist_x
		ray->pos_x += step_y;
		ray->pos_y = 
		return ('x');
	}
}
*/
static void	set_dist_var(t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->dx_pos_x = (int)ray->pos_x;
		ray->step_x = -1;
	}
	else
	{
		ray->dx_pos_x = (int)ray->pos_x + 1;
		ray->step_x = 1;
	}
	if (ray_dir_y < 0)
	{
		ray->dy_pos_y = (int)ray->pos_y;
		ray->step_y = -1;
	}
	else
	{
		ray->dy_pos_y = (int)ray->pos_y + 1;
		ray->step_y = 1;
	}
}

void	cast_ray(t_ray *ray, char **map)
{
	char	delta_dir;

	set_dist_var(ray);
	init_side_dist(ray);
	while (ray->hit == '\0')
	{
		delta_dir = set_ray_pos(ray);
		//	check for wall collision
		//	calculate next ray->delta_dist
	}

	// START COMMENT
	static int x = 0;
	if (x == 0 || x == WIN_W / 2 || x == WIN_W - 1)
	{
		printf("ray->side_dist_x: %f\n", ray->side_dist_x);
		printf("ray->side_dist_y: %f\n\n", ray->side_dist_y);
		if (x == WIN_W - 1)
			x = 0;
		// sleep(2);
	}
	x++;
	// END COMMENT

	(void)map;
}

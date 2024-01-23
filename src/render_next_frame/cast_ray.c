/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:38:47 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/23 20:38:48 by hiper            ###   ########.fr       */
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

static void	init_side_dist(t_ray *ray)
{
	double	ratio;
	double	diff_x;
	double	diff_y;

	zero_div_guard(ray);
	ratio = ray->ray_dir_x / ray->ray_dir_y;
	if (ray->ray_dir_x < 0)
		diff_x = ((ray->pos_x - (int)ray->pos_x) * -1) * ratio;
	else
		diff_x = (1 - (ray->pos_x - (int)ray->pos_x)) * ratio;
	if (ray->ray_dir_y < 0)
		diff_y = ((ray->pos_y - (int)ray->pos_y) * -1) / ratio;
	else
		diff_y = (1 - (ray->pos_y - (int)ray->pos_y)) / ratio;
	ray->dx_pos_y = ray->pos_y + diff_y;
	ray->dy_pos_x = ray->pos_x + diff_x;
	ray->side_dist_x = sqrt((ray->dx_pos_x - ray->pos_x) * \
							(ray->dx_pos_x - ray->pos_x) + \
							(ray->dx_pos_y - ray->pos_y) * \
							(ray->dx_pos_y - ray->pos_y));
	ray->side_dist_y = sqrt((ray->dy_pos_x - ray->pos_x) * \
							(ray->dy_pos_x - ray->pos_x) + \
							(ray->dy_pos_y - ray->pos_y) * \
							(ray->dy_pos_y - ray->pos_y));
/*
	if (ray->canvas_x == 0 || ray->canvas_x == WIN_W / 2 || ray->canvas_x == WIN_W - 1)
	{
		printf("camera_x: %lf\n", ray->camera_x);
		printf("dir_x: %lf\ndir_y: %lf\n", ray->ray_dir_x, ray->ray_dir_y);
		printf("ratio: %lf\n", ratio);
		printf("diffX: %lf\ndiffY: %lf\n", diff_x, diff_y);
		printf("distX:\n\tposX: %lf\n\tposY: %lf\n", ray->dx_pos_x, ray->dx_pos_y);
		printf("distY:\n\tposX: %lf\n\tposY: %lf\n", ray->dy_pos_x, ray->dy_pos_y);
		printf("sidedistX:\n%lf\nsidedistY:\n%lf\n\n", ray->side_dist_x, ray->side_dist_y);
		printf("==============================================\n");
	}
*/
}
/*
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
	if (ray->ray_dir_y < 0)
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

static char	init_ray_pos(t_ray *ray)
{
	if (fabs(ray->side_dist_x) < fabs(ray->side_dist_y))
	{
		ray->pos_x = ray->dx_pos_x;
		ray->pos_y = ray->dx_pos_y;
		return ('x');
	}
	else
	{
		ray->pos_x = ray->dy_pos_x;
		ray->pos_y = ray->dx_pos_y;
		return ('y');
	}
}

static char	check_ray_collision(t_ray *ray, char dir, char **map)
{
	int	array_x;
	int	array_y;

	array_x = (int)ray->pos_x;
	array_y = (int)ray->pos_y;
	ft_printf_fd(1, "\n\n\narray_x: %d\narray_y: %d\n\n\n\n", array_x, array_y);
	if (dir == 'x' && ray->ray_dir_x < 0)
		array_x--;
	if (dir == 'y' && ray->ray_dir_y > 0)
		array_y--;
	if (map[array_y][array_x] == '1')
	{
		if (dir == 'x')
		{
			if (ray->ray_dir_x > 0)
				return ('e');
			else
				return ('w');
		}
		else
		{
			if (ray->ray_dir_y > 0)
				return ('s');
			else
				return ('n');
		}
	}
	else
		return ('\0');
}

static void	get_next_deltas(t_ray *ray)
{
	double	ratio;
	
	double	diff_x;
	double	diff_y;
	ratio = ray->ray_dir_x / ray->ray_dir_y;
	if (ray->ray_dir_x < 0)
		diff_x = ((ray->pos_x - (int)ray->pos_x) * -1) * ratio;
	else
		diff_x = (1 - (ray->pos_x - (int)ray->pos_x)) * ratio;
	if (ray->ray_dir_y < 0)
		diff_y = ((ray->pos_y - (int)ray->pos_y) * -1) / ratio;
	else
		diff_y = (1 - (ray->pos_y - (int)ray->pos_y)) / ratio;
	ray->dx_pos_y = ray->pos_y + diff_y;
	ray->dy_pos_x = ray->pos_x + diff_x;
	ray->side_dist_x += sqrt((ray->dx_pos_x - ray->pos_x) * \
							(ray->dx_pos_x - ray->pos_x) + \
							(ray->dx_pos_y - ray->pos_y) * \
							(ray->dx_pos_y - ray->pos_y));
	ray->side_dist_y += sqrt((ray->dy_pos_x - ray->pos_x) * \
							(ray->dy_pos_x - ray->pos_x) + \
							(ray->dy_pos_y - ray->pos_y) * \
							(ray->dy_pos_y - ray->pos_y));
}

static char	update_ray_pos(t_ray *ray)
{
	if (fabs(ray->side_dist_x) < fabs(ray->side_dist_y))
	{
		ray->pos_x = ray->dx_pos_x;
		ray->pos_y = ray->dx_pos_y;
		return ('x');
	}
	else
	{
		ray->pos_x = ray->dy_pos_x;
		ray->pos_y = ray->dx_pos_y;
		return ('y');
	}
}

void	cast_ray(t_ray *ray, char **map)
{
	char	delta_dir;

	set_dist_var(ray);
	init_side_dist(ray);
	delta_dir = init_ray_pos(ray);
	while (true)
	{
		ray->hit = check_ray_collision(ray, delta_dir, map);
		if (ray->hit)
			break ;
		//	calculate next ray->delta_dist
		get_next_deltas(ray);
		delta_dir = update_ray_pos(ray);
	}
	/*
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
	*/
	(void)delta_dir;
	(void)map;
}

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

void	cast_ray(t_ray *ray, char **map)
{

	ray->side_dist_x = 0;
	if (ray->ray_dir_x > 0)
		ray->side_dist_x = ray->start_x - (int)ray->start_x;
	else
		ray->side_dist_x = 1 - (ray->start_x - (int)ray->start_x);

	if (ray->ray_dir_y > 0)
		ray->side_dist_y = ray->start_y - (int)ray->start_y;
	else
		ray->side_dist_y = 1 - (ray->start_y - (int)ray->start_y);

	
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
	(void)ray;
	(void)map;
	//	do the dda

}

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

static void	reset_ray(t_ray *ray, t_player *player, int x)
{
	ray->hit = '\0';
	ray->canvas_x = x;
	ray->camera_x = 2 * x / (double)WIN_W - 1;
	ray->ray_dir_x = player->dir_x + player->plane_vector_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_vector_y * ray->camera_x;
	ray->step_x = 0;
	ray->step_y = 0;

	// START COMMENT
	if (x == 0 || x == WIN_W / 2 || x == WIN_W - 1)
	{
		printf("ray->camera_x: %f\n", ray->camera_x);
		printf("ray->ray_dir_x: %f\n", ray->ray_dir_x);
		printf("ray->ray_dir_y: %f\n\n", ray->ray_dir_y);
		// sleep(2);
	}
	// END COMMENT
}

// START COMMENT
static void	get_dist(t_ray *ray)
{
	//	calculate ray->perp_{x,y} & distance from ray->wall_{x,y}
	(void)ray;
}

static void	draw_wall_slice(t_ray *ray, t_mlx *mlx)
{
	t_our_img	*texture;

	//	select texture
	texture = select_texture(ray, mlx);
	//	get start x and y for canvas + render height
	set_render_height(mlx, ray);
	//	get texture X & init texture Y
	ray->texture_y = 0;
	ray->texture_x = find_texture_x(ray, texture);
	//	draw slice
//	pre_render_slice(ray, texture, mlx->surfaces);
}
// END COMMENT
void raycaster(t_cubed *cubed)
{
	t_ray	ray;
	int		x;

	ft_bzero(&ray, sizeof(t_ray));
	x = 0;
	while (x < WIN_W)
	{
		ray.pos_x = cubed->player->pos_x_array;
		ray.pos_y = cubed->player->pos_y_array;
		reset_ray(&ray, cubed->player, x);
		cast_ray(&ray, cubed->map);
// START COMMENT
		get_dist(&ray);
		draw_wall_slice(&ray, cubed->mlx);
// END COMMENT
		x++;
	}
}

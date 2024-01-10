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

static void	update_vectors(t_rwf *rwf, t_player *player, int x)
{
	rwf->cameraX = 2 * x / (double)WIN_W - 1;
	rwf->rayDirX = player->dir_x + player->plane_vector_x * rwf->cameraX;
	rwf->rayDirY = player->dir_y + player->plane_vector_y * rwf->cameraX;
	if (rwf->rayDirX == 0)
		rwf->rayDirX = 0.00000000001;
	if (rwf->rayDirY == 0)
		rwf->rayDirY = 0.00000000001;
	rwf->deltaDistX = sqrt(1 + (rwf->rayDirY * rwf->rayDirY) \
							/ (rwf->rayDirX * rwf->rayDirX));
	rwf->deltaDistY = sqrt(1 + (rwf->rayDirX * rwf->rayDirX) \
							/ (rwf->rayDirY * rwf->rayDirY));
}

*/

static void	init_ray_dir(t_ray *ray, t_player *player, int x)
{
	ray->canvas_x = x;
	ray->camera_x = 2 * x / (double)WIN_W - 1;
	ray->ray_dir_x = player->dir_x + player->plane_vector_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_vector_y * ray->camera_x;
	
	if (x == 0 || x == WIN_W / 2 || x == WIN_W - 1)
	{
		printf("ray->camera_x: %f\n", ray->camera_x);
		printf("ray->ray_dir_x: %f\n", ray->ray_dir_x);
		printf("ray->ray_dir_y: %f\n\n", ray->ray_dir_y);
		// sleep(2);
	}
	
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
	//	get texture X
	ray->texture_x = find_texture_x(ray, texture);
	//	draw slice
	pre_render_slice(ray, texture, mlx->surfaces);
}
// END COMMENT
void raycaster(t_cubed *cubed)
{
	t_ray	ray;
	int		x;

	ft_bzero(&ray, sizeof(t_ray));
	ray.start_x = cubed->player->pos_x_array;
	ray.start_y = cubed->player->pos_y_array;
	x = 0;
	while (x < WIN_W)
	{
		init_ray_dir(&ray, cubed->player, x);
		cast_ray(&ray, cubed->map);
// START COMMENT
		get_dist(&ray);
		draw_wall_slice(&ray, cubed->mlx);
// END COMMENT
		x++;
	}

}

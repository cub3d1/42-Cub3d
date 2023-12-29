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

/*
static void	get_dist(t_ray *ray)
{
	//	calculate ray->perp_{x,y} + distance from ray->wall_{x,y}
}

static void	draw_wall_slice(t_ray *ray, t_mlx *mlx, int x)
{
	t_our_img	*texture;
	float		ratio;

	//	select texture
	texture = select_texture(ray);
	//	get start & end Y for canvas (render height)

	//	get texture X
	//	get ratio (texture height / render height)
	ratio = (float)texture->h / (float)(ray->canvas_end - ray->canvas_start);
	//	draw slice accordingly
}
*/
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
		// ft_printf_fd(1, "Ray %d:\n", x);
		init_ray_dir(&ray, cubed->player, x);
		cast_ray(&ray, cubed->map);
		/*
		get_dist(ray);
		draw_wall_slice(ray, cubed->mlx, x);
		*/
		x++;
	}

}

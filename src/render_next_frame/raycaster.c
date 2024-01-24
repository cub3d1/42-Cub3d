/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:38:47 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/23 22:11:24 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	reset_ray(t_ray *ray, t_player *player, int x)
{
	ray->dx_pos_x = 0;
	ray->dx_pos_y = 0;
	ray->dy_pos_x = 0;
	ray->dy_pos_y = 0;
	ray->hit = '\0';
	ray->canvas_x = x;
	ray->camera_x = 2 * x / (double)WIN_W - 1;
	ray->ray_dir_x = player->dir_x + player->plane_vector_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_vector_y * ray->camera_x;
	ray->step_x = 0;
	ray->step_y = 0;

}

// START COMMENT
static void	get_dist(t_ray *ray, t_player *player)
{
	//	calculate ray->perp_{x,y} & distance from ray->wall_{x,y}
	double delta_dist;
	double side_dist;
	// 1 - player
	// 2 - raio
	// d = √[(x2 − x1)2 + (y2 − y1)2]
	if (ray->hit == 'w' || ray->hit == 'e')
		side_dist = ray->side_dist_x;
	else
		side_dist = ray->side_dist_y;
	
	delta_dist = sqrt((ray->pos_x - player->pos_x_array) * \
					  (ray->pos_x - player->pos_x_array) + \
					  (ray->pos_y - player->pos_y_array) * \
					  (ray->pos_y - player->pos_y_array)) - \
					  side_dist;

	ray->wall_dist = delta_dist - side_dist;
	printf("ray pos:\n\tx: %lf\n\ty: %lf\nplayer pos:\n\tx: %lf\n\ty: %lf\n", ray->pos_x, ray->pos_y, player->pos_x_array, player->pos_y_array);
	printf("delta dist: %lf\nside dist: %lf\n", delta_dist, side_dist);
	printf("dist: %lf\n", ray->wall_dist);
//	sleep(5);
}
/*
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
*/
// END COMMENT
void raycaster(t_cubed *cubed)
{
	t_ray	ray;
	int		x;

	ft_bzero(&ray, sizeof(t_ray));
	x = 0;
	ray.pos_x = cubed->player->pos_x_array;
	ray.pos_y = cubed->player->pos_y_array;
	while (x < WIN_W)
	{
		reset_ray(&ray, cubed->player, x);
		cast_ray(&ray, cubed->player, cubed->map);
// START COMMENT
		get_dist(&ray, cubed->player);
//		draw_wall_slice(&ray, cubed->mlx);
// END COMMENT
		x++;
	}
//	sleep(5);
}

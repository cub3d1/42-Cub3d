/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:38:47 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/26 00:46:00 by hiper            ###   ########.fr       */
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

// static void	draw_wall_slice(t_ray *ray, t_mlx *mlx)
// {
// 	t_our_img	*texture;

// 	//	select texture
// 	texture = select_texture(ray, mlx);
// 	//	get start x and y for canvas + render height
// 	set_render_height(mlx, ray);
// 	//	get texture X & init texture Y
// 	ray->texture_y = 0;
// 	ray->texture_x = find_texture_x(ray, texture);
// 	//	draw slice
// 	pre_render_slice(ray, texture, mlx->surfaces);
// }

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

static void draw_wall_slice(t_ray *ray, t_mlx *mlx)
{
	t_our_img	*texture;

	ray->render_h = (int)(WIN_H / ray->wall_dist);
	if (ray->render_h < 0)
		ray->render_h = INT_MAX;
	//TEXTURES
	texture = select_texture(ray, mlx);
	ray->texture_x = texture->w * ray->wall_x;
	// sleep(1);
	//	COPY FROM TEXTURE TO BUFFER
	pre_render_slice(mlx->surfaces, texture, ray);
/*
	int color = 0; 
	if (ray->current_wall == 'w')
		color = create_trgb(0, 0, 255, 0);
	else if (ray->current_wall == 'e')
		color = create_trgb(0, 160, 32, 240);
	else if (ray->current_wall == 'n')
		color = create_trgb(0, 115, 40, 40);
	else if (ray->current_wall == 's')
		color = create_trgb(0, 150, 105, 25);
	
	// ray->step_y = texture->w / (ray->canvas_end - ray->canvas_start);
	// ray->texture_y = 1;
	// color = mlx_get_color_value(mlx->mlx_ptr, *(unsigned int*)texture->addr + (1 * texture->line_length + ray->texture_x * (texture->bpp / 8)));
	while (ray->canvas_start <= ray->canvas_end)
	{

		my_mlx_pixel_put(mlx->surfaces->map_img, ray->canvas_x, ray->canvas_start++, color);	
		// ray->texture_y += ray->step_y;
	}
*/
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
//		printf("ray nr %d ==============================\n", x);
		reset_ray(&ray, cubed->player, x);
		cast_ray(&ray, cubed->player, cubed->map);
		// sleep(1);
		draw_wall_slice(&ray, cubed->mlx);
		x++;
	}
//	sleep(5);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:38:47 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/26 00:00:43 by hiper            ###   ########.fr       */
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

void	my_mlx_pixel_put(t_our_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

static void draw_wall_slice(t_ray *ray, t_mlx *mlx)
{
	int 		line_height;
	t_our_img	*texture;

	line_height = (int)(WIN_H / ray->wall_dist);
	ray->canvas_start = -line_height / 2 + WIN_H / 2;
	if(ray->canvas_start < 0)
		ray->canvas_start = 0;
		
	ray->canvas_end = line_height / 2 + WIN_H / 2;
	if(ray->canvas_end >= WIN_H)
		ray->canvas_end = WIN_H - 1;
	//TEXTURES
	texture = select_texture(ray, mlx);


	//THIS FUCKS OFF
	int color = 0x00FFFFFF; 
	if (ray->current_wall == 'w')
		color = create_trgb(0, 0, 255, 0);
	else if (ray->current_wall == 'e')
		color = create_trgb(0, 160, 32, 240);
	else if (ray->current_wall == 'n')
		color = create_trgb(0, 115, 40, 40);
	else if (ray->current_wall == 's')
		color = create_trgb(0, 150, 105, 25);
	
	while (ray->canvas_start < ray->canvas_end)
		my_mlx_pixel_put(mlx->surfaces->map_img, ray->canvas_x, ray->canvas_start++, color);	
	(void)texture;
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
		// printf("ray nr %d\n", x);
		reset_ray(&ray, cubed->player, x);
		cast_ray(&ray, cubed->player, cubed->map);
		// sleep(1);
		draw_wall_slice(&ray, cubed->mlx);
		x++;
	}
//	sleep(5);
}

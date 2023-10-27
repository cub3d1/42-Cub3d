/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:52:25 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/27 17:52:15 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	put_pixels_to_map(t_canvas *map2d, int y, int x)
{
	char	*img_addr;
	int		pix_x;
	int		pix_y;

	img_addr = map2d->map_img->addr;
	pix_x = x;
	pix_y = y;
	while (pix_y < y + map2d->wall_h)
	{
		while (pix_x < x + map2d->wall_w)
		{
			img_addr = map2d->map_img->addr + \
			(pix_y * map2d->map_img->line_length) + \
			(pix_x * (map2d->map_img->bpp / 8));
			*(unsigned int *)img_addr = 0x00ffffff;
			pix_x++;
		}
		pix_x = x;
		pix_y++;
	}
}

void	draw_map2d(char **map, t_canvas *map2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
				put_pixels_to_map(map2d, map2d->wall_h * i, map2d->wall_w * j);
			j++;
		}
		j = 0;
		i++;
	}
}

// static unsigned int	get_rgb(unsigned char t, unsigned char r, (here was a \)
// 	unsigned char g, unsigned char b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// static void	draw_ceiling(int *ceiling, t_our_img *canvas)
// {
// 	unsigned int	color;
// 	char			*pixel;
// 	int				x;
// 	int				y;

// 	color = get_rgb(0, ceiling[0], ceiling[1], ceiling[2]);
// 	x = 0;
// 	y = 0;
// 	while (y < WIN_H / 2)
// 	{
// 		while (x < WIN_W)
// 		{
// 			pixel = canvas->addr;
// 			pixel += (y * canvas->line_length) + (x * (canvas->bpp / 8));
// 			*(unsigned int *)pixel = color;
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }

// static void	draw_floor(int *floor, t_our_img *canvas)
// {
// 	unsigned int	color;
// 	char			*pixel;
// 	int				x;
// 	int				y;

// 	color = get_rgb(0, floor[0], floor[1], floor[2]);
// 	x = 0;
// 	y = WIN_H / 2;
// 	while (y < WIN_H)
// 	{
// 		while (x < WIN_W)
// 		{
// 			pixel = canvas->addr;
// 			pixel += (y * canvas->line_length) + (x * (canvas->bpp / 8));
// 			*(unsigned int *)pixel = color;
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }

// static t_our_img	*select_texture(t_player *player, t_mlx *mlx, t_render *ray)
// {
// 	if (ray->hit == 'x')
// 	{
// 		if (ray->wall_x < player->pos_x_array)
// 			return (mlx->text_w);
// 		else if (ray->wall_x > player->pos_x_array)
// 			return (mlx->text_e);
// 	}
// 	else if (ray->hit == 'y')
// 	{
// 		if (ray->wall_y < player->pos_y_array)
// 			return (mlx->text_n);
// 		else if (ray->wall_y > player->pos_y_array)
// 			return (mlx->text_s);
// 	}
// 	return (NULL);
// }

// static int	find_tex_x(t_render *ray, t_our_img *texture)
// {
// 	if (ray->hit == 'x')
// 		return ((int)(texture->w * (ray->wall_x - (int)ray->wall_x)));
// 	else if (ray->hit == 'y')
// 		return ((int)(texture->w * (ray->wall_y - (int)ray->wall_y)));
// 	return ('\0');
// }

// static int	find_render_h(t_mlx *mlx, t_render *ray, (here was a \)
// 							t_our_img *texture, t_player *player)
// {
// 	float	wall_dist;

// 	wall_dist = sqrt((ray->wall_x - player->pos_x_array) * (here was a \)
// 					(ray->wall_x - player->pos_x_array) + (here was a \)
// 					(ray->wall_y - player->pos_y_array) * (here was a \)
// 					(ray->wall_y - player->pos_y_array));
// 	return ((int)((mlx->proj_plane_height * texture->h) / wall_dist));
// }
/*
	wall_dist = sqrt((ray->wall_x - player->pos_x_array) * \
					(ray->wall_x - player->pos_x_array) + \
					(ray->wall_y - player->pos_y_array) * \
					(ray->wall_y - player->pos_y_array));
	return ((int)((mlx->proj_plane_height * texture->h) / wall_dist));
}

static void	interpolate_texture(t_render *ray, t_canvas *surfaces, \
								t_our_img *texture, float ratio)
{
	int	step;

	step = texture->h / (int)(ratio * 100);
	//	copy pixels
}

static void	copy_to_canvas(t_render *ray, t_canvas *surfaces, \
							t_our_img *texture)
{
	//	copy pixels
}

static void	skip_pixels(t_render *ray, t_canvas *surfaces, \
						t_our_img *texture, float ratio)
{
	int	step;

	step = (int)ratio;
	if (ratio - (int)ratio <= 0.2f)
		step--;
	if (step == 0 || ratio - (int)ratio >= 0.8f)
		step++;
	//	copy pixels
}

static void	draw_wall_slice(t_render *ray, t_canvas *surfaces, t_our_img *texture)
{
	float	ratio;

	ratio = (float)texture->h / (float)ray->render_h;
	if (ratio < 1.0f)
		interpolate_texture(ray, surfaces, texture, ratio);
	else if (ratio > 0.8f && ratio < 1.2f)
		copy_to_canvas(ray, surfaces, texture);
	else
		skip_pixels(ray, surfaces, texture, ratio);
	//	fuck... how do I do this without fucking up with the norm?

	//	start drawing wall at (WIN_H / 2) - (render_h / 2)
	//	if pix_step < 1, interpolate texture:
	//		at each iteration add pix_step to iterator
	//			& move to next y in texture when iterator >= 1
	//	else (ie pix_step >= 1)
	//		copy each y in texture to canvas & add pix_step - (int)pix_step to iterator
	//		when iterator >= 1, skip row
	//	that should work...
}
*/
// static void	draw_walls(t_cubed *cubed, t_mlx *mlx, t_list *raycast)
// {
// 	t_render	*ray;
// 	t_our_img	*texture;

// 	while (raycast)
// 	{
// 		ray = raycast->content;
// 		texture = select_texture(cubed->player, mlx, ray);
// 		ray->tex_x = find_tex_x(ray, texture);
// 		ray->render_h = find_render_h(mlx, ray, texture, cubed->player);
// //		draw_wall_slice(ray, mlx->surfaces, texture);
// /*
// 		get from render struct:
// 			section of the texture to extract
// 			ex:
// 				if hit == x
// 					it's (int)(texture->w * (ray->wall_x - (int)ray->wall_x)
// 			size of column to pre render
// 		copy pixels from texture to wall
// */
// 		raycast = raycast->next;
// 	}
// }

// void	pre_render(t_cubed *cubed)
// {
// 	t_mlx	*mlx;

// 	mlx = cubed->mlx;
// 	//	pre render floor + ceiling + walls
// 	draw_ceiling(mlx->ceiling_color, mlx->surfaces->map_img);
// 	draw_floor(mlx->floor_color, mlx->surfaces->map_img);
// 	draw_walls(cubed, mlx, mlx->renderer);
// }
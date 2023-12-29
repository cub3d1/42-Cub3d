/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:52:25 by fmouronh          #+#    #+#             */
/*   Updated: 2023/12/07 23:27:26 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static unsigned int	get_rgb(unsigned char t, unsigned char r, \
	unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	draw_ceiling(int *ceiling, t_our_img *canvas)
{
	unsigned int	color;
	char			*pixel;
	int				x;
	int				y;

	color = get_rgb(0, ceiling[0], ceiling[1], ceiling[2]);
	x = 0;
	y = 0;
	while (y < WIN_H / 2)
	{
		while (x < WIN_W)
		{
			pixel = canvas->addr;
			pixel += (y * canvas->line_length) + (x * (canvas->bpp / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	draw_floor(int *floor, t_our_img *canvas)
{
	unsigned int	color;
	char			*pixel;
	int				x;
	int				y;

	color = get_rgb(0, floor[0], floor[1], floor[2]);
	x = 0;
	y = WIN_H / 2;
	while (y < WIN_H)
	{
		while (x < WIN_W)
		{
			pixel = canvas->addr;
			pixel += (y * canvas->line_length) + (x * (canvas->bpp / 8));
			*(unsigned int *)pixel = color;
			x++;
		}
		x = 0;
		y++;
	}
}
/*
static void	print_struct_data(t_render *ray)
{
	printf("ray %d\n", ray->col);
	printf("ray->wall_x\t=\t%f\n", ray->wall_x);
	printf("ray->wall_y\t=\t%f\n", ray->wall_y);
	printf("ray->plane_x\t=\t%f\n", ray->plane_x);
	printf("ray->plane_y\t=\t%f\n", ray->plane_y);
	printf("ray->hit\t=\t%c\n", ray->hit);
	printf ("\n");
	(void)ray;
}
*/
/*
static void	draw_walls(t_cubed *cubed, t_mlx *mlx, t_list *raycast)
{
	t_render	*ray;
	t_our_img	*texture;

	while (raycast)
	{
		ray = raycast->content;
		print_struct_data(ray);
		texture = select_texture(cubed->player, mlx, ray);
		ray->tex_x = find_tex_x(ray, texture);
		ray->render_h = find_render_h(mlx, ray, texture, cubed->player);
		if (ray->render_h < 1)
			ray->render_h = 1;
//		ft_printf_fd(1, "%d\n", ray->render_h);
		draw_wall_slice(ray, mlx->surfaces, texture);
		raycast = raycast->next;
	}
//	exit_err(cubed, 0);
}
*/
void	pre_render(t_cubed *cubed)
{
	t_mlx	*mlx;

	mlx = cubed->mlx;
	draw_ceiling(mlx->ceiling_color, mlx->surfaces->map_img);
	draw_floor(mlx->floor_color, mlx->surfaces->map_img);
}

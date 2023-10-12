/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minimap_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:50:13 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/12 17:50:57 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	put_pixels_to_wall(t_our_img *wall, int w, int h)
{
	char	*pix;
	char	*pix_dst;
	int		x;
	int		y;

	pix = wall->addr;
	x = 0;
	y = 0;
	while (y < h)
	{
		while (x < w)
		{
			pix_dst = pix + (y * wall->line_length + x * (wall->bpp / 8));
			*(unsigned int *)pix_dst = 0x00ffffff;
			x++;
		}
		x = 0;
		y++;
	}
}

void	set_minimap_walls(t_cubed *cubed)
{
	t_mlx	*mlx;

	mlx = cubed->mlx;
	mlx->minimap_wall->w = WIN_W / ((int)get_biggest_line(cubed->map) - 1);
	mlx->minimap_wall->h = WIN_H / (int)get_array_size(cubed->map);
	mlx->minimap_wall->img = mlx_new_image(mlx->mlx_ptr, mlx->minimap_wall->w, \
		mlx->minimap_wall->h);
	mlx->minimap_wall->addr = mlx_get_data_addr(mlx->minimap_wall->img, \
		&mlx->minimap_wall->bpp, &mlx->minimap_wall->line_length, \
		&mlx->minimap_wall->endian);
	put_pixels_to_wall(mlx->minimap_wall, mlx->minimap_wall->w, \
		mlx->minimap_wall->h);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_automap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:52:05 by ddantas-          #+#    #+#             */
/*   Updated: 2023/10/01 11:05:53 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	put_pixels_to_canvas(t_map2d *automap, int y, int x)
{
	char	*img_addr;
	int		pix_x;
	int		pix_y;

	img_addr = automap->map_img->addr;
	pix_x = x;
	pix_y = y;
	while (pix_y < y + automap->wall_h)
	{
		while (pix_x < x + automap->wall_w)
		{
			img_addr = automap->map_img->addr;
			img_addr += (pix_y * automap->map_img->line_length) + \
			(pix_x * (automap->map_img->bpp / 8));
			*(unsigned int *)img_addr = 0x00ffffff;
			pix_x++;
		}
		pix_x = x;
		pix_y++;
	}
}

static void	draw_walls(char **map, t_map2d *automap)
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
				put_pixels_to_canvas(automap, automap->wall_h * i, automap->wall_w * j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	show_automap(t_cubed *cubed)
{
	mlx_clear_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr);
	draw_walls(cubed->map, cubed->mlx->automap);
	mlx_put_image_to_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, \
		cubed->mlx->automap->map_img->img, 0, 0);
	mlx_put_image_to_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, \
		cubed->mlx->minimap_player->img, (int)cubed->player->pos_x, \
		(int)cubed->player->pos_y);
	(void)cubed;
}

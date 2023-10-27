/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_render_map2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:26:03 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/27 18:27:03 by fmouronh         ###   ########.fr       */
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

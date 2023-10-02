/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:52:05 by ddantas-          #+#    #+#             */
/*   Updated: 2023/10/01 11:05:53 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_walls(char **map, t_mlx *mlx)
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
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->minimap_wall->img, mlx->minimap_wall->w * j, mlx->minimap_wall->h * i);
			j++;
		}
		j = 0;
		i++;
	}
}

void show_minimap(t_cubed *cubed, int minimap)
{
	if (minimap++ == 0)
		mlx_clear_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr);
	mlx_put_image_to_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, cubed->mlx->minimap_player, \
				(int)cubed->player->pos_x, (int)cubed->player->pos_y);
	draw_walls(cubed->map, cubed->mlx);
	(void)cubed;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:52:05 by ddantas-          #+#    #+#             */
/*   Updated: 2023/10/01 09:51:54 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void show_minimap(t_cubed *cubed, int minimap)
{
	if (minimap++ == 0)
		mlx_clear_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr);
	mlx_put_image_to_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, cubed->mlx->minimap_player, \
				(int)cubed->player->pos_x, (int)cubed->player->pos_y);
	(void)cubed;
}
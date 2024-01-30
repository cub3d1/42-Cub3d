/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/25 17:58:29 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	render_next_frame(t_cubed *cubed)
{
	t_mlx		*mlx;

	mlx = cubed->mlx;
	update_angle(cubed);
	update_player_pos(cubed, cubed->keys, cubed->player);
	if (!cubed->keys->show_automap)
	{
		pre_render(cubed);
		raycaster(cubed);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
			mlx->surfaces->map_img->img, 0, 0);
		if (cubed->keys->show_minimap)
		{
			show_map2d(cubed, cubed->mlx->minimap);
			show_player(cubed, cubed->mlx->minimap_player, cubed->mlx->minimap);
		}
	}
	else
	{
		mlx_clear_window(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr);
		show_map2d(cubed, cubed->mlx->automap);
		show_player(cubed, cubed->mlx->automap_player, cubed->mlx->automap);
	}
	return (0);
}

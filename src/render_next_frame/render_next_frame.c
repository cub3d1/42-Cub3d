/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/27 17:22:35 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_info(t_cubed *cubed, int frame_counter)
{
	char	*frame;

	frame = ft_itoa(frame_counter);
	ft_printf_fd(1, "frame = %s |", frame);
	free(frame);
	// printf("p.pos_x = %.1f |", cubed->player->pos_x);
	// printf("p.pos_y = %.1f |", cubed->player->pos_y);
	// printf("p.dir_x = %.1f |", cubed->player->dir_x);
	// printf("p.dir_y = %.1f |", cubed->player->dir_y);
	// printf("p.left_planeX = %.1f |", cubed->player->left_planeX);
	// printf("p.left_planeY = %.1f |", cubed->player->left_planeY);
	// printf("p.right_planeX = %.1f |", cubed->player->right_planeX);
	// printf("p.right_planeY = %.1f |", cubed->player->right_planeY);
	// printf("p.pos_x_array = %.1f |", cubed->player->pos_x_array);
	// printf("p.pos_y_array = %.1f |", cubed->player->pos_y_array);
	// printf("angle = %.1f |", cubed->player->angle);
	printf("\n");
	(void)cubed; (void)frame_counter;
}

int	render_next_frame(t_cubed *cubed)
{
	static int	frame_counter = 1;
	t_mlx	*mlx;

	// if (frame_counter == 1)
	// {
	// cubed->player->angle = 45;
	// cubed->player->dir_x = cos(cubed->player->angle * M_PI / 180);
	// cubed->player->dir_y = sin(cubed->player->angle * M_PI / 180);
	// } 
	// Para tirar depois de resolve bug do deltaX e deltaY

	mlx = cubed->mlx;
	update_angle(cubed);
	update_player_pos(cubed, cubed->keys, cubed->player);
	if (!cubed->keys->show_automap)
	{
		raycaster(cubed);
		// pre_render(cubed);
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
	print_info(cubed, frame_counter++);
	return (0);
}

/*				

O---------------+ x
|
|
|
|
|
+y


*/
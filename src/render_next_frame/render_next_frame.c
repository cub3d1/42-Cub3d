/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/01 18:35:47 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_rgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	draw_ceiling(t_mlx *mlx, int *color_c)
{
	int	w;
	int	h;
	int	color;

	w = 0;
	while (w < WIN_W)
	{
		h = 0;
		while (h < WIN_H / 2)
		{
			color = get_rgb(0, color_c[0], color_c[1], color_c[2]);
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, w, h, color);
			h++;
		}
		w++;
	}
}

static void	draw_floor(t_mlx *mlx, int *color_f)
{
	int	w;
	int	h;
	int	color;

	w = 0;
	while (w < WIN_W)
	{
		h = WIN_H / 2;
		while (h < WIN_H)
		{
			color = get_rgb(0, color_f[0], color_f[1], color_f[2]);
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, w, h, color);
			h++;
		}
		w++;
	}
}

static void print_cubes(t_cubed *cubed, t_mlx *mlx, t_player *player)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	mlx->minimap_player, (int)player->pos_x, (int)player->pos_y);

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	mlx->green_ball, player->dir_x_pos, player->dir_y_pos);

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	mlx->black_ball, player->left_planeX_pos, player->left_planeY_pos);

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	mlx->black_ball, player->right_planeX_pos, player->right_planeY_pos);
	(void)cubed;
}

void	print_info(t_cubed *cubed, int frame_counter)
{
	// char	*frame;

	// frame = ft_itoa(frame_counter);
	// ft_printf_fd(1, "frame = %s |", frame);
	// free(frame);
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
	// printf("\n");
	(void)cubed; (void)frame_counter;
}



int	render_next_frame(t_cubed *cubed)
{
	static int	frame_counter = 1;
	
	update_angle(cubed);
	update_player_pos(cubed, cubed->keys, cubed->player);
	if (!cubed->keys->show_minimap)
	{
		draw_ceiling(cubed->mlx, cubed->mlx->ceiling_color);
		draw_floor(cubed->mlx, cubed->mlx->floor_color);
		print_cubes(cubed, cubed->mlx, cubed->player);
	}
	else
		show_minimap(cubed);


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
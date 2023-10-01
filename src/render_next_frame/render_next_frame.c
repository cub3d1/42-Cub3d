/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/01 11:11:35 by hiper            ###   ########.fr       */
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

void	print_info(t_cubed *cubed, int frame_counter)
{
	// char	*frame;

	// frame = ft_itoa(frame_counter);
	// ft_printf_fd(1, "frame = %s | ", frame);
	// free(frame);
	// printf("p.pos_x = %f | ", cubed->player->pos_x);
	// printf("p.pos_y = %f | ", cubed->player->pos_y);
	// printf("show_minimap = %d | ", cubed->keys->show_minimap);
	// printf("w = %d | ", cubed->keys->w);
	// printf("a = %d | ", cubed->keys->a);
	// printf("s = %d | ", cubed->keys->s);
	// printf("d = %d | ", cubed->keys->d);
	// printf("angle = %f | ", cubed->player->angle);
	// printf("\n");
	(void)cubed; (void)frame_counter;
}

int	render_next_frame(t_cubed *cubed)
{
	static int	frame_counter = 1;
	static int	minimap = 0;
	
	update_angle(cubed);
	update_player_pos(cubed, cubed->keys);
	if (!cubed->keys->show_minimap)
	{
		if (minimap > 0)
			minimap = 0;
		draw_ceiling(cubed->mlx, cubed->mlx->ceiling_color);
		draw_floor(cubed->mlx, cubed->mlx->floor_color);
	}
	else
		show_minimap(cubed, minimap++);

	print_info(cubed, frame_counter++);
	return (0);
}
/*				
				-Y
				|   /
				|  /
				| /
				|/
-x -------------P---------------+ x
				|
				|
				|
				|
				|
				+y


		*/

	// Draw walls must get player pos and direction
	// And then draw the correct walls that the play can see
	// draw_walls(cubed);

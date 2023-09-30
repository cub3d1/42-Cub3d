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
	int w;
	int h;
	int color;

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
	char	*frame;

	frame = ft_itoa(frame_counter);
	ft_printf_fd(1, "frame = %s | ", frame);
	free(frame);
	printf("p.pos_x = %f | ", cubed->player->pos_x);
	printf("p.pos_y = %f\n", cubed->player->pos_y);
	(void)cubed;
}

int	render_next_frame(t_cubed *cubed)
{
	static int	frame_counter = 1;

	draw_ceiling(cubed->mlx, cubed->mlx->ceiling_color);
	draw_floor(cubed->mlx, cubed->mlx->floor_color);	


	// Draw walls must get player pos and direction
	// And then draw the correct walls that the play can see
	// draw_walls(cubed);
	print_info(cubed, frame_counter++);
	return (0);
}
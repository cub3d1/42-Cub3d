#include "../../include/cub3d.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void draw_ceiling(t_cubed *cubed)
{
	int w;
	int h;
	int color;

	w = 0;
	while (w < WIN_W)
	{
		h = 0;
		while (h < WIN_H / 2)
		{
			color = create_trgb(0, cubed->mlx->ceiling_color[0], \
				cubed->mlx->ceiling_color[1], cubed->mlx->ceiling_color[2]);
			mlx_pixel_put(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, w, h, color);
			h++;
		}
		w++;
	}	
}

static void	draw_floor(t_cubed *cubed)
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
			color = create_trgb(0, cubed->mlx->floor_color[0], \
				cubed->mlx->floor_color[1], cubed->mlx->floor_color[2]);
			mlx_pixel_put(cubed->mlx->mlx_ptr, cubed->mlx->win_ptr, w, h, color);
			h++;
		}
		w++;
	}
}


void	print_info(t_cubed *cubed, int frame_counter)
{
	char	*frame;

	frame = ft_itoa(frame_counter);
	ft_printf_fd(1, "frame = %s\n", frame);
	free(frame);
	// ft_printf_fd(1, "p.pos_x = %s\n", cubed->player->pos_x);
	(void)cubed;
}

int	render_next_frame(t_cubed *cubed)
{
	static int	frame_counter = 1;

	draw_ceiling(cubed);
	draw_floor(cubed);	


	// Draw walls must get player pos and direction
	// And then draw the correct walls that the play can see
	// draw_walls(cubed);
	print_info(cubed, frame_counter++);
	return (0);
}
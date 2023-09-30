#include "../../include/cub3d.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	render_next_frame(t_cubed *cubed)
{
	int w;
	int h;
	int color;

	/* draw ceiling */
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
	/* draw floor */
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
	(void)cubed;
	return (0);
}
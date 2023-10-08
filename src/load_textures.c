/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:26:58 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/01 14:36:15 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


static void	put_pixels_to_wall(t_our_img *minimap_wall, int w, int h)
{
	char	*pix;
	char	*pix_dst;
	int		x;
	int		y;

	pix = minimap_wall->addr;
	x = 0;
	y = 0;
	while (y < h)
	{
		while (x < w)
		{
			pix_dst = pix + (y * minimap_wall->line_length + x * (minimap_wall->bpp / 8));
			*(unsigned int *)pix_dst = 0x00ffffff;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	set_minimap_walls(t_cubed *cubed)
{
	t_mlx	*mlx;

	mlx = cubed->mlx;
	mlx->minimap_wall->w = WIN_W / ((int)get_biggest_line(cubed->map) - 1);
	mlx->minimap_wall->h = WIN_H / (int)get_array_size(cubed->map);
	mlx->minimap_wall->img = mlx_new_image(mlx->mlx_ptr, mlx->minimap_wall->w, mlx->minimap_wall->h);
	mlx->minimap_wall->addr = mlx_get_data_addr(mlx->minimap_wall->img, &mlx->minimap_wall->bpp, &mlx->minimap_wall->line_length, &mlx->minimap_wall->endian);
	put_pixels_to_wall(mlx->minimap_wall, mlx->minimap_wall->w, mlx->minimap_wall->h);
}

static void	set_texture(t_cubed *cubed, t_mlx *mlx, t_our_img *img, char *line)
{
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	line[ft_strlen(line) - 1] = '\0';
	img->img = mlx_xpm_file_to_image(mlx->mlx_ptr, line, &img->w, &img->h);
	if (!img->img)
	{
		ft_printf_fd(1, "Error\nTexture '%s' not found\n");
		exit_err(cubed, 4);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	if (!img->addr)
	{
		ft_printf_fd(1, "Error\nTexture '%s' adress failed\n");
		exit_err(cubed, 4);
	}
}

void	load_textures(t_cubed *cubed, char *arg)
{
	int		fd;
	char	*line;
	t_our_img	*temp_img;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit_err(cubed, 2);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			set_texture(cubed, cubed->mlx, cubed->mlx->text_n, line);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			set_texture(cubed, cubed->mlx, cubed->mlx->text_s, line);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			set_texture(cubed, cubed->mlx, cubed->mlx->text_e, line);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			set_texture(cubed, cubed->mlx, cubed->mlx->text_w, line);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		exit_err(cubed, 3);
	set_minimap_walls(cubed);
	
	temp_img = cubed->mlx->minimap_player;
	temp_img->img = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, TEMP_MINIMAP_PLAYER, &temp_img->w, &temp_img->h);
	temp_img->addr = mlx_get_data_addr(temp_img->img, &temp_img->bpp, &temp_img->line_length, &temp_img->endian);
	if (!cubed->mlx->minimap_player->img || !cubed->mlx->minimap_player->addr)
		exit_err(cubed, 4);	

	temp_img = cubed->mlx->green_ball;
	temp_img->img = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, GREEN_BALL, &temp_img->w, &temp_img->h);
	temp_img->addr = mlx_get_data_addr(temp_img->img, &temp_img->bpp, &temp_img->line_length, &temp_img->endian);
	if (!cubed->mlx->green_ball->img || !cubed->mlx->green_ball->addr)
		exit_err(cubed, 4);

	temp_img = cubed->mlx->black_ball;
	temp_img->img = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, BLACK_BALL, &temp_img->w, &temp_img->h);
	temp_img->addr = mlx_get_data_addr(temp_img->img, &temp_img->bpp, &temp_img->line_length, &temp_img->endian);
	if (!cubed->mlx->black_ball->img || !cubed->mlx->black_ball->addr)
		exit_err(cubed, 4);

	cubed->player->left_planeX = 0;
	cubed->player->left_planeY = 0.66;

	cubed->player->right_planeX = 0;
	cubed->player->right_planeY = 0.66;
}

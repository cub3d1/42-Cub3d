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

static void	set_texture(t_cubed *cubed, char *line, int option)
{
	int		width;
	int		height;
	void	*texture;

	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	line[ft_strlen(line) - 1] = '\0';
	texture = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, line, &width, &height);
	if (!texture)
		ft_printf_fd(1, "Error\nTexture '%s' not found\n", line);
	if (option == 1)
		cubed->mlx->text_n = texture;
	else if (option == 2)
		cubed->mlx->text_s = texture;
	else if (option == 3)
		cubed->mlx->text_e = texture;
	else if (option == 4)
		cubed->mlx->text_w = texture;
}

static void	put_pixels_to_wall(t_minimap_wall *minimap_wall, int w, int h)
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
	write(1, "\n\n\n\nhello\n\n\n", 11);
	mlx->minimap_wall->w = WIN_W / ((int)get_biggest_line(cubed->map) - 1);
	mlx->minimap_wall->h = WIN_H / (int)get_array_size(cubed->map);
	mlx->minimap_wall->img = mlx_new_image(mlx->mlx_ptr, mlx->minimap_wall->w, mlx->minimap_wall->h);
	mlx->minimap_wall->addr = mlx_get_data_addr(mlx->minimap_wall->img, &mlx->minimap_wall->bpp, &mlx->minimap_wall->line_length, &mlx->minimap_wall->endian);
	put_pixels_to_wall(mlx->minimap_wall, mlx->minimap_wall->w, mlx->minimap_wall->h);
}

void	load_textures(t_cubed *cubed, char *arg)
{
	int		fd;
	char	*line;
	int		width;
	int		height;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit_err(cubed, 2);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			set_texture(cubed, line, 1);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			set_texture(cubed, line, 2);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			set_texture(cubed, line, 3);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			set_texture(cubed, line, 4);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		exit_err(cubed, 3);
	set_minimap_walls(cubed);
	cubed->mlx->minimap_player = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, TEMP_MINIMAP_PLAYER, &width, &height);
	if (!cubed->mlx->text_n || !cubed->mlx->text_s
		|| !cubed->mlx->text_e || !cubed->mlx->text_w
		|| !cubed->mlx->minimap_player)
		exit_err(cubed, 4);	

		

	cubed->mlx->green_ball = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, GREEN_BALL, &width, &height);
	cubed->mlx->black_ball = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, BLACK_BALL, &width, &height);
	if (!cubed->mlx->green_ball || !cubed->mlx->black_ball)
		exit(99);

	cubed->player->left_planeX = 0;
	cubed->player->left_planeY = 0.66;

	cubed->player->right_planeX = 0;
	cubed->player->right_planeY = 0.66;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:26:58 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/15 23:24:39 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	load_image(t_cubed *cubed, t_our_img *img, char *texture)
{
	t_mlx	*mlx;

	mlx = cubed->mlx;
	img->img = mlx_xpm_file_to_image(mlx->mlx_ptr, texture, &img->w, &img->h);
	if (!img->img)
	{
		ft_printf_fd(2, "Error\nTexture '%s' not found\n", texture);
		exit_err(cubed, 4);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
		&img->line_length, &img->endian);
	if (!img->addr)
	{
		ft_printf_fd(2, "Error\nTexture '%s' adress failed\n", texture);
		exit_err(cubed, 4);
	}
}

static void	set_texture(t_cubed *cubed, t_our_img *img, char *line)
{
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	line[ft_strlen(line) - 1] = '\0';
	load_image(cubed, img, line);
}

static void	load_wall_textures(t_cubed *cubed, char *arg)
{
	int			fd;
	char		*line;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit_err(cubed, 2);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			set_texture(cubed, cubed->mlx->text_n, line);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			set_texture(cubed, cubed->mlx->text_s, line);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			set_texture(cubed, cubed->mlx->text_e, line);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			set_texture(cubed, cubed->mlx->text_w, line);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		exit_err(cubed, 3);
}

void	load_textures(t_cubed *cubed, char *arg)
{
	load_wall_textures(cubed, arg);
	cubed->player->left_plane_x = 0;
	cubed->player->left_plane_y = 0.66;
	cubed->player->right_plane_x = 0;
	cubed->player->right_plane_y = 0.66;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:26:58 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/01 14:09:18 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	set_texture(t_cubed *cubed, void *texture, char *line)
{
	int		width;
	int		height;
	// char	*tmp;

	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
/*
	width and height are the dimensions of the image in pixels that is returned by the function
	it's defined by the size of the image, not the function

	width = n map cols / WIN_W
	height = n map rows / WIN_H
*/
	
	// texture = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, line, &width, &height);
	// if (!texture)
		// ft_printf_fd(1, "Error\nTexture '%s' not found\n", line);
	(void)cubed->mlx->mlx_ptr;
	(void)width;
	(void)height;
	(void)texture;
}

void	load_textures(t_cubed *cubed, char *arg)
{
	int		fd;
	char	*line;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit_err(cubed, 2);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			set_texture(cubed->mlx->mlx_ptr, &cubed->mlx->text_n, line);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			set_texture(cubed->mlx->mlx_ptr, &cubed->mlx->text_s, line);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			set_texture(cubed->mlx->mlx_ptr, &cubed->mlx->text_e, line);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			set_texture(cubed->mlx->mlx_ptr, &cubed->mlx->text_w, line);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		exit_err(cubed, 3);
	//	load images for minimap
}


void load_tmp_textures(t_cubed *cubed)
{
	int width;
	int height;

	cubed->mlx->minimap_player =  mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, TEMP_MINIMAP_PLAYER, &width, &height);
	cubed->mlx->text_n = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, "./textures/walls/North_wall_temp.xpm", &width, &height);
	cubed->mlx->text_s = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, "./textures/walls/South_wall_temp.xpm", &width, &height);
	cubed->mlx->text_e = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, "./textures/walls/West_wall_temp.xpm", &width, &height);
	cubed->mlx->text_w = mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, "./textures/walls/West_wall_temp.xpm", &width, &height);
	if (!cubed->mlx->text_n || !cubed->mlx->text_s
		|| !cubed->mlx->text_e || !cubed->mlx->text_w)
		exit_err(cubed, 4);
	
}
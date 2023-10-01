/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:26:58 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/01 01:42:27 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// static void	set_texture(void *mlx_ptr, void *texture, char *line)
// {
// 	while (*line != ' ')
// 		line++;
// 	while (*line == ' ')
// 		line++;
// 	(void)mlx_ptr;
// 	(void)texture;
// /*
// 	width = n map cols / WIN_W
// 	height = n map rows / WIN_H

// 	texture = mlx_xpm_file_to_image(mlx_ptr, line, int *width, int *height);
// */
// }

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
		// if (ft_strncmp(line, "NO ", 3) == 0)
		// 	set_texture(cubed->mlx->mlx_ptr, cubed->mlx->text_n, line);
		// else if (ft_strncmp(line, "SO ", 3) == 0)
		// 	set_texture(cubed->mlx->mlx_ptr, cubed->mlx->text_s, line);
		// else if (ft_strncmp(line, "EA ", 3) == 0)
		// 	set_texture(cubed->mlx->mlx_ptr, cubed->mlx->text_e, line);
		// else if (ft_strncmp(line, "WE ", 3) == 0)
		// 	set_texture(cubed->mlx->mlx_ptr, cubed->mlx->text_w, line);
		free(line);
		line = get_next_line(fd);
	}
	// if (!cubed->mlx->text_n || !cubed->mlx->text_s
	// 	|| !cubed->mlx->text_e || !cubed->mlx->text_w)
	// 	exit_err(cubed, 4);
	if (close(fd) == -1)
		exit_err(cubed, 3);
	//	load images for minimap
}
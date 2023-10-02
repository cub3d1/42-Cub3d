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

static void set_texture(t_cubed *cubed, char *line, int option)
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

void load_textures(t_cubed *cubed, char *arg)
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
	cubed->mlx->minimap_player =  mlx_xpm_file_to_image(cubed->mlx->mlx_ptr, TEMP_MINIMAP_PLAYER, &width, &height);
	if (!cubed->mlx->text_n || !cubed->mlx->text_s
		|| !cubed->mlx->text_e || !cubed->mlx->text_w || !cubed->mlx->minimap_player)
		exit_err(cubed, 4);
	
}
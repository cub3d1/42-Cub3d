/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/30 23:22:07 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_line_spaces(char *line)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	return (i);
}

static void	get_color(t_cubed *cubed, char *line, int *color)
{
	char	**split;

	split = NULL;
	line += get_line_spaces(line);
	split = ft_split(line, ',');
	if (!split)
		exit_err(cubed, 4);
	if (split[0] && split[1] && split[2] && !split[3])
	{
		color[0] = ft_atoi(split[0]);
		color[1] = ft_atoi(split[1]);
		color[2] = ft_atoi(split[2]);
	}
	else
	{
		ft_free_split(split);
		exit_err(cubed, 1);
	}
	ft_free_split(split);
}

void	load_colors(t_cubed *cubed, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "F ", 2) == 0)
			get_color(cubed, line, cubed->mlx->floor_color);
		else if (ft_strncmp(line, "C ", 2) == 0)
			get_color(cubed, line, cubed->mlx->ceiling_color);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
}

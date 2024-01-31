/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/30 19:21:14 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	find_map_start(int map_fd)
{
	int		i;
	char	*line;

	i = skip_elems(map_fd);
	while (true)
	{
		line = get_next_line(map_fd);
		i++;
		if (!line || ft_strchr(line, '1'))
			break ;
		free(line);
	}
	if (line)
		free(line);
	return (i);
}

static int	get_map_height(int map_fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(map_fd);
	while (line && ft_strchr(line, '1'))
	{
		i++;
		free(line);
		line = get_next_line(map_fd);
	}
	if (line)
		free(line);
	return (i);
}

static void	skip_to_map(int map_fd, int map_offset)
{
	int	i;

	i = 0;
	while (i < map_offset)
	{
		free(get_next_line(map_fd));
		i++;
	}
}

static void	get_map_to_array(t_cubed *cubed, int map_fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (i < cubed->map_height)
	{
		line = get_next_line(map_fd);
		cubed->map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	if (line)
		free(line);
}

void	load_map(t_cubed *cubed, char *path)
{
	int		map_fd;
	int		map_offset;

	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		exit_err(cubed, 2);
	map_offset = find_map_start(map_fd) - 1;
	cubed->map_height = get_map_height(map_fd) + 1;
	if (close(map_fd) == -1)
		exit_err(cubed, 3);
	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		exit_err(cubed, 2);
	cubed->map = ft_calloc(cubed->map_height + 1, sizeof(char *));
	if (!cubed->map)
		exit_err(cubed, 5);
	skip_to_map(map_fd, map_offset);
	get_map_to_array(cubed, map_fd);
}

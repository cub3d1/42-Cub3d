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

static int	get_max_map_lines(t_cubed *cubed, char *path)
{
	int		map_fd;
	char	*line;
	int		max_line;

	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		exit_err(cubed, 2);
	line = NULL;
	max_line = 0;
	line = get_next_line(map_fd);
	while (line)
	{
		free(line);
		line = get_next_line(map_fd);
		max_line++;
	}
	if (close(map_fd) == -1)
		exit_err(cubed, 3);
	return (max_line);
}

void	advance_gnl_to_map(int map_fd)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		free(get_next_line(map_fd));
		i++;
	}
}

static void	get_map_to_array(int map_fd, int max_line, t_cubed *cubed)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(map_fd);
	while (i < max_line)
	{
		cubed->map[i] = (char *)ft_strdup(line);
		free(line);
		line = NULL;
		if (++i < max_line)
			line = get_next_line(map_fd);
	}
	if (line != NULL)
		free(line);
}

// void print_map(t_cubed *cubed)
// {
// 	int i;

// 	i = 0;
// 	while (cubed->map[i])
// 	{
// 		ft_printf_fd(1, "%s", cubed->map[i]);
// 		i++;
// 	}
// }

int	load_map(t_cubed *cubed, char *path)
{
	int		map_fd;
	int		max_line;

	max_line = get_max_map_lines(cubed, path);
	map_fd = open(path, O_RDONLY);
	if (map_fd == -1)
		exit_err(cubed, 2);
	cubed->map = (char **)ft_calloc(sizeof(char *), (max_line - 8 + 1));
	advance_gnl_to_map(map_fd);
	get_map_to_array(map_fd, max_line - 8, cubed);
	if (close(map_fd) == -1)
		exit_err(cubed, 3);
	return (0);
}

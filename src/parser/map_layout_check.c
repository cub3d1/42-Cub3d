/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_layout_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:46:02 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/25 08:46:22 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	find_map_offset(char *arg)
{
	int		map_fd;
	char	*line;
	int		i;

	map_fd = open(arg, O_RDONLY);
	if (map_fd == -1)
		exit(2);
	line = get_next_line(map_fd);
	i = 0;
	while (line)
	{
		if (ft_strchr(line, '1'))
		{
			free(line);
			return (i);
		}
		i++;
		free(line);
		line = get_next_line(map_fd);
	}
	//	read file until map is found, return line nr

	if (close(map_fd) == -1)
		exit(3);
	return (-1);
}
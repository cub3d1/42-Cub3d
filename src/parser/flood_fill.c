/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:19:39 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/28 02:20:09 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	flood_fill(char **map, int x, int y)
{
	if ((x < 0 || y < 0) || (!map[y] || !map[y][x] || map[y][x] == '\n')
		|| (map[y][x] != '0'))
		return ;
	map[y][x] = '_';
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y + 1);
}

bool	flood_fill_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '_')
			{
				if (!map[i + 1])
					return (false);
				else if ((int)ft_strlen(map[i + 1]) <= j)
					return (false);
				else if (map[i + 1][j] == ' ' || map[i - 1][j] == ' '
					|| map[i][j + 1] == ' ' || map[i][j - 1] == ' '
					|| map[i + 1][j] == '\n' || map[i - 1][j] == '\n'
					|| (map[i][j + 1] && map[i][j + 1] == '\n'))
					return (false);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (true);
}

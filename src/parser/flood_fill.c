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

static bool	is_player_token(char tkn)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tkn == PLAYER_TKNS[i])
			return (true);
		i++;
	}
	return (false);
}

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
			if (map[i][j] == '0'
				&& (map[i + 1][j] == ' ' || map[i - 1][j] == ' '
				|| map[i][j + 1] == ' ' || map[i][j - 1] == ' '))
				return (false);
			j++;
		}
		j = 0;
		i++;
	}
}

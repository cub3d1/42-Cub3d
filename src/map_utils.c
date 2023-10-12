/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:13:45 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/12 17:14:10 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	get_biggest_line(char **map)
{
	int		i;
	int		j;
	int		biggest;

	i = 0;
	biggest = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > biggest)
			biggest = j;
		i++;
	}
	return ((float)biggest);
}

float	get_array_size(char **map)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (map[i])
	{
		size++;
		i++;
	}
	return ((float)size);
}

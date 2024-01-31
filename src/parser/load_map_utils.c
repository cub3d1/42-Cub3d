/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:24:51 by fmouronh          #+#    #+#             */
/*   Updated: 2024/01/31 12:25:03 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	elem_check(bool elems[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (elems[i] == false)
			return (false);
		i++;
	}
	return (true);
}

int	skip_elems(int map_fd)
{
	char	*line;
	bool	elems[6];
	int		i;

	i = 0;
	ft_bzero(elems, 6 * sizeof(bool));
	while (!elem_check(elems))
	{
		line = get_next_line(map_fd);
		if (!ft_strncmp("NO ", line, 3))
			elems[ELEM_NO] = true;
		else if (!ft_strncmp("SO ", line, 3))
			elems[ELEM_SO] = true;
		else if (!ft_strncmp("EA ", line, 3))
			elems[ELEM_EA] = true;
		else if (!ft_strncmp("WE ", line, 3))
			elems[ELEM_WE] = true;
		else if (!ft_strncmp("C ", line, 2))
			elems[ELEM_C] = true;
		else if (!ft_strncmp("F ", line, 2))
			elems[ELEM_F] = true;
		free(line);
		i++;
	}
	return (i);
}

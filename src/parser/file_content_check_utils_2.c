/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content_check_utils_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:30:33 by fmouronh          #+#    #+#             */
/*   Updated: 2024/02/01 15:31:22 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	valid_textures(char *line, bool elems[6])
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (elems[ELEM_NO])
			return (false);
		elems[ELEM_NO] = true;
		return (true);
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		if (elems[ELEM_SO])
			return (false);
		elems[ELEM_SO] = true;
		return (true);
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		if (elems[ELEM_EA])
			return (false);
		elems[ELEM_EA] = true;
		return (true);
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		if (elems[ELEM_WE])
			return (false);
		elems[ELEM_WE] = true;
		return (true);
	}
	return (false);
}

bool	valid_colors(char *line, bool elems[6])
{
	if (!ft_strncmp(line, "C ", 2))
	{
		if (elems[ELEM_C])
			return (false);
		elems[ELEM_C] = true;
		return (true);
	}
	else if (!ft_strncmp(line, "F ", 2))
	{
		if (elems[ELEM_F])
			return (false);
		elems[ELEM_F] = true;
		return (true);
	}
	return (false);
}
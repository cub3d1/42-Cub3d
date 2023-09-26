/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content_check_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:21:15 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/26 21:21:36 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	color_format_ok(char *line)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (line[i] && line[i] != '\n')
	{
		if (ft_isdigit(line[i]))
			j++;
		else if (line[i] == ',')
		{
			k++;
			j = 0;
			if (!ft_isdigit(line[i + 1]))
				return (false);
		}
		else
			return (false);
		if (j == 4 || k == 3)
			return (false);
		i++;
	}
	return (true);
}

bool	color_vals_ok(char *line)
{
	char	val[3];
	int		len;
	int		i;

	i = 0;
	while (i < 3)
	{
		len = 0;
		while (ft_isdigit(line[len]))
			len++;
		ft_strlcpy(val, line, len + 1);
		if (ft_atoi(val) > 255)
			return (false);
		line += len + 1;
		i++;
	}
	return (true);
}

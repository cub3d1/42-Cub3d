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
	char	val[4];
	int		len;
	int		i;

	i = 0;
	while (i < 3)
	{
		len = 0;
		while (ft_isdigit(line[len]))
			len++;
		if (len > 3)
			return (false);
		ft_strlcpy(val, line, len + 1);
		if (ft_atoi(val) > 255)
			return (false);
		line += len + 1;
		i++;
	}
	return (true);
}

bool	map_start(char *line)
{
	const char	tex_tkns[4][3] = {"NO ", "SO ", "WE ", "EA "};
	int			i;

	while (*line && *line == ' ')
		line++;
	if (*line == 'F' || *line == 'C')
		return (false);
	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(line, tex_tkns[i], 3) == 0)
			return (false);
		i++;
	}
	if (ft_strchr(line, '1'))
		return (true);
	else
		return (false);
}

static bool	valid_elem(char *line, bool elems[6])
{
	if (!*line || !ft_strncmp(line, "\n", 1))
		return (true);
	if (valid_textures(line, elems))
		return (true);
	if (valid_colors(line, elems))
		return (true);
	if (elems[ELEM_NO] && elems[ELEM_SO] \
		&& elems[ELEM_EA] && elems[ELEM_WE] \
		&& elems[ELEM_C] && elems[ELEM_F] \
		&& (!*line || !ft_strncmp(line, "\n", 1) || ft_strchr(line, '1')))
		return (true);
	return (false);
}

bool	elems_ok(int map_fd, t_cubed *cubed)
{
	char	*line;
	bool	elems[6];

	ft_bzero(elems, 6);
	line = get_next_line(map_fd);
	while (line)
	{
		if (!valid_elem(line, elems))
		{
			free(line);
			if (close(map_fd) == -1)
				exit_err(cubed, 3);
			return (false);
		}
		free(line);
		line = get_next_line(map_fd);
	}
	if (close(map_fd) == -1)
		exit_err(cubed, 3);
	return (true);
}

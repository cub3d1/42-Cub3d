/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 02:07:36 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/25 07:19:44 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	tex_tkn_check(char *line, bool *found)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(line, TEXTURE_TKNS[i], 3) == 0)
		{
			if (found[i])
				return (false);
			if (ft_strlen(line < 4))
				return (false);
			found[i] = true;
			break ;
		}
		i++;
	}
	return (true);
}

bool	textures_ok(int map_fd)
{
	bool	ok;
	bool	tkns_found[4];
	char	*line;

	ok = true;
	ft_memset(tkns_found, 0, 4);
	line = get_next_line(map_fd);
	while (line)
	{
		if (!tex_tkn_check(line, tkns_found))
		{
			ok = false;
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(map_fd);
	}
	if (close(map_fd == -1))
		exit(3)
	if (ft_memchr(tkns_found, 0, 4))
		ok = false;
	return (ok);
}


static bool	color_tkn_check(char *line, bool *found)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (ft_strncmp(line, COLOR_TKNS[i], 2) == 0)
		{
			if (found[i])
				return (false);
			if (!color_format_ok(line) || !color_vals_ok(line))
				return (false);
			found[i] = true;
			break ;
		}
		i++;
	}
	return (true);
}

bool	color_ok(int map_fd, char **line)
{
	bool	ok;
	bool	tkns_found[2];
	char	*line;

	ok = true;
	ft_memset(tkns_found, 0, 2);
	line = get_next_line(map_fd);
	while (line)
	{
		if (!color_tkn_check(line, tkns_found))
		{
			ok = false;
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(map_fd);
	}
	if (close(map_fd) == -1)
		exit(3);
	if (ft_memchr(tkns_found, 0, 2))
		ok = false;
	return (ok);
}

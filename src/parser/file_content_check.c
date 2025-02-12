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
	const char	tex_tkns[4][3] = {"NO ", "SO ", "WE ", "EA "};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(line, tex_tkns[i], 3) == 0)
		{
			if (found[i])
				return (false);
			if (ft_strlen(line) < 4)
				return (false);
			found[i] = true;
			break ;
		}
		i++;
	}
	return (true);
}

bool	textures_ok(int map_fd, t_cubed *cubed)
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
		exit_err(cubed, 3);
	if (ft_memchr(tkns_found, 0, 4))
		ok = false;
	return (ok);
}

static bool	color_tkn_check(char *line, bool *found)
{
	const char	color_tkns[2][2] = {"F ", "C "};
	int			i;

	i = 0;
	while (*line && *line == ' ')
		line++;
	while (i < 2)
	{
		if (ft_strncmp(line, color_tkns[i], 2) == 0)
		{
			if (found[i])
				return (false);
			line += 2;
			while (*line && *line == ' ')
				line++;
			if (!color_format_ok(line) || !color_vals_ok(line))
				return (false);
			found[i] = true;
			break ;
		}
		i++;
	}
	return (true);
}

bool	color_ok(int map_fd, t_cubed *cubed)
{
	bool	color_ok;
	bool	tkns_found[2];
	char	*line;

	color_ok = true;
	ft_bzero(tkns_found, 2);
	line = get_next_line(map_fd);
	while (line && color_ok)
	{
		color_ok = color_tkn_check(line, tkns_found);
		free(line);
		if (color_ok)
			line = get_next_line(map_fd);
	}
	if (close(map_fd) == -1)
		exit_err(cubed, 3);
	if (!tkns_found[0] || !tkns_found[1])
		color_ok = false;
	return (color_ok);
}

bool	map_pos_ok(int map_fd)
{
	char	*line;
	bool	ok;

	ok = true;
	line = get_next_line(map_fd);
	while (line && (*line == '\n' || !map_start(line)))
	{
		free(line);
		line = get_next_line(map_fd);
	}
	if (!line)
		return (false);
	while (line && (ft_strchr(line, '1') || ft_strchr(line, '0')))
	{
		free(line);
		line = get_next_line(map_fd);
	}
	while (line)
	{
		if (*line != '\n')
			ok = false;
		free(line);
		line = get_next_line(map_fd);
	}
	return (ok);
}

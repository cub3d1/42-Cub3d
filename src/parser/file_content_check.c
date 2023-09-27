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
		abort_init(3, cubed);
	if (ft_memchr(tkns_found, 0, 4))
		ok = false;
	return (ok);
}


static bool	color_tkn_check(char *line, bool *found)
{
	int	i;

	i = 0;
	while (*line && *line == ' ')
		line++;
	while (i < 2)
	{
		if (ft_strncmp(line, COLOR_TKNS[i], 2) == 0)
		{
			if (found[i])
				return (false);
			line += 2;
			while (*line && *line == ' ')
				line++;
			if (!color_format_ok(line + 2) || !color_vals_ok(line + 2))
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
		abort_init(3, cubed);
	if (ft_memchr(tkns_found, 0, 2))
		ok = false;
	return (ok);
}

bool	map_pos_ok(int map_fd)
{
	char	*line;

	line = get_next_line(map_fd);
	while (line && (*line == '\n' || !map_start(line)))
	{
		free(line);
		line = get_next_line(map_fd);
	}
	while (line && (ft_strchr(line, '1') || ft_strchr(line, '0')))
	{
		free(line);
		line = get_next_line(map_fd);
	}
	while (line)
	{
		if (*line != '\n')
		{
			free(line);
			return (false);
		}
		free(line);
		line = get_next_line(map_fd);
	}
	if (close(map_fd) == -1)
		abort_init(3, cubed);
	return (true);
}
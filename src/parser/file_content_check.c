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

bool	textures_ok(int map_fd, char **line)
{
	const char	*textures[4] = {"NO ", "SO ", "WE ", "EA "};
	int	i;

	i = 0;
	while (*line && **line && i < 4)
	{
		if (ft_strlen(*line) < 3 || ft_strncmp(*line, textures[i], 3) != 0)
		{
			ft_printf_fd(2, "Error\nInvalid texture identifier\n");
			free(*line);
			return (false);
		}
		if (ft_strlen(*line + 3) == 0)
		{
			ft_printf_fd(2, "Error\nFile path not specified\n");
			free(*line);
			return (false);
		}
		free(*line);
		*line = get_next_line(map_fd);
		i++;
	}
	if (i < 4)
	{
		ft_printf_fd(2, "Error\nMissing texture paths\n");
		return (false);
	}
	return (true);
}

static bool	color_format_ok(char *line)
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

static bool color_vals_ok(char *line)
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

bool	color_ok(int map_fd, char **line)
{
	const char	*surfaces[2] = {"F ", "C "};
	int			i;

	i = 0;
	while (*line && i < 2)
	{
		if (ft_strncmp(*line, surfaces[i], 2) != 0)
		{
			ft_printf_fd(2, "Error\nInvalid surface color identifier\n");
			free(*line);
			return (false);
		}
		// ft_printf_fd(1, "%s\n", *line);
		if (!color_format_ok(*line + 2))
		{
			ft_printf_fd(2, "Error\nInvalid surface color format\n");
			free(*line);
			return (false);
		}
		if (!color_vals_ok(*line + 2))
		{
			ft_printf_fd(2, "Error\nInvalid surface color value\n");
			free(*line);
			return (false);
		}
		free(*line);
		*line = get_next_line(map_fd);
		i++;
	}
	return (true);
}

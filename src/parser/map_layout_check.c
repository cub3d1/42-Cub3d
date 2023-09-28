/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_layout_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:46:02 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/25 08:46:22 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*	remove this function				*/
/*	use it before loading map to ram	*/
int	find_map_offset(char *arg)
{
	int		map_fd;
	char	*line;
	int		i;

	map_fd = open(arg, O_RDONLY);
	if (map_fd == -1)
		exit(2);
	line = get_next_line(map_fd);
	i = 0;
	while (line && (!ft_strchr(line, '1') && ft_strchr(line, '0')))
	{
		i++;
		free(line);
		line = get_next_line(map_fd);
	}
	if (line)
		free(line);
	if (close(map_fd) == -1)
		exit(3);
	return (i);
}

static bool	valid_tkns(char token)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (token == MAP_TKNS[i])
			return (true);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (token == PLAYER_TKNS[i])
			return (true);
		i++;
	}
	return (false);
}

bool	map_tokens_ok(t_cubed *cubed)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cubed->map[i])
	{
		while (cubed->map[i][j])
		{
			if (!valid_tkns(cubed->map[i][j]))
				return (false);
			j++;
		}
		j = 0;
		i++;
	}
	return (true);
}

static bool	player_found(char *line)
{
	while (*line)
	{
		if (*line == PLAYER_TKNS[0] || line == PLAYER_TKNS[1]
			|| line == PLAYER_TKNS[2] || line == PLAYER_TKNS[3])
			return (true);
		line++;
	}
	return (false);
}

bool	player_token_ok(t_cubed *cubed)
{
	int		i;
	bool	found;

	i = 0;
	found = false;
	while (cubed->map[i])
	{
		if (player_found(cubed->map[i]))
		{
			if (found)
				return (false);
			found = true;
		}
	}
	if (!found)
		return (false);
	return (true);
}

bool	layout_enclosed(t_cubed *cubed)
{
	int	player_pos[2];

	cubed-map[(int)cubed->player-pos_y][(int)cubed->player-pos_x] = '0';
	//	do a flood fill
	flood_fill(cubed->map, (int)cubed->player->pos_x, (int)cubed->player->pos_y);
	//	check if any masked '0' is adjacent to ' '
	if (!flood_fill_check(cubed->map))
		return (false);
	return (true);
}


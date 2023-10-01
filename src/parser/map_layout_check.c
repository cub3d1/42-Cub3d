/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_layout_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:46:02 by fmouronh          #+#    #+#             */
/*   Updated: 2023/10/01 10:18:43 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
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
*/

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
	if (token == ' ' || token == '\n')
		return (true);
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
		if (*line == PLAYER_TKNS[0] || *line == PLAYER_TKNS[1]
			|| *line == PLAYER_TKNS[2] || *line == PLAYER_TKNS[3])
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
			init_player_struct(cubed->player, cubed->map, i);
		}
		i++;
	}
	if (!found)
		return (false);
	return (true);
}

/*	DELETE THIS	*/
// void	print_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		ft_printf_fd(1, "%s", map[i]);
// 		i++;
// 	}
// }

bool	layout_enclosed(t_cubed *cubed)
{
	char		**shadow_map;
	t_player	*player;

	player = cubed->player;
	shadow_map = init_shadow_map(cubed->map);
	shadow_map[(int)player->pos_y_array][(int)player->pos_x_array] = '0';
	flood_fill(shadow_map, (int)player->pos_x_array, (int)player->pos_y_array);
	if (!flood_fill_check(shadow_map))
		return (false);
	ft_free_split(shadow_map);
	return (true);
}

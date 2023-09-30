/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_layout_check_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:13:43 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/30 17:13:59 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**init_shadow_map(char **map)
{
	char	**shadow;
	int		i;

	i = 0;
	while (map[i])
		i++;
	shadow = malloc((i + 1) * sizeof(char *));
	if (!shadow)
		return (NULL);
	i = 0;
	while (map[i])
	{
		shadow[i] = ft_strdup(map[i]);
		if (!shadow[i])
		{
			ft_free_split(shadow);
			return (NULL);
		}
		i++;
	}
	shadow[i] = NULL;
	return (shadow);
}

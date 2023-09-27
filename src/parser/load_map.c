/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:17:47 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/26 23:17:48 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	load_map(t_cubed *cubed, char *arg)
{
	int	map_fd;

	map_fd = open(arg, O_RDONLY);
	if (map_fd == -1)
		abort_init(2, cubed);
	

}
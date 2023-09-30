/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:21:14 by fmouronh          #+#    #+#             */
/*   Updated: 2023/09/30 19:21:14 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	exit_err(t_cubed *cubed, int err_code)
{
	if (err_code == 1)
		ft_printf_fd(1, "Error\nInvalid file format\n");
	else if (err_code == 2)
		ft_printf_fd(1, "Error\nFile doesn't exist\n");
	else if (err_code == 3)
		ft_printf_fd(1, "Error\nFile couldn't be closed\n");
	else if (err_code == 4)
		ft_printf_fd(1, "Error\nMap load fail\n");
	else if (err_code == 5)
		ft_printf_fd(1, "Error\nMalloc Failed\n");
	free_stuff(cubed, -1);
	exit(err_code);
}

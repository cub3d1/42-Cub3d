/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:30:11 by fmouronh          #+#    #+#             */
/*   Updated: 2023/05/12 00:22:52 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_smallest(int num_a, int num_b)
{
	if (num_a < num_b)
		return (num_a);
	else
		return (num_b);
}

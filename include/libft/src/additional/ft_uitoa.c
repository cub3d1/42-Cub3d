/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:59:00 by fmouronh          #+#    #+#             */
/*   Updated: 2022/11/27 00:14:51 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_fact(unsigned int nbr)
{
	int	i;

	i = 1;
	while (nbr / 10 != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static void	assign_nums(char *str, unsigned int nb)
{
	if (nb > 9)
		assign_nums(str - 1, nb / 10);
	*str = (nb % 10) + '0';
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = count_fact(n);
	num = ft_calloc(len + 1, sizeof(char));
	if (!num)
		return (NULL);
	assign_nums(num + len - 1, n);
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:46:51 by fmouronh          #+#    #+#             */
/*   Updated: 2022/12/01 01:07:50 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_read_bits(char *result, void *ptr, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = size - 1;
	while (i < size * 2)
	{
		if (i % 2 == 0)
			result[i] = (*(char *)(ptr + j) >> 4) & 0xF;
		else
			result[i] = *(char *)(ptr + j) & 0xF;
		if (++i % 2 == 0)
			j--;
	}
}

static void	ft_hex_convert(char *bits, size_t size)
{
	const char	*vals = "0123456789abcdef";
	size_t		i;

	i = 0;
	while (i < size * 2)
	{
		bits[i] = vals[(int)bits[i]];
		i++;
	}
}

char	*ft_btox(void *ptr, size_t size)
{
	char	*bits;
	char	*result;
	size_t	i;

	bits = ft_calloc((size * 2) + 1, sizeof(char));
	if (!bits)
		return (NULL);
	ft_read_bits(bits, ptr, size);
	ft_hex_convert(bits, size);
	i = 0;
	while (bits[i] == '0')
		i++;
	if (bits[i])
	{
		result = ft_calloc(ft_strlen(&bits[i]) + 1, sizeof(char));
		if (!result)
			result = NULL;
		else
			ft_strlcpy(result, &bits[i], ft_strlen(&bits[i]) + 1);
	}
	else
		result = ft_strdup("0");
	free(bits);
	return (result);
}

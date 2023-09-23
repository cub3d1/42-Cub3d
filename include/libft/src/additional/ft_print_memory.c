/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:08:02 by fmouronh          #+#    #+#             */
/*   Updated: 2023/05/12 00:21:39 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_blanks(size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putstr_fd("0x0000000000000000:", 1);
		ft_putstr_fd(" .... .... .... .... .... .... .... .... ", 1);
		ft_putendl_fd("................", 1);
		i++;
	}
}

static void	print_offset(const void *ptr)
{
	char	*hexvals;
	size_t	hv_len;

	hexvals = ft_btox(&ptr, sizeof(long int));
	if (hexvals)
	{
		write(1, "0x", 2);
		hv_len = ft_strlen(hexvals);
		while (hv_len++ < 16)
		{
			write(1, "0", 1);
		}
		ft_putstr_fd(hexvals, 1);
		free(hexvals);
	}
}

static void	hex_vals(const void *addr)
{
	char	*byte;
	size_t	i;

	i = 0;
	while (i < 16)
	{
		byte = ft_btox((void *)(addr + i), sizeof(char));
		if (!byte[1])
			write(1, "0", 1);
		ft_putstr_fd(byte, 1);
		free(byte);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

static void	char_vals(const void *addr)
{
	char	val;
	int		i;

	i = 0;
	while (i < 16)
	{
		val = ((char *)addr)[i];
		if (ft_isprint(val))
			write(1, &val, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(const void *addr, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = (void *)addr;
	if (!addr)
		print_blanks(size);
	else
	{
		while (i < size)
		{
			print_offset(addr);
			write(1, ": ", 2);
			hex_vals(addr);
			write(1, " ", 1);
			char_vals(addr);
			write(1, "\n", 1);
			addr += 16;
			i++;
		}
	}
	return (ptr);
}

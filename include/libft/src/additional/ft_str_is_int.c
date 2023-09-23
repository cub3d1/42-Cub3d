/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 02:19:47 by fmouronh          #+#    #+#             */
/*   Updated: 2023/05/12 00:22:30 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(char *str, int len)
{
	int		cmp;
	char	*int_min;
	char	*int_max;

	cmp = 0;
	int_min = ft_itoa(INT_MIN);
	int_max = ft_itoa(INT_MAX);
	if (len == 11 && str[0] == '-')
		cmp = ft_strncmp(str, int_min, len);
	else if (len == 10)
		cmp = ft_strncmp(str, int_max, len);
	free(int_min);
	free(int_max);
	return (cmp);
}

static bool	str_is_num(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	ft_str_is_int(char	*str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 11 || (len == 11 && str[0] != '-'))
		return (false);
	else if (!str_is_num(str))
		return (false);
	else if (check_overflow(str, len) > 0)
		return (false);
	else
		return (true);
}

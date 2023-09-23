/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:57:09 by fmouronh          #+#    #+#             */
/*   Updated: 2023/07/06 15:57:24 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, int index, int torem, char *torepl)
{
	char	*result;
	int		len;
	int		tail;

	len = ft_strlen(str) + ft_strlen(torepl) - torem + 1;
	tail = ft_strlen(str) - index - torem + ft_strlen(torepl);
	result = ft_calloc(len, sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, index + 1);
	ft_strlcat(result, torepl, ft_strlen(torepl) + 1);
	ft_strlcat(result, &str[index + torem], tail + 1);
	return (result);
}

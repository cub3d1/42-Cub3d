/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:20:10 by fmouronh          #+#    #+#             */
/*   Updated: 2023/05/12 00:20:13 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_invalid_fd(int fd, char *buffer)
{
	int	i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (1);
	if (!*buffer)
	{
		if (!read(fd, buffer, BUFFER_SIZE))
		{
			while (buffer[i])
				buffer[i++] = '\0';
			return (1);
		}
	}
	return (0);
}

int	ft_read_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i++] == '\n')
			break ;
	}
	return (i);
}

static char	*alloc_result(char *line, int eol)
{
	char	*result;

	if (line)
		result = ft_calloc(ft_strlen(line) + eol + 1, sizeof(char));
	else
		result = ft_calloc(eol + 1, sizeof(char));
	return (result);
}

char	*ft_cp_to_line(char *line, char *buffer, int eol)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = alloc_result(line, eol);
	if (!result || eol < 0)
		return (NULL);
	while (line && line[i])
	{
		result[i] = line[i];
		i++;
	}
	while (j < eol)
		result[i++] = buffer[j++];
	result[i] = '\0';
	if (line)
		free(line);
	if (!*result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

void	ft_update_buffer(char *buffer, int eol)
{
	int	i;

	i = 0;
	while (buffer[eol])
		buffer[i++] = buffer[eol++];
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}

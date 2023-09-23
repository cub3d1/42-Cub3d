/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:20:02 by fmouronh          #+#    #+#             */
/*   Updated: 2023/05/12 00:20:04 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[NR_OPEN][BUFFER_SIZE + 1];
	char		*line;
	int			eol;

	line = NULL;
	eol = BUFFER_SIZE;
	if (fd < 0 || ft_invalid_fd(fd, buffer[fd]))
		return (NULL);
	while (*(buffer[fd]))
	{
		if (eol < BUFFER_SIZE)
			buffer[fd][eol] = '\0';
		eol = ft_read_buffer(buffer[fd]);
		line = ft_cp_to_line(line, buffer[fd], eol);
		if (!line || !*line)
			return (NULL);
		if (buffer[fd][eol - 1] == '\n')
		{
			ft_update_buffer(buffer[fd], eol);
			return (line);
		}
		eol = read(fd, buffer[fd], BUFFER_SIZE);
	}
	return (line);
}

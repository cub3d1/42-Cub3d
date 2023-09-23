/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:19:23 by fmouronh          #+#    #+#             */
/*   Updated: 2023/05/12 00:19:36 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <linux/limits.h>
# include "libft.h"

char	*get_next_line(int fd);
int		ft_read_buffer(char *buffer);
char	*ft_cp_to_line(char *line, char *buffer, int eol);
void	ft_update_buffer(char *buffer, int eol);
int		ft_invalid_fd(int fd, char *buffer);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:58:08 by fmouronh          #+#    #+#             */
/*   Updated: 2022/11/12 16:24:18 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
			s++;
	}
	return (words);
}

static char	**assign_words(char **split, char const *s, char c, size_t words)
{
	char	*next_wd;
	size_t	i;
	size_t	len;

	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		next_wd = (char *)s;
		while (*next_wd && *next_wd != c)
			next_wd++;
		len = (size_t)(next_wd - s) + 1;
		split[i] = ft_calloc(len, sizeof(char));
		if (!split[i])
		{
			free(split);
			return (NULL);
		}
		ft_strlcpy(split[i++], s, len);
		s = (char const *)next_wd;
	}
	split[i] = NULL;
	return (split);
}

static char	**ft_sanitize(char const *s, char c)
{
	char	**split;

	split = NULL;
	if (!s)
		return (NULL);
	else if (!*s)
	{
		split = malloc(sizeof(char *) * 1);
		if (!split)
			return (NULL);
		split[0] = NULL;
	}
	else if (!c)
	{
		split = malloc(sizeof(char *) * 2);
		if (!split)
			return (NULL);
		split[0] = ft_strdup(s);
		split[1] = NULL;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;

	if (!s || !*s || !c)
		return (ft_sanitize(s, c));
	else
	{
		words = ft_count_words(s, c);
		split = malloc((words + 1) * sizeof(char *));
		if (!split)
			return (NULL);
		split = assign_words(split, s, c, words);
		if (!split)
			return (NULL);
	}
	return (split);
}

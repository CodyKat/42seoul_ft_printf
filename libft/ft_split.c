/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:45:50 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/19 04:00:21 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (count);
		while (*s != '\0' && *s != c)
			s++;
		count++;
	}
	return (count);
}

static char	*ft_alloc_string(char **dst, const char *src, char del)
{
	int		len;

	len = 0;
	while (*src == del)
		src++;
	while (*src != del && *src != '\0')
	{
		src++;
		len++;
	}
	*dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	src -= len;
	ft_strlcpy(*dst, src, len + 1);
	return ((char *)(src + len - 1));
}

static void	free_back(char **table, int idx)
{
	int	f_idx;

	f_idx = 0;
	while (f_idx < idx)
	{
		free(table[f_idx]);
		f_idx++;
	}
	free(table);
}

char	**ft_split(const char *s, char c)
{
	char	**table;
	int		word_count;
	int		idx;

	idx = 0;
	word_count = ft_count_words(s, c);
	table = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (table == NULL)
		return (NULL);
	while (idx < word_count)
	{
		s = ft_alloc_string(&table[idx], s, c);
		if (s == NULL)
		{
			free_back(table, idx);
			return (NULL);
		}
		s++;
		idx++;
	}
	table[word_count] = NULL;
	return (table);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:24:56 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:23:43 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**free_malloc(char **tab, size_t i)
{
	while (tab[i])
		free(tab[i++]);
	return (free(tab), NULL);
}

int	word_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s && *s != c)
				s++;
			i++;
		}
	}
	return (i);
}

static int	wlen(char const *s, char c)
{
	int	len;

	len = 0;
	if (!*s)
		return (0);
	while (*s && *s++ != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		a;
	int		i;

	a = -1;
	i = 0;
	res = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !res)
		return (NULL);
	while (++a < word_count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		res[a] = ft_substr(s, i, wlen(&s[i], c));
		if (!res[a])
			return (free_malloc(res, 0));
		i += wlen(&s[i], c);
	}
	return (res[a] = NULL, res);
}

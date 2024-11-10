/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:49:06 by ydunay            #+#    #+#             */
/*   Updated: 2024/08/29 10:35:51 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (s)
	{
		if (start >= (unsigned int)ft_strlen(s) || len == 0)
			return (ft_strdup(""));
		i = 0;
		while (i < len && s[i + start] != '\0')
			i++;
		new = (char *)malloc(i + 1);
		if (!new)
			return (NULL);
		j = 0;
		while (j < i)
		{
			new[j] = s[start + j];
			j++;
		}
		new[j] = '\0';
		return (new);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:14:03 by ydunay            #+#    #+#             */
/*   Updated: 2023/10/15 09:12:43 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	total_length;
	size_t	i;

	i = 0;
	total_length = (ft_strlen(s1) + ft_strlen(s2));
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(total_length + 1);
	if (!new)
		return (NULL);
	while (*s1)
		*(new + i++) = *s1++;
	while (*s2)
		*(new + i++) = *s2++;
	new[i] = '\0';
	return (new);
}

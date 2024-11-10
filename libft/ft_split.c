/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:44:24 by ydunay            #+#    #+#             */
/*   Updated: 2024/08/28 11:20:27 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char *str)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	arr = (char **)malloc((ft_strlen(str) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == 32 || str[i] == '\t')
			i++;
		k = i;
		while (str[i] && str[i] != 32 && str[i] != '\t')
			i++;
		if (i > k)
		{
			arr[j] = ft_substr(str, k, i - k);
			j++;
		}
	}
	arr[j] = 0;
	return (arr);
}

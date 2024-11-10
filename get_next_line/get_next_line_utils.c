/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:42:43 by ydunay            #+#    #+#             */
/*   Updated: 2024/08/29 11:25:18 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	return (0);
}

void	*ft_free_stack(char **stack, int create_line)
{
	char	*line;

	if (!*stack)
		return (NULL);
	if (!create_line)
	{
		if (*stack)
		{
			free(*stack);
			*stack = NULL;
		}
		return (NULL);
	}
	else if (create_line)
	{
		line = ft_strdup(*stack);
		free(*stack);
		*stack = NULL;
		return (line);
	}
	return (NULL);
}

static void	freesplit(char **split)
{
	int	x;

	x = 0;
	while (split[x])
	{
		free(split[x]);
		x++;
	}
	free(split);
}

static int	fornorm(char *str, char **arr, int i, int k)
{
	int	j;

	j = 0;
	while (str[i])
	{
		while (str[i] == ',')
		{
			if (str[i + 1] == ',' || str[0] == ',')
			{
				arr[j] = 0;
				freesplit(arr);
				return (0);
			}
			i++;
		}
		k = i;
		while (str[i] && str[i] != ',')
			i++;
		if (i > k)
			arr[j++] = ft_substr(str, k, i - k);
	}
	arr[j] = 0;
	return (1);
}

char	**ft_split2(char *str)
{
	char	**arr;
	int		i;
	int		k;

	arr = (char **)malloc((ft_strlen(str) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	k = 0;
	if (!fornorm(str, arr, i, k))
		return (0);
	return (arr);
}

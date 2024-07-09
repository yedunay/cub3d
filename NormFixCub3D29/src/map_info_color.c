/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:56:43 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:10:08 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include <stdio.h>

void	take_rgbcolor(t_game *game)
{
	char	**str;
	int		i;

	i = 0;
	while (i < 2)
	{
		str = ft_split(game->map.color_path[i], 32);
		if (str != NULL && str[1] != NULL)
		{
			game->map.rgb_color[i] = ft_strdup(str[1]);
		}
		else
		{
			free_array(str, 0);
			free_all(game, "Error color");
		}
		free_array(str, 0);
		i++;
	}
}

int	get_rgb_color(char *str, t_game *game)
{
	char	**tmp;
	int		res;

	tmp = NULL;
	tmp = ft_split(str, ',');
	if (check_color(tmp) == 0)
	{
		free_array(tmp, 0);
		free_all(game, "Error :invalid color detected");
	}
	if (count_comma(str) != 2)
	{
		free_array(tmp, 0);
		free_all(game, "Error : comma count is not 3");
	}
	is_digit_cub(tmp, game);
	res = (ft_atoi(tmp[0]) << 16) + (ft_atoi(tmp[1]) << 8) + ft_atoi(tmp[2]);
	free_array(tmp, 0);
	return (res);
}

int	check_color(char **tmp)
{
	if (tmp[0] != NULL && tmp[1] != NULL && (tmp[2] != NULL
			&& tmp[2][0] != '\n'))
	{
		if (!(0 <= ft_atoi(tmp[0]) && ft_atoi(tmp[0]) <= 255)
			|| !(0 <= ft_atoi(tmp[1]) && ft_atoi(tmp[1]) <= 255)
			|| !(0 <= ft_atoi(tmp[2]) && ft_atoi(tmp[2]) <= 255))
		{
			printf("Girilen sayilar 0-255 arasinda değil !!!\n");
			return (0);
		}
	}
	else
	{
		printf("Renk girilmedi !\n");
		return (0);
	}
	return (1);
}

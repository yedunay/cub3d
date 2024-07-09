/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:12:28 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 21:50:42 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include <stdio.h>

void	check_info(t_game *game)
{
	if (newline_control(game) == 0)
		free_all(game, "Bilgiler arasinda hiçbirşey olmamali");
	else if (game->map.infocount != 6)
		free_all(game, "Error info count");
	else if (game->map.flags[0] != 1 || game->map.flags[1] != 1
		|| game->map.flags[2] != 1 || game->map.flags[3] != 1
		|| game->map.flags[4] != 1 || game->map.flags[5] != 1)
		free_all(game, "Error info flag");
	else
		printf("Info count OK\n");
}

void	take_info(t_game *game)
{
	take_textures(game);
	take_rgbcolor(game);
	game->map.f_color = get_rgb_color(game->map.rgb_color[0], game);
	game->map.c_color = get_rgb_color(game->map.rgb_color[1], game);
}

void	take_textures(t_game *game)
{
	char	**str;
	int		i;

	i = 0;
	while (i < 4)
	{
		str = ft_split(game->map.directions[i], 32);
		if (str != NULL && str[1] != NULL && str[1][0] != '\n')
			game->map.textures[i] = ft_strdup(str[1]);
		else
		{
			free_array(str, 0);
			free_all(game, "Error texture");
		}
		free_array(str, 0);
		i++;
	}
}

void	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.real_map[i])
	{
		j = 0;
		while (game->map.real_map[i][j])
		{
			if (game->map.real_map[i][j] != '1'
				&& game->map.real_map[i][j] != '0'
				&& game->map.real_map[i][j] != '\0'
				&& game->map.real_map[i][j] != 'N'
				&& game->map.real_map[i][j] != 'S'
				&& game->map.real_map[i][j] != 'W'
				&& game->map.real_map[i][j] != 'E'
				&& game->map.real_map[i][j] != '\n'
				&& game->map.real_map[i][j] != ' '
				&& game->map.real_map[i][j] != 32)
				free_all(game, "Invalid character");
			j++;
		}
		i++;
	}
}

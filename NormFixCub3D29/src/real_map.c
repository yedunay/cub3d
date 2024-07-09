/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:19:16 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:20:58 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	map_check(t_game *game)
{
	create_real_map(game);
	create_tmp_map(game);
	check_characters(game);
	copy_map(game, 0, 0);
}

int	copy_map(t_game *game, int y, int x)
{
	while (game->map.real_map[++y])
	{
		x = -1;
		while (game->map.real_map[y][++x])
		{
			if (game->map.real_map[y][x] == 'N'
				|| game->map.real_map[y][x] == 'S'
				|| game->map.real_map[y][x] == 'W'
				|| game->map.real_map[y][x] == 'E')
			{
				game->map.posx = x;
				game->map.posy = y;
				game->map.playercount++;
				game->map.pov = game->map.real_map[y][x];
			}
		}
	}
	printf("Player Pos Map[%d][%d]\n", game->map.posy, game->map.posx);
	if (game->map.playercount != 1)
		free_all(game, "Error player count");
	return (0);
}

void	create_real_map(t_game *game)
{
	int	i;
	int	j;

	game->map.real_height = game->map.map_height - game->map.endofinfo;
	i = game->map.endofinfo;
	j = 0;
	game->map.real_map = (char **)malloc(sizeof(char *) * (game->map.real_height
				+ 1));
	while (game->map.map[i])
	{
		game->map.real_map[j] = ft_strdup(game->map.map[i]);
		i++;
		j++;
	}
	game->map.real_map[j] = NULL;
	printf("\n");
}

int	find_bigger_line_len(char **map)
{
	int		i;
	size_t	bigg_len;

	i = 0;
	bigg_len = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > bigg_len)
			bigg_len = ft_strlen(map[i]);
		i++;
	}
	return (bigg_len);
}

void	create_tmp_map(t_game *game)
{
	int	i;
	int	j;
	int	line_len;

	line_len = find_bigger_line_len(game->map.real_map);
	game->map.tmp_map = (char **)calloc(game->map.real_height + 1,
			sizeof(char *));
	i = 0;
	while (game->map.real_map[i])
	{
		j = 0;
		game->map.tmp_map[i] = (char *)calloc(line_len + 1, sizeof(char));
		while (game->map.real_map[i][j])
		{
			game->map.tmp_map[i][j] = game->map.real_map[i][j];
			j++;
		}
		i++;
	}
	game->map.tmp_map[i] = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:14:55 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:11:58 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	map_print(t_game *game)
{
	int	i;

	i = 0;
	printf("************************************\n");
	printf("************************************\n");
	while (game->map.map[i] != NULL)
	{
		printf("%s", game->map.map[i]);
		i++;
	}
	printf("************************************\n");
	printf("************************************\n");
	map_print_info(game);
}

void	map_print_info(t_game *game)
{
	printf("NO = %s", game->map.directions[0]);
	printf("EA = %s", game->map.directions[1]);
	printf("SO = %s", game->map.directions[2]);
	printf("WE = %s", game->map.directions[3]);
	printf("F = %s", game->map.color_path[0]);
	printf("C = %s", game->map.color_path[1]);
	printf("Textures 0 %s", game->map.textures[0]);
	printf("Textures 1 %s", game->map.textures[1]);
	printf("Textures 2 %s", game->map.textures[2]);
	printf("Textures 3 %s", game->map.textures[3]);
	printf("F color = %d\n", game->map.f_color);
	printf("C color = %d\n", game->map.c_color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:00:46 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:25:45 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stddef.h>

void	map_init(t_game *game)
{
	game->map.map_name = NULL;
	game->map.playercount = 0;
	game->map.c_color = 0;
	game->map.f_color = 0;
	game->map.fd = 0;
	game->map.playercount = 0;
	game->map.real_height = 0;
	game->map.posx = 0;
	game->map.posy = 0;
	game->map.tmp_map = NULL;
	game->map.map = NULL;
	game->map.map_height = 0;
	game->map.floor = NULL;
	game->map.ceiling = NULL;
	game->map.real_map = NULL;
	game->map.infocount = 0;
	game->map.endofinfo = 0;
	init_array(game);
}

void	init_array(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->map.directions[i] = NULL;
		game->map.textures[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 2)
	{
		game->map.color_path[i] = NULL;
		game->map.rgb_color[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		game->map.flags[i] = 0;
		i++;
	}
}

void	raycast_init(t_game *game)
{
	if (!check_player(game))
		return (free_all(game, "Error player pov\n"));
	game->posx = game->map.posx + 0.5;
	game->posy = game->map.posy + 0.5;
	game->exit_control = 1;
	game->a = false;
	game->d = false;
	game->s = false;
	game->w = false;
	game->left = false;
	game->right = false;
	game->shift = false;
	game->speed = 0.1;
	game->rotspeed = 0.05;
}

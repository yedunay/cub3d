/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:27:56 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/28 22:04:45 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	east_west(t_game *game)
{
	if (game->map.pov == 'W')
	{
		game->dirx = -1.0;
		game->diry = 0.0;
		game->planex = 0.0;
		game->planey = -0.66;
		return (true);
	}
	else if (game->map.pov == 'E')
	{
		game->dirx = 1.0;
		game->diry = 0.0;
		game->planex = 0.0;
		game->planey = 0.66;
		return (true);
	}
	return (false);
}

static bool	south_north(t_game *game)
{
	if (game->map.pov == 'S')
	{
		game->dirx = 0;
		game->diry = 1;
		game->planex = -0.66;
		game->planey = 0;
		return (true);
	}
	else if (game->map.pov == 'N')
	{
		game->dirx = 0;
		game->diry = -1.00;
		game->planex = 0.66;
		game->planey = 0;
		return (true);
	}
	return (false);
}

bool	check_player(t_game *game)
{
	if (east_west(game))
		return (true);
	if (south_north(game))
		return (true);
	return (false);
}

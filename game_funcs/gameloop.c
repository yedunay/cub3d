/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:14:56 by ydunay            #+#    #+#             */
/*   Updated: 2024/08/29 12:07:31 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"

static void	move_player(t_game *game)
{
	playermv1(game);
	playermv2(game);
}

int	gameloop(t_game *game)
{
	move_player(game);
	turn_player(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->img.img, 0,
		0);
	return (0);
}

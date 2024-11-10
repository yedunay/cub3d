/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:14:59 by ydunay            #+#    #+#             */
/*   Updated: 2024/08/29 11:58:16 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	playermv1(t_game *game)
{
	t_pmv	g;

	g = (t_pmv){0};
	g.x = &game->player.y;
	g.y = &game->player.x;
	g.movevalx = game->player.plane_y * game->player.move_speed;
	g.movevaly = game->player.plane_x * game->player.move_speed;
	if (game->keys.a)
	{
		if (game->map.map[(int)(*g.x)][(int)(*g.y - g.movevaly)] != '1')
			*g.y -= g.movevaly;
		if (game->map.map[(int)(*g.x - g.movevalx)][(int)(*g.y)] != '1')
			*g.x -= g.movevalx;
	}
	if (game->keys.d)
	{
		if (game->map.map[(int)(*g.x)][(int)(*g.y + g.movevaly)] != '1')
			*g.y += g.movevaly;
		if (game->map.map[(int)(*g.x + g.movevalx)][(int)(*g.y)] != '1')
			*g.x += g.movevalx;
	}
}

void	playermv2(t_game *game)
{
	t_pmv	g;

	g = (t_pmv){0};
	g.x = &game->player.y;
	g.y = &game->player.x;
	g.movevalx = game->player.dir_y * game->player.move_speed;
	g.movevaly = game->player.dir_x * game->player.move_speed;
	if (game->keys.w)
	{
		if (game->map.map[(int)(*g.x)][(int)(*g.y + g.movevaly)] != '1')
			*g.y += g.movevaly;
		if (game->map.map[(int)(*g.x + g.movevalx)][(int)(*g.y)] != '1')
			*g.x += g.movevalx;
	}
	if (game->keys.s)
	{
		if (game->map.map[(int)(*g.x)][(int)(*g.y - g.movevaly)] != '1')
			*g.y -= g.movevaly;
		if (game->map.map[(int)(*g.x - g.movevalx)][(int)(*g.y)] != '1')
			*g.x -= g.movevalx;
	}
}

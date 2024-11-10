/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:15:01 by ydunay            #+#    #+#             */
/*   Updated: 2024/08/28 11:18:20 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

static void	turn_right(t_game *g)
{
	t_turn	t;
	double	t_rad;

	t = (t_turn){0};
	t_rad = g->player.turn_radian;
	t.olddirx = g->player.dir_x;
	t.oldplanex = g->player.plane_x;
	t.dirx = &g->player.dir_x;
	t.planex = &g->player.plane_x;
	t.diry = &g->player.dir_y;
	t.planey = &g->player.plane_y;
	*t.dirx = t.olddirx * cos(t_rad) - *t.diry * sin(t_rad);
	*t.diry = t.olddirx * sin(t_rad) + *t.diry * cos(t_rad);
	*t.planex = t.oldplanex * cos(t_rad) - *t.planey * sin(t_rad);
	*t.planey = t.oldplanex * sin(t_rad) + *t.planey * cos(t_rad);
}

static void	turn_left(t_game *g)
{
	t_turn	t;
	double	t_rad;

	t = (t_turn){0};
	t_rad = (-1) * (g->player.turn_radian);
	t.olddirx = g->player.dir_x;
	t.oldplanex = g->player.plane_x;
	t.dirx = &g->player.dir_x;
	t.planex = &g->player.plane_x;
	t.diry = &g->player.dir_y;
	t.planey = &g->player.plane_y;
	*t.dirx = t.olddirx * cos(t_rad) - *t.diry * sin(t_rad);
	*t.diry = t.olddirx * sin(t_rad) + *t.diry * cos(t_rad);
	*t.planex = t.oldplanex * cos(t_rad) - *t.planey * sin(t_rad);
	*t.planey = t.oldplanex * sin(t_rad) + *t.planey * cos(t_rad);
}

void	turn_player(t_game *g)
{
	if (g->keys.right)
		turn_right(g);
	if (g->keys.left)
		turn_left(g);
}

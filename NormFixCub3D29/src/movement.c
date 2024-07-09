/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:17:02 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:14:50 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int	key_press(int keyCode, t_game *game)
{
	if (keyCode == 53)
		free_all(game, "Game closed");
	if (keyCode == 13)
		game->w = true;
	if (keyCode == 1)
		game->s = true;
	if (keyCode == 0)
		game->a = true;
	if (keyCode == 2)
		game->d = true;
	if (keyCode == 124)
		game->right = true;
	if (keyCode == 123)
		game->left = true;
	if (keyCode == 257)
		game->shift = true;
	return (0);
}

int	key_release(int keyCode, t_game *game)
{
	if (keyCode == 13)
		game->w = false;
	if (keyCode == 1)
		game->s = false;
	if (keyCode == 0)
		game->a = false;
	if (keyCode == 2)
		game->d = false;
	if (keyCode == 124)
		game->right = false;
	if (keyCode == 123)
		game->left = false;
	if (keyCode == 257)
		game->shift = false;
	return (0);
}

void	movement(t_game *game)
{
	if (game->shift)
		game->speed = 0.07;
	else
		game->speed = 0.03;
	if (game->w)
	{
		if (game->map.real_map[(int)(game->posy)][(int)(game->posx + game->dirx
				* game->speed)] != '1')
			game->posx += game->dirx * game->speed;
		if (game->map.real_map[(int)(game->posy + game->diry
				* game->speed)][(int)(game->posx)] != '1')
			game->posy += game->diry * game->speed;
	}
	if (game->d)
	{
		if (game->map.real_map[(int)(game->posy)][(int)(game->posx
				+ game->planex * game->speed)] != '1')
			game->posx += game->planex * game->speed;
		if (game->map.real_map[(int)(game->posy + game->planey
				* game->speed)][(int)(game->posx)] != '1')
			game->posy += game->planey * game->speed;
	}
	movement2(game);
}

void	movement2(t_game *game)
{
	if (game->s)
	{
		if (game->map.real_map[(int)(game->posy)][(int)(game->posx - game->dirx
				* game->speed)] != '1')
			game->posx -= game->dirx * game->speed;
		if (game->map.real_map[(int)(game->posy - game->diry
				* game->speed)][(int)(game->posx)] != '1')
			game->posy -= game->diry * game->speed;
	}
	if (game->a)
	{
		if (game->map.real_map[(int)(game->posy)][(int)(game->posx
				- game->planex * game->speed)] != '1')
			game->posx -= game->planex * game->speed;
		if (game->map.real_map[(int)(game->posy - game->planey
				* game->speed)][(int)(game->posx)] != '1')
			game->posy -= game->planey * game->speed;
	}
}

void	rotate(t_game *g)
{
	double	olddirx;
	double	oldplanex;

	if (g->right)
	{
		olddirx = g->dirx;
		g->dirx = g->dirx * cos(g->rotspeed) - g->diry * sin(g->rotspeed);
		g->diry = olddirx * sin(g->rotspeed) + g->diry * cos(g->rotspeed);
		oldplanex = g->planex;
		g->planex = g->planex * cos(g->rotspeed) - g->planey * sin(g->rotspeed);
		g->planey = oldplanex * sin(g->rotspeed) + g->planey * cos(g->rotspeed);
	}
	if (g->left)
	{
		olddirx = g->dirx;
		g->dirx = g->dirx * cos(g->rotspeed) + g->diry * sin(g->rotspeed);
		g->diry = -olddirx * sin(g->rotspeed) + g->diry * cos(g->rotspeed);
		oldplanex = g->planex;
		g->planex = g->planex * cos(g->rotspeed) + g->planey * sin(g->rotspeed);
		g->planey = -oldplanex * sin(g->rotspeed) + g->planey
			* cos(g->rotspeed);
	}
}

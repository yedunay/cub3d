/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:22:15 by eozdur            #+#    #+#             */
/*   Updated: 2024/07/09 12:37:07 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	ray1(t_game *g, int x)
{
	g->camerax = 2 * x / (double)WIDTH - 1;
	g->raydirx = g->dirx + g->planex * g->camerax;
	g->raydiry = g->diry + g->planey * g->camerax;
	g->mapx = (int)g->posx;
	g->mapy = (int)g->posy;
	if (g->raydirx == 0)
		g->deltadistx = 1e30;
	else
		g->deltadistx = fabs(1 / g->raydirx);
	if (g->raydiry == 0)
	{
		g->deltadisty = 0.001f;
		g->deltadisty = 1e30;
	}
	else
		g->deltadisty = fabs(1 / g->raydiry);
}

void	ray2(t_game *g)
{
	if (g->raydirx < 0)
	{
		g->stepx = -1;
		g->sidedistx = (g->posx - g->mapx) * g->deltadistx;
	}
	else
	{
		g->stepx = 1;
		g->sidedistx = (g->mapx + 1.0 - g->posx) * g->deltadistx;
	}
	if (g->raydiry < 0)
	{
		g->stepy = -1;
		g->sidedisty = (g->posy - g->mapy) * g->deltadisty;
	}
	else
	{
		g->stepy = 1;
		g->sidedisty = (g->mapy + 1.0 - g->posy) * g->deltadisty;
	}
}

void	ray3(t_game *game)
{
	game->hit = 0;
	while (game->hit == 0)
	{
		if (game->sidedistx < game->sidedisty)
		{
			game->sidedistx += game->deltadistx;
			game->mapx += game->stepx;
			game->side = 0;
		}
		else
		{
			game->sidedisty += game->deltadisty;
			game->mapy += game->stepy;
			game->side = 1;
		}
		if (game->map.real_map[game->mapy][game->mapx] == '1')
			game->hit = 1;
	}
}

void	ray4(t_game *g)
{
	find_direction(g);
	if (g->side == 0)
		g->perp_wall_dist = g->sidedistx - g->deltadistx;
	else
		g->perp_wall_dist = g->sidedisty - g->deltadisty;
	g->line_h = (int)(HEIGHT / g->perp_wall_dist);
	g->draw_start = -g->line_h / 2 + HEIGHT / 2;
	if (g->draw_start < 0)
		g->draw_start = 0;
	g->draw_end = g->line_h / 2 + HEIGHT / 2;
	if	(g->draw_end >= HEIGHT)
		g->draw_end = HEIGHT - 1;
	if (g->side == 0)
		g->wallx = g->posy + g->perp_wall_dist * g->raydiry;
	else
		g->wallx = g->posx + g->perp_wall_dist * g->raydirx;
	g->wallx = g->wallx - (int)g->wallx;
	g->tex_x = (int)(g->wallx * (double)g->tex_width);
	if (g->side == 0 && g->raydirx < 0)
		g->tex_x = g->tex_width - g->tex_x - 1;
	if (g->side == 1 && g->raydiry > 0)
		g->tex_x = g->tex_width - g->tex_x - 1;
	g->step = 1.0 * (double)g->tex_height / (double)g->line_h;
	g->texpos = (g->draw_start - HEIGHT / 2 + g->line_h / 2) * g->step;
}

void	find_direction(t_game *g)
{
	if (g->side == 0)
	{
		if (g->raydirx < 0)
		{
			g->tex_width = g->west->width;
			g->tex_height = g->west->height;
		}
		else
		{
			g->tex_width = g->east->width;
			g->tex_height = g->east->height;
		}
	}
	else
	{
		if (g->raydiry < 0)
		{
			g->tex_width = g->north->width;
			g->tex_height = g->north->height;
		}
		else
		{
			g->tex_width = g->south->width;
			g->tex_height = g->south->height;
		}
	}
}

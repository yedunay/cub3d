/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:18:39 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:14:59 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../minilibx/mlx.h"

int	raycast(t_game *game)
{
	movement(game);
	rotate(game);
	raycasting(game);
	return (0);
}

void	raycasting(t_game *game)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		ray1(game, x);
		ray2(game);
		ray3(game);
		ray4(game);
		render_column(game, x, 0);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}

void	render_column(t_game *g, int x, int y)
{
	while (y < HEIGHT)
	{
		g->tex_y = (int)g->texpos;
		if (y < g->draw_start)
			g->img->addr[y * WIDTH + x] = g->map.c_color;
		else if (y > g->draw_end)
			g->img->addr[y * WIDTH + x] = g->map.f_color;
		else
		{
			if (g->side == 1 && g->raydiry < 0)
				g->img->addr[y * WIDTH + x] = g->north->addr[g->north->width
					* g->tex_y + g->tex_x];
			else if (g->side == 1 && g->raydiry >= 0)
				g->img->addr[y * WIDTH + x] = g->south->addr[g->south->width
					* g->tex_y + g->tex_x];
			if (g->side == 0 && g->raydirx < 0)
				g->img->addr[y * WIDTH + x] = g->west->addr[g->west->width
					* g->tex_y + g->tex_x];
			else if (g->side == 0 && g->raydirx >= 0)
				g->img->addr[y * WIDTH + x] = g->east->addr[g->east->width
					* g->tex_y + g->tex_x];
			g->texpos += g->step;
		}
		y++;
	}
}

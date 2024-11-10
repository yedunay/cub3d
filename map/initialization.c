/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:16:55 by ydunay - ta       #+#    #+#             */
/*   Updated: 2024/08/28 11:22:15 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <unistd.h>

void	mlx_inited(t_game *g)
{
	g->mlx.mlx = mlx_init();
	if (!g->mlx.mlx)
	{
		write(2, "Error: Mlx initialization problems !!\n", 38);
		exitfunc(g, 2);
	}
	g->mlx.window = mlx_new_window(g->mlx.mlx, W_WIDHT, W_HEIGHT, "cub3D");
	if (!g->mlx.window)
	{
		write(2, "Error: Mlx window initalize problem !!\n", 39);
		exitfunc(g, 2);
	}
}

void	player_map_init(t_game *g, char *map)
{
	g->player.x = -1;
	g->player.y = -1;
	g->player.dir_x = 0;
	g->player.dir_y = -1;
	g->player.direction = 0;
	g->player.turn_radian = 0.04;
	g->player.move_speed = 0.1;
	g->player.plane_x = 0.66;
	g->player.plane_y = 0;
	g->map = (t_map){0};
	g->map.path = ft_strdup(map);
	if (!g->map.path)
		return (exitfunc(g, 1));
}

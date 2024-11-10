/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:11:06 by ydunay            #+#    #+#             */
/*   Updated: 2024/08/28 18:13:27 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

void	exitfunc2(t_game *game, int def)
{
	if (def == 2)
	{
		write (2, "Error: Walls are not closed or invalid char\n", 44);
		exitprogram(game, 2);
	}
	if (def == 3)
	{
		write (2, "Error: There is more than a player\n", 35);
		exitprogram(game, 2);
	}
	if (def == 4)
	{
		write (2, "Error: Invalid char !\n", 22);
		exitprogram(game, 2);
	}
	if (def == 5)
	{
		write (2, "Error: Different than (N,S,W,E,F,C)\
			or missing arguments!!\n", 61);
		exitprogram(game, 2);
	}
}

static void	destroy(t_game *game)
{
	if (game->map.wall.no_texture.img)
		mlx_destroy_image(game->mlx.mlx, game->map.wall.no_texture.img);
	if (game->map.wall.so_texture.img)
		mlx_destroy_image(game->mlx.mlx, game->map.wall.so_texture.img);
	if (game->map.wall.we_texture.img)
		mlx_destroy_image(game->mlx.mlx, game->map.wall.we_texture.img);
	if (game->map.wall.ea_texture.img)
		mlx_destroy_image(game->mlx.mlx, game->map.wall.ea_texture.img);
	mlx_destroy_window(game->mlx.mlx, game->mlx.window);
	free(game->mlx.mlx);
	if (game->map.wall.no_texture.path)
		free(game->map.wall.no_texture.path);
	if (game->map.wall.so_texture.path)
		free(game->map.wall.so_texture.path);
	if (game->map.wall.we_texture.path)
		free(game->map.wall.we_texture.path);
	if (game->map.wall.ea_texture.path)
		free(game->map.wall.ea_texture.path);
}

void	freesplit(char **split)
{
	int	x;

	x = 0;
	while (split[x])
	{
		free(split[x]);
		x++;
	}
	free(split);
}

void	exitprogram(t_game *game, int status)
{
	destroy(game);
	if (game->map.fd)
		close(game->map.fd);
	if (game->map.path)
		free(game->map.path);
	if (game->map.map)
		freesplit(game->map.map);
	if (game->map.tmp_map)
		freesplit(game->map.tmp_map);
	if (game->map.lines)
		freesplit(game->map.lines);
	if (status == 2)
		exit(1);
	write(1, "\x1b[32mProgram is closed.\x1b[0m\n", 28);
	exit(0);
}

void	exitfunc(t_game *game, int status)
{
	if (status == 1)
	{
		write(2, "Error: malloc error !! \n", 24);
		exit(1);
	}
	if (game->map.fd)
		close(game->map.fd);
	if (game->map.path)
		free(game->map.path);
	if (game->map.map)
		freesplit(game->map.map);
	if (game->map.lines)
		freesplit(game->map.lines);
	if (game->map.tmp_map)
		freesplit(game->map.tmp_map);
	if (game->mlx.mlx)
	{
		if (game->mlx.window)
			mlx_destroy_window(game->mlx.mlx, game->mlx.window);
		free(game->mlx.mlx);
	}
	exit(1);
}

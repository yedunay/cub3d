/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:16:59 by ydunay - ta       #+#    #+#             */
/*   Updated: 2024/08/29 10:04:14 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/cub3d.h"
#include "../libft/libft.h"
#include <unistd.h>

static void	zero_in_neighbours(t_game *game, char **map, int i, int j)
{
	if (i == 0 || i == game->map.height - 1 || j == 0 || j == ft_strlen(map[i])
		- 2)
		exitfunc2(game, 2);
	if (is_space(map[i - 1][j]) || is_space(map[i + 1][j]) || is_space(map[i][j
			- 1]) || is_space(map[i][j + 1]))
		exitfunc2(game, 2);
}

static void	set_direction2(t_game *game, t_direction direction)
{
	if (direction == SOUTH)
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	if (direction == WEST)
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
	if (direction == EAST)
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
}

static void	set_direction(t_game *game, char c)
{
	t_direction	direction;

	direction = 0;
	if (c == 'W')
		direction = (WEST);
	else if (c == 'N')
		direction = (NORTH);
	else if (c == 'E')
		direction = (EAST);
	else if (c == 'S')
		direction = (SOUTH);
	game->player.direction = direction;
	if (direction == NORTH)
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else
		set_direction2(game, direction);
}

static void	continue_map_check(t_game *game, char **map, int i, int j)
{
	if (i == 0 || i == game->map.height - 1 || j == 0 || j == ft_strlen(map[i])
		- 2)
		if (map[i][j] != '1' && !is_space(map[i][j]))
			exitfunc2(game, 2);
	if (map[i][j] == 'E' || map[i][j] == 'S' || map[i][j] == 'W'
		|| map[i][j] == 'N')
	{
		if (game->player.x != -1 || game->player.y != -1)
			exitfunc2(game, 3);
		set_direction(game, map[i][j]);
		game->player.x = j + 0.5;
		game->player.y = i + 0.5;
	}
	if (!control_map_char(map[i][j]))
		exitfunc2(game, 4);
}

void	map_checker(t_game *game)
{
	char	**tmp_map;
	int		i;
	int		j;

	i = 0;
	tmp_map = game->map.map;
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			continue_map_check(game, tmp_map, i, j);
			if (tmp_map[i][j] == '0' || tmp_map[i][j] == 'E'
				|| tmp_map[i][j] == 'W' || tmp_map[i][j] == 'N'
				|| tmp_map[i][j] == 'S')
				zero_in_neighbours(game, tmp_map, i, j);
			j++;
		}
		i++;
	}
	if (game->player.x == -1 || game->player.y == -1)
	{
		write(2, "Error: Give me a player you idiot!\n", 35);
		exitprogram(game, 2);
	}
}

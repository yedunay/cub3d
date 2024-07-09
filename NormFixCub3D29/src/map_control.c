/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:11:59 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:20:39 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	map_read(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	game->map.fd = open(game->map.map_name, O_RDONLY);
	if (game->map.fd == -1)
	{
		printf("Error open file\n");
		exit(1);
	}
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.map_height
				+ 1));
	while (1)
	{
		line = get_next_line(game->map.fd);
		if (!line)
			break ;
		game->map.map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	game->map.map[i] = NULL;
	if (i == 0)
		free_all(game, "Error map is empty");
	close(game->map.fd);
}

void	find_size_map(t_game *game)
{
	int		y;
	char	*line;

	y = 0;
	game->map.fd = open(game->map.map_name, O_RDONLY);
	if (game->map.fd == -1)
		free_all(game, "Error open file\n");
	while (1)
	{
		line = get_next_line(game->map.fd);
		if (!line)
			break ;
		y++;
		free(line);
	}
	game->map.map_height = y;
	printf("map_height = %d\n", game->map.map_height);
	close(game->map.fd);
}

void	map_control(t_game *game)
{
	find_size_map(game);
	map_read(game);
	map_parse(game);
	check_info(game);
	take_info(game);
	skip_spaces(game, game->map.endofinfo);
	map_check(game);
	path_finder(game, game->map.posy, game->map.posx);
}

void	path_finder(t_game *game, int y, int x)
{
	if (x < 0 || y < 0 || y >= (game->map.real_height)
		|| game->map.tmp_map[y][x] == ' ' || game->map.tmp_map[y][x] == '\0')
	{
		free_all(game, "Invalid path\n");
	}
	if (game->map.tmp_map[y][x] == '1')
	{
		return ;
	}
	game->map.tmp_map[y][x] = '1';
	path_finder(game, y, x - 1);
	path_finder(game, y - 1, x);
	path_finder(game, y, x + 1);
	path_finder(game, y + 1, x);
}

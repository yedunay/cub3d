/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:17:02 by ydunay - ta       #+#    #+#             */
/*   Updated: 2024/08/29 10:54:05 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/cub3d.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

int	control_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| is_space(c))
		return (1);
	else
		return (0);
}

void	extfdcontrol(char *path, int fd)
{
	int	i;

	i = ft_strlen(path);
	if ((path[i - 1] != 'b' || path[i - 2] != 'u' || path[i - 3] != 'c'
			|| path[i - 4] != '.'))
	{
		write(2, "Error: Extension should end with .cub !!", 40);
		exit(1);
	}
	fd = open(path, O_RDONLY);
	if (fd <= 0)
	{
		write(2, "Error: Open problems file-descriptor couldn't work!!", 52);
		exit(1);
	}
	close(fd);
}

static void	set_line(t_game *game, int y)
{
	char	*line;

	game->map.fd = open(game->map.path, O_RDONLY);
	if (game->map.fd < 0)
	{
		write(2, "Error: Open (read) problems !!\n", 31);
		exitfunc(game, 2);
	}
	game->map.lines = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!(game->map.lines))
		exitfunc(game, 2);
	line = get_next_line(game->map.fd);
	if (!line)
		exitfunc(game, 2);
	while (line)
	{
		game->map.lines[y] = ft_strdup(line);
		if (!game->map.lines[y])
			exitfunc(game, 2);
		free(line);
		line = get_next_line(game->map.fd);
		y++;
	}
	close(game->map.fd);
}

static void	find_height(t_game *game)
{
	char	*line;
	int		height;

	height = 0;
	game->map.fd = open(game->map.path, O_RDONLY);
	if (game->map.fd < 0)
	{
		write(2, "Error: Open (read) problems !!\n", 31);
		exitfunc(game, 2);
	}
	line = get_next_line(game->map.fd);
	if (!line)
		exitfunc(game, 2);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(game->map.fd);
	}
	close(game->map.fd);
	game->map.height = height;
}

void	map_utils(t_game *game)
{
	int	pass;

	pass = 0;
	find_height(game);
	set_line(game, 0);
	pass = set_map_infos(game, 0, 0);
	pass_spaces(game, pass, 0);
	map_checker(game);
}

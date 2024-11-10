/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:17:06 by ydunay - ta       #+#    #+#             */
/*   Updated: 2024/08/29 10:53:00 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/cub3d.h"
#include "../libft/libft.h"
#include <unistd.h>

static void	set_six_values(t_game *game, int *count, char **split)
{
	if (!ft_strcmp(split[0], "NO"))
		*count += set_texture(game, &game->map.wall.no_texture, split[1]);
	else if (!ft_strcmp(split[0], "SO"))
		*count += set_texture(game, &game->map.wall.so_texture, split[1]);
	else if (!ft_strcmp(split[0], "WE"))
		*count += set_texture(game, &game->map.wall.we_texture, split[1]);
	else if (!ft_strcmp(split[0], "EA"))
		*count += set_texture(game, &game->map.wall.ea_texture, split[1]);
	else if (!ft_strcmp(split[0], "F"))
		*count += set_color(&game->map.floor_color, game, split[1]);
	else if (!ft_strcmp(split[0], "C"))
		*count += set_color(&game->map.ceiling_color, game, split[1]);
}

void	pass_spaces(t_game *game, int i, int j)
{
	while (game->map.lines[i])
	{
		j = 0;
		while (is_space(game->map.lines[i][j]) || game->map.lines[i][j] == '\t')
			j++;
		if (game->map.lines[i][j] != '\0')
			break ;
		i++;
	}
	j = 0;
	game->map.map = ft_calloc(game->map.height - i + 1, sizeof(char *));
	if (!game->map.map)
		exitprogram(game, 2);
	while (game->map.lines[i])
	{
		game->map.map[j] = ft_strdup(game->map.lines[i]);
		if (!game->map.map[j])
			exitprogram(game, 2);
		i++;
		j++;
	}
	game->map.map[j] = NULL;
	game->map.height = j;
}

int	is_skipping(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
	{
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	set_map_infos(t_game *game, int i, int sixcount)
{
	char	**parse;

	while (game->map.lines[i])
	{
		while ((game->map.lines[i] == NULL) || is_skipping(game->map.lines[i]))
			i++;
		parse = ft_split(game->map.lines[i]);
		if (!parse)
			exitfunc(game, 2);
		if (parse[1] && (parse[2] && !(is_skipping(parse[2]))))
		{
			write(2, "Error: Invalid path!\n", 21);
			exitfunc(game, 2);
		}
		set_six_values(game, &sixcount, parse);
		freesplit(parse);
		i++;
		if (sixcount == 6)
			break ;
	}
	if (sixcount != 6)
		exitfunc2(game, 5);
	return (i);
}

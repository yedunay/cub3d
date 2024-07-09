/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:13:58 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:11:38 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"

void	take_directions(t_game *game, int flag, int i)
{
	if (flag == 0)
	{
		if (game->map.directions[0] == NULL)
		{
			game->map.directions[0] = ft_strdup(game->map.map[i]);
			game->map.infocount++;
		}
		game->map.flags[0] += 1;
	}
	else if (flag == 1)
	{
		if (game->map.directions[1] == NULL)
		{
			game->map.directions[1] = ft_strdup(game->map.map[i]);
			game->map.infocount++;
		}
		game->map.flags[1] += 1;
	}
}

void	take_directions2(t_game *game, int flag, int i)
{
	if (flag == 2)
	{
		if (game->map.directions[2] == NULL)
		{
			game->map.directions[2] = ft_strdup(game->map.map[i]);
			game->map.infocount++;
		}
		game->map.flags[2] += 1;
	}
	else if (flag == 3)
	{
		if (game->map.directions[3] == NULL)
		{
			game->map.directions[3] = ft_strdup(game->map.map[i]);
			game->map.infocount++;
		}
		game->map.flags[3] += 1;
	}
}

void	take_color_path(t_game *game, char flag, int i)
{
	if (flag == 'F')
	{
		if (game->map.color_path[0] == NULL)
		{
			game->map.color_path[0] = ft_strdup(game->map.map[i]);
			game->map.infocount++;
		}
		game->map.flags[4] += 1;
	}
	else if (flag == 'C')
	{
		if (game->map.color_path[1] == NULL)
		{
			game->map.color_path[1] = ft_strdup(game->map.map[i]);
			game->map.infocount++;
		}
		game->map.flags[5] += 1;
	}
}

int	ft_check_info_map(t_game *game, int i)
{
	int	j;

	j = 0;
	if (game->map.map[i] == NULL)
		return (0);
	while (game->map.map[i][j] != '\0')
	{
		if (!ft_is_white_space(game->map.map[i][j])
			&& game->map.map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

void	map_parse(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i] != NULL)
	{
		if ((ft_strncmp(game->map.map[i], "NO ", 3) == 0))
			take_directions(game, 0, i);
		else if ((ft_strncmp(game->map.map[i], "EA ", 3) == 0))
			take_directions(game, 1, i);
		else if ((ft_strncmp(game->map.map[i], "SO ", 3) == 0))
			take_directions2(game, 2, i);
		else if ((ft_strncmp(game->map.map[i], "WE ", 3) == 0))
			take_directions2(game, 3, i);
		else if ((ft_strncmp(game->map.map[i], "F ", 2) == 0))
			take_color_path(game, 'F', i);
		else if ((ft_strncmp(game->map.map[i], "C ", 2) == 0))
			take_color_path(game, 'C', i);
		i++;
		if (ft_check_info_map(game, i) == 1 && game->map.infocount == 6)
		{
			game->map.endofinfo = i;
			break ;
		}
	}
}

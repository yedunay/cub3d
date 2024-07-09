/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:14:19 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:13:31 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"

void	skip_spaces(t_game *game, int end)
{
	int	i;

	i = 0;
	while (game->map.map[end])
	{
		i = 0;
		if (game->map.map[end][i] == 'N' || game->map.map[end][i] == 'S'
				|| game->map.map[end][i] == 'W' || game->map.map[end][i] == 'E')
			free_all(game, "Player position is not valid");
		while (game->map.map[end][i] == ' ' || game->map.map[end][i] == '\t')
			i++;
		if (game->map.map[end][i] == '\n')
			end++;
		else
		{
			game->map.endofinfo = end;
			break ;
		}
	}
}

int	newline_control(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.endofinfo)
	{
		if (check_line_dir(game->map.map[i], 0) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

void	is_digit_cub(char **str, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\n' && str[i][j] != '\0')
		{
			if (!ft_isdigit(str[i][j]))
			{
				free_array(str, 0);
				free_all(game, "Error value is not digit");
			}
			j++;
		}
		i++;
	}
}

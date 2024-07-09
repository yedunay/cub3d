/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:15:12 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:13:14 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void	free_all(t_game *game, char *str)
{
	if (game->map.map != NULL)
		free_array(game->map.map, 0);
	if (game->map.ceiling != NULL)
		free(game->map.ceiling);
	if (game->map.floor != NULL)
		free(game->map.floor);
	if (game->map.real_map != NULL)
		free_array(game->map.real_map, 0);
	if (game->map.tmp_map != NULL)
		free_array(game->map.tmp_map, 0);
	free_array(game->map.directions, 4);
	free_array(game->map.textures, 4);
	free_array(game->map.color_path, 2);
	free_array(game->map.rgb_color, 2);
	if (game->exit_control)
		free_ray(game);
	printf("%s\n", str);
	exit(1);
}

void	free_ray(t_game *game)
{
	if (game->north)
	{
		mlx_destroy_image(game->mlx, game->north->img);
		free(game->north);
	}
	if (game->south)
	{
		mlx_destroy_image(game->mlx, game->south->img);
		free(game->south);
	}
	if (game->west)
	{
		mlx_destroy_image(game->mlx, game->west->img);
		free(game->west);
	}
	if (game->east)
	{
		mlx_destroy_image(game->mlx, game->east->img);
		free(game->east);
	}
	if (game->img)
	{
		mlx_destroy_image(game->mlx, game->img->img);
		free(game->img);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}

void	free_array(char **str, int size)
{
	int	i;

	i = 0;
	if (size == 0)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			free(str[i]);
			i++;
		}
	}
	if (size == 0)
		free(str);
}

int	check_line_dir(char *map, int i)
{
	char	c;

	while (map[i] != '\0')
	{
		c = map[i];
		if (ft_strncmp(map, "SO ", 3) == 0)
			return (1);
		else if (ft_strncmp(map, "NO ", 3) == 0)
			return (1);
		else if (ft_strncmp(map, "EA ", 3) == 0)
			return (1);
		else if (ft_strncmp(map, "WE ", 3) == 0)
			return (1);
		else if (ft_strncmp(map, "F ", 2) == 0)
			return (1);
		else if (ft_strncmp(map, "C ", 2) == 0)
			return (1);
		else if (c == '\n' || c == ' ')
			i++;
		else if (c == '\0')
			return (1);
		else
			return (0);
	}
	return (1);
}

int	count_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

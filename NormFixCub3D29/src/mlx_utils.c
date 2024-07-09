/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:16:13 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:14:19 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <math.h>

int	close_game(t_game *game)
{
	free_all(game, "Game closed");
	return (0);
}

void	get_image_data_addr(t_game *game)
{
	game->north->addr = (int *)mlx_get_data_addr(game->north->img,
			&game->north->bits_per_pixel, &game->north->line_length,
			&game->north->endian);
	game->east->addr = (int *)mlx_get_data_addr(game->east->img,
			&game->east->bits_per_pixel, &game->east->line_length,
			&game->east->endian);
	game->south->addr = (int *)mlx_get_data_addr(game->south->img,
			&game->south->bits_per_pixel, &game->south->line_length,
			&game->south->endian);
	game->west->addr = (int *)mlx_get_data_addr(game->west->img,
			&game->west->bits_per_pixel, &game->west->line_length,
			&game->west->endian);
	if (!game->north->addr || !game->east->addr || !game->south->addr
		|| !game->west->addr)
		return (game->exit_control = 0, free_all(game, "mlx fail"), (void)0);
}

void	init_game_img(t_game *game)
{
	init_direction(game);
	if (!game->img || !game->north || !game->south || !game->east
		|| !game->west)
		free_all(game, "alloc fail");
	game->img->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img->img)
		return (game->exit_control = 0, free_all(game, "mlx fail"), (void)0);
	game->img->addr = (int *)mlx_get_data_addr(game->img->img,
			&game->img->bits_per_pixel, &game->img->line_length,
			&game->img->endian);
	if (!game->img->addr)
		return (game->exit_control = 0, free_all(game, "mlx fail"), (void)0);
	game->north->img = mlx_xpm_file_to_image(game->mlx, game->map.textures[0],
			&game->north->width, &game->north->height);
	game->east->img = mlx_xpm_file_to_image(game->mlx, game->map.textures[1],
			&game->east->width, &game->east->height);
	game->south->img = mlx_xpm_file_to_image(game->mlx, game->map.textures[2],
			&game->south->width, &game->south->height);
	game->west->img = mlx_xpm_file_to_image(game->mlx, game->map.textures[3],
			&game->west->width, &game->west->height);
	if (!game->north->img || !game->east->img || !game->south->img
		|| !game->west->img)
		return (game->exit_control = 0, free_all(game, "mlx fail"), (void)0);
	check_texture_size(game);
	get_image_data_addr(game);
}

void	check_texture_size(t_game *game)
{
	if (game->north->width > 1920 || game->north->height > 1080)
		free_all(game, "Texture size is too big");
	if (game->east->width > 1920 || game->east->height > 1080)
		free_all(game, "Texture size is too big");
	if (game->south->width > 1920 || game->south->height > 1080)
		free_all(game, "Texture size is too big");
	if (game->west->width > 1920 || game->west->height > 1080)
		free_all(game, "Texture size is too big");
	return ;
}

void	init_direction(t_game *game)
{
	game->img = malloc(sizeof(t_image));
	game->north = malloc(sizeof(t_image));
	game->south = malloc(sizeof(t_image));
	game->east = malloc(sizeof(t_image));
	game->west = malloc(sizeof(t_image));
	game->map.textures[0] = ft_strtrim(game->map.textures[0], "\n");
	game->map.textures[1] = ft_strtrim(game->map.textures[1], "\n");
	game->map.textures[2] = ft_strtrim(game->map.textures[2], "\n");
	game->map.textures[3] = ft_strtrim(game->map.textures[3], "\n");
}

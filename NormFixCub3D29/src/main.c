/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:48:06 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:19:52 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	check_format(char *map_name)
{
	int	i;

	i = 0;
	i = ft_strlen(map_name);
	if (i < 4 || map_name[i - 1] != 'b' || map_name[i - 2] != 'u' || map_name[i
			- 3] != 'c' || map_name[i - 4] != '.')
	{
		printf("Error file format\n");
		exit(1);
	}
	printf("File format OK\n");
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		printf("Error Arg\n");
		return (1);
	}
	check_format(av[1]);
	map_init(&game);
	game.map.map_name = av[1];
	map_control(&game);
	raycast_init(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cub3D");
	init_game_img(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 1L << 17, close_game, &game);
	mlx_loop_hook(game.mlx, &raycast, &game);
	mlx_loop(game.mlx);
	free_all(&game, "Map ok");
}

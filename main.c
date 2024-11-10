/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:17:43 by taksin            #+#    #+#             */
/*   Updated: 2024/08/28 15:15:44 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "minilibx/mlx.h"
#include <unistd.h>

static void	convert_rgb(t_color *color)
{
	color->color = (color->r << 16 | color->g << 8 | color->b);
	color->defined = true;
}

static int	keypress(int keycode, void *param)
{
	t_game	*key;

	key = (t_game *)param;
	if (keycode == 13)
		key->keys.w = true;
	if (keycode == 0)
		key->keys.a = true;
	if (keycode == 1)
		key->keys.s = true;
	if (keycode == 2)
		key->keys.d = true;
	if (keycode == 123)
		key->keys.left = true;
	if (keycode == 124)
		key->keys.right = true;
	if (keycode == 53)
		exitprogram(key, 1);
	return (0);
}

static int	keyrelease(int keyrls, void *param)
{
	t_game	*keys;

	keys = (t_game *)param;
	if (keyrls == 13)
		keys->keys.w = false;
	if (keyrls == 0)
		keys->keys.a = false;
	if (keyrls == 1)
		keys->keys.s = false;
	if (keyrls == 2)
		keys->keys.d = false;
	if (keyrls == 123)
		keys->keys.left = false;
	if (keyrls == 124)
		keys->keys.right = false;
	return (0);
}

static int	exitgame(void *gameadr)
{
	t_game	*game;

	game = (t_game *)gameadr;
	if (game->img.img)
		mlx_destroy_image(game->mlx.mlx, game->img.img);
	exitprogram(game, 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		extfdcontrol(av[1], game.map.fd);
		player_map_init(&game, av[1]);
		mlx_inited(&game);
		map_utils(&game);
		game.img.img = mlx_new_image(game.mlx.mlx, W_WIDHT, W_HEIGHT);
		if (!game.img.img)
			exitprogram(&game, 2);
		game.img.addr = (int *)mlx_get_data_addr(game.img.img,
				&game.img.bits_per_pixel, &game.img.line_lenght,
				&game.img.endian);
		convert_rgb(&game.map.floor_color);
		convert_rgb(&game.map.ceiling_color);
		mlx_hook(game.mlx.window, 2, 1L, keypress, &game);
		mlx_hook(game.mlx.window, 3, 2L, keyrelease, &game);
		mlx_loop_hook(game.mlx.mlx, gameloop, &game);
		mlx_hook(game.mlx.window, 17, 1L << 17, exitgame, &game);
		mlx_loop(game.mlx.mlx);
	}
	else
		write(2, "Error: Wrong arguments!\n", 24);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:17:18 by ydunay - ta       #+#    #+#             */
/*   Updated: 2024/08/29 12:08:31 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_wall(t_game *game, int x, t_ray *ray, int y)
{
	if (ray->side == 1 && ray->ray_dir_y < 0)
		game->img.addr[y * W_WIDHT + x] = \
			game->map.wall.no_texture.addr
		[game->map.wall.no_texture.width * ray->texture.y + ray->texture.x];
	else if (ray->side == 1 && ray->ray_dir_y >= 0)
		game->img.addr[y * W_WIDHT + x] = \
			game->map.wall.so_texture.addr
		[game->map.wall.so_texture.width * ray->texture.y + ray->texture.x];
	if (ray->side == 0 && ray->ray_dir_x < 0)
		game->img.addr[y * W_WIDHT + x] = \
			game->map.wall.we_texture.addr
		[game->map.wall.we_texture.width * ray->texture.y + ray->texture.x];
	else if (ray->side == 0 && ray->ray_dir_x >= 0)
		game->img.addr[y * W_WIDHT + x] = \
			game->map.wall.ea_texture.addr
		[game->map.wall.ea_texture.width * ray->texture.y + ray->texture.x];
	ray->texture.pos += ray->step;
}

static void	draw_line(t_game *game, int x, t_ray *ray)
{
	int	y;

	y = 0;
	while (y < W_HEIGHT)
	{
		ray->texture.y = (int)ray->texture.pos;
		if (y < ray->draw_start)
			game->img.addr[y * W_WIDHT + x] = game->map.ceiling_color.color;
		else if (y > ray->draw_end)
			game->img.addr[y * W_WIDHT + x] = game->map.floor_color.color;
		else
			draw_wall(game, x, ray, y);
		y++;
	}
}

void	raycast(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < W_WIDHT)
	{
		calc_pos_dir(game, &ray, x);
		ray.map_x = (int)game->player.x;
		ray.map_y = (int)game->player.y;
		calc_delta_dist(&ray);
		calc_side_distandstep(game, &ray);
		dda_func(game, &ray);
		calc_texture_width_height(game, &ray);
		calc_perp_wall_dist(&ray);
		calc_start_end_draw(&ray);
		calc_texture(game, &ray);
		draw_line(game, x, &ray);
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcolortexture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay - taksin <<ydunay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:17:08 by ydunay - ta       #+#    #+#             */
/*   Updated: 2024/08/28 18:03:24 by ydunay - ta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <unistd.h>

static int	check_is_digit(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (j == 0)
			{
				if (split[i][j] == '\n')
					return (1);
			}
			if (!ft_isdigit(split[i][j]) && split[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	set_texture(t_game *game, t_image *image, char *path)
{
	image->path = ft_strtrim(path, " \n\v\t\r\f");
	if (!image->path)
	{
		write(2, "Error: Path couldn't allocated !\n", 33);
		exitprogram(game, 2);
	}
	image->img = mlx_xpm_file_to_image(game->mlx.mlx, image->path,
			&image->width, &image->height);
	if (!image->img)
	{
		write(2, "Error: Texture path is not valid!\n", 34);
		exitprogram(game, 2);
	}
	image->addr = (int *)mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_lenght, &image->endian);
	return (1);
}

static int	ft_argindex(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	set_color(t_color *color, t_game *game, char *split)
{
	char	**parse;

	parse = ft_split2(split);
	if (!parse)
		return (write(2, "Error: Color is not allocated !\n", 32),
			exitprogram(game, 2), 1);
	if (ft_argindex(parse) != 3 || check_is_digit(parse))
	{
		freesplit(parse);
		write(2, "Error: No many argument index and digit!\n", 41);
		exitprogram(game, 2);
	}
	if (color->defined == false && parse[0] && parse[1] && parse[2])
	{
		color->r = ft_atoi(parse[0]);
		color->g = ft_atoi(parse[1]);
		color->b = ft_atoi(parse[2]);
		freesplit(parse);
		if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
			|| color->b < 0 || color->b > 255)
			return (write(2, "Error: Color is not valid !\n", 28),
				exitprogram(game, 2), 1);
		return (color->defined = true, 1);
	}
	return (freesplit(parse), 0);
}

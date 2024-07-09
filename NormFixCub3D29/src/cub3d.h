/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdur <eozdur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:43:38 by eozdur            #+#    #+#             */
/*   Updated: 2024/02/29 13:03:24 by eozdur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1080
# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef struct s_image
{
	void	*img;
	int		*addr;
	int		num;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_map
{
	char	**map;
	int		map_height;
	int		real_height;
	char	*map_name;
	char	**tmp_map;
	int		fd;
	char	*floor;
	char	*ceiling;
	char	**real_map;
	char	*directions[4];
	char	*textures[4];
	int		playercount;
	int		posx;
	int		posy;
	char	pov;
	char	*color_path[2];
	char	*rgb_color[2];
	int		flags[6];
	int		infocount;
	int		endofinfo;
	int		f_color;
	int		c_color;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_image	*img;
	t_image	*north;
	t_image	*south;
	t_image	*west;
	t_image	*east;
	float	speed;
	float	rotspeed;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perp_wall_dist;
	double	wallx;
	double	raydirx;
	double	raydiry;
	double	step;
	double	texpos;
	int		color;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		line_h;
	int		floor;
	int		ceiling;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	int		tex_width;
	int		tex_height;
	int		exit_control;
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
	bool	shift;
}			t_game;

void		find_direction(t_game *g);
void		init_direction(t_game *game);
void		check_texture_size(t_game *game);
void		check_tmp_map(t_game *game);
bool		check_player(t_game *game);
void		ray1(t_game *g, int x);
void		ray2(t_game *g);
void		ray3(t_game *game);
void		ray4(t_game *g);
void		free_ray(t_game *game);
void		raycasting(t_game *g);
void		rotate(t_game *g);
void		render_column(t_game *g, int x, int y);
void		movement2(t_game *game);
void		movement(t_game *game);
int			raycast(t_game *game);
int			close_game(t_game *game);
int			key_press(int keyCode, t_game *game);
int			key_release(int keyCode, t_game *game);
void		get_image_data_addr(t_game *game);
void		init_game_img(t_game *game);
void		raycast_init(t_game *game);
void		map_control(t_game *game);
void		find_size_map(t_game *game);
void		map_parse(t_game *game);
void		check_info(t_game *game);
void		map_check(t_game *game);
void		map_init(t_game *game);
void		init_array(t_game *game);
void		free_all(t_game *game, char *str);
int			check_color(char **tmp);
void		free_array(char **str, int size);
int			copy_map(t_game *game, int y, int x);
void		map_print(t_game *game);
void		check_characters(t_game *game);
void		create_tmp_map(t_game *game);
int			ft_is_white_space(char c);
void		take_directions2(t_game *game, int flag, int i);
void		check_characters(t_game *game);
void		is_digit_cub(char **str, t_game *game);
void		map_print_info(t_game *game);
void		create_real_map(t_game *game);
void		take_textures(t_game *game);
void		skip_spaces(t_game *game, int end);
void		take_info(t_game *game);
int			newline_control(t_game *game);
int			count_comma(char *str);
void		path_finder(t_game *game, int y, int x);
int			check_line_dir(char *map, int i);
int			get_rgb_color(char *str, t_game *game);
void		take_rgbcolor(t_game *game);

#endif

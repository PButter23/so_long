/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:48:44 by arde-jes          #+#    #+#             */
/*   Updated: 2025/03/05 11:50:11 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "mlx/mlx.h"
# include "external_functions/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
}				t_data;

typedef struct	s_game
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	char		**map;
	t_player	player;
	char		*map_path;
}				t_game;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	draw_blue_square(t_data *data);
int		create_trgb(int t, int r, int g, int b);
int		distribute_color(char c);
char	**original_map(int fd, t_data *data);
void	draw_cell(int x, int y, int color, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_game(t_game *game, const char *map_path);
void	start_loop_game(t_game *game);
int		key_hook(int keycode, void *param);
char	**draw_map(t_game *game);
void	movement_conditions(t_game *game, int x, int y);
void	render_map(t_game *game);
int		count_lines(int fd);
char	**allocate_map(int height);
int		read_map(int fd, char **map);
void	find_player_cords(t_game *game);

#endif
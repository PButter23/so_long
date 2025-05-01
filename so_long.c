/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:02:39 by arde-jes          #+#    #+#             */
/*   Updated: 2025/03/05 12:02:41 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, const char *map_path)
{
	t_data	img;
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Erro ao abrir arquivo");
		return ;
	}
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1000, 600, "Hello world!");
	game->img.img = mlx_new_image(game->mlx, 1000, 600);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	game->map = original_map(fd, &img);
	close(fd);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
}

void	start_loop_game(t_game *game)
{
	mlx_key_hook(game->mlx_win, key_hook, &game->player);
	mlx_loop(game->mlx);
}

void	find_players_cords(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	fprintf(stderr, "player não encontrado\n");
	return ;
}

void	draw_map(t_game *game)
{

}

int	main(void)
{
	t_game	game;

	init_game(&game, "maps/hard.ber");
	start_loop_game(&game);
	return (0);
}
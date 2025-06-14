/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:03:04 by arde-jes          #+#    #+#             */
/*   Updated: 2025/03/05 17:03:05 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			color = distribute_color(game->map[y][x]);
			draw_cell(x, y, color, &game->img);
			x++;
		}
		y++;
	}
	color = distribute_color('P');
	draw_cell(game->player.x, game->player.y, color, &game->img);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
}
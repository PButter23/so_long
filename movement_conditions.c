/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:03:04 by arde-jes          #+#    #+#             */
/*   Updated: 2025/03/05 17:03:05 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_remaining_collectibles(t_game *game)
{
	int	height;
	int	lenght;
	int	count_C;

	height = 0;
	count_C = 0;
	while (game->map[height] != NULL)
	{
		lenght = 0;
		while (game->map[height][lenght] != '\0')
		{
			if (game->map[height][lenght] == 'C')
				count_C++;
			lenght++;
		}
		height++;
	}
	return (count_C);
}

void	movement_conditions(t_game *game, int x, int y)
{
	int	count_C;
	int	height;
	int	width;

	height = 0;
	width = ft_strlen(game->map[0]);
	if (x < 0 || y < 0 || y >= height || x >= width)
		return;
	while (game->map[height])
		height++;
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		if (game->map[y][x] == 'C')
			game->map[y][x] = '0';
		render_map(game);
	}
	else if (game->map[y][x] == 'E')
	{
		count_C = check_remaining_collectibles(game);
		if (count_C == 0)
			render_map(game);
	}
	else if (game->map[y][x] == '1')
	{
		game->player.x = x;
		game->player.y = y;
	}
	return ;
}
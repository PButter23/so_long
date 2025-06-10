/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:03:04 by arde-jes          #+#    #+#             */
/*   Updated: 2025/03/05 17:03:05 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ESC_KEY 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100

int	key_hook(int keycode, void *param)
{
	t_game	*game;
	int		new_x;
	int		new_y;

	game = (t_game *)param;
	new_x = game->player.x;
	new_y = game->player.y;
	if (keycode == ESC_KEY)
		exit(0);
	else if (keycode == W_KEY)
		game->player.y -= 1;
	else if (keycode == A_KEY)
		game->player.x -= 1;
	else if (keycode == S_KEY)
		game->player.y += 1;
	else if (keycode == D_KEY)
		game->player.x += 1;
	movement_conditions(game, new_x, new_y);
	return(0);
}
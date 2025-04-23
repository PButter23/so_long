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
	t_player	*player;

	player = (t_player *)param;
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == W_KEY)
		player->y -= 1;
	if (keycode == A_KEY)
		player->y += 1;
	if (keycode == S_KEY)
		player->x -= 1;
	if (keycode == D_KEY)
		player->x += 1;
	return(0);
}
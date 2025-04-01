/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:33:22 by arde-jes          #+#    #+#             */
/*   Updated: 2025/03/06 14:33:25 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	distribute_color(char c)
{
	if (c == 'P')
		return (0xFF0000);
	else if (c == 'E')
		return (0x00FF00);
	else if (c == 'C')
		return (0xFFFF00);
	else if (c == '0')
		return (0xFFFFFF);
	else if (c == '1')
		return (0xFF0000);
	return (0xFFFFFF);
}

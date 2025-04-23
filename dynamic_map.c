/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:03:04 by arde-jes          #+#    #+#             */
/*   Updated: 2025/03/05 17:03:05 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		c;
	int		a;

	a = 0;
	c = 0;
	while (s[c] != '\0')
	{
		c++;
	}
	ptr = (char *)malloc((c + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[a] != '\0')
	{
		ptr[a] = s[a];
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}

int	calculate_height(char **original_map)
{
	int	height;

	height = 0;
	while (!*original_map[height])
		height++;
	return (height);
}

char	**create_dynamic_map(int height)
{
	char	**map;
	int	y;

	y = 0;
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	while (y < height)
	{
		map[y] = NULL;
		y++;
	}
	map[height] = NULL;
	return (map);
}

void	copy_to_dynamic_map(char **original_map, char **dynamic_map, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		dynamic_map[y] = ft_strdup(original_map[y]);
		if (!dynamic_map[y])
		{
			perror("Erro ao duplicar linha do mapa");
			exit(1);
		}
		y++;
	}
	dynamic_map[height] = NULL;
}

void	dynamic_map(char **original_map, t_data *data, t_player player)
{
	char	**dynamic_map;
	int		height;

	height = calculate_height(original_map);
	dynamic_map = create_dynamic_map(height);
	copy_to_dynamic_map(original_map, dynamic_map, height);
	
}
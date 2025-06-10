/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   original_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:03:04 by arde-jes          #+#    #+#             */
/*   Updated: 2025/03/05 17:03:05 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	ct;
	size_t	lens;
	char	*n;

	lens = 0;
	lens = ft_strlen((char *)s);
	if (start >= lens)
	{
		n = (char *)malloc(1);
		n[0] = '\0';
		return (n);
	}
	ct = 0;
	if (len > lens - start)
		len = lens - start;
	n = (char *)malloc ((len + 1) * sizeof(char));
	if (n == NULL)
		return (NULL);
	while (ct < len)
	{
		n[ct] = s[ct + start];
		ct++;
	}
	n[ct] = '\0';
	return (n);
}

int	count_lines(int fd)
{
	int		ct;
	char	*line;

	ct = 0;
	line = get_next_line(fd);
	while (line)
	{
		ct++;
		free(line);
		line = get_next_line(fd);
	}
	return (ct);
}

char	**allocate_map(int height)
{
	char	**map;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	map[height] = NULL;
	return (map);
}

int	read_map(int fd, char **map)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[y] = ft_substr(line, 0, ft_strlen(line));
		free(line);
		if (!map[y])
		{
			while (y-- >= 0)
				free(map[y]);
			free(map);
			return (0);
		}
		y++;
		line = get_next_line(fd);
	}
	return (1);
}

char	**original_map(int fd, t_data *data)
{
	int		height;
	char	**map;

	if (!data)
		return (NULL);
	height = count_lines(fd);
	if (height <= 0)
		return (NULL);
	map = allocate_map(height);
	if (!map)
		return (NULL);
	if (!read_map(fd, map))
		return (NULL);
	return (map);
}

char	**draw_map(t_game *game)
{
	int y;
	int x;
	int color;

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
	return (game->map);
}

void	draw_cell(int x, int y, int color, t_data *data)
{
	int	cell_size;
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	if (!data)
		return;
	cell_size = 32;
	start_x = x * cell_size;
	start_y = y * cell_size;
	j = start_y;
	while (j < start_y + cell_size)
	{
		i = start_x;
		while (i < start_x + cell_size)
		{
			my_mlx_pixel_put(data, i, j, color);
			i++;
		}
		j++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!data)
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

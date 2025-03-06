/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_image_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:03:04 by arde-jes          #+#    #+#             */
/*   Updated: 2025/03/05 17:03:05 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(int fd, t_data *data)
{
	char	*line;
	int		y;
	int		x;
	int		color;

	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		x = 0;
		while (line[x] != '\0')
		{
			if (line[x] == 'P' || line[x] == 'E' || line[x] == '0'
				|| line[x] == '1' || line[x] == 'C')
			{
				color = distribute_color(line[x]);
				draw_cell(x, y, color, data);
			}
			x++;
		}
		free(line);
		line = get_next_line(fd);
		y++;
	}
}

void	draw_cell(int x, int y, int color, t_data *data)
{
	int	cell_size;
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	cell_size = 32;
	start_x = x * cell_size;
	start_y = y * cell_size;
	j = start_y;
	while (j < start_y + cell_size)
	{
		i = start_x;
		while (i < start_x+ cell_size)
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

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	fd;

	fd = open("maps/hard.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("Erro ao abrir arquivo");
		return (1);
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_map(fd, &img);
	close(fd);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

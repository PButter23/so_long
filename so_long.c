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
	original_map(fd, &img);
	close(fd);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
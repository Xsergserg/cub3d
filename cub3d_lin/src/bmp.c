/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 18:25:09 by rbeach            #+#    #+#             */
/*   Updated: 2020/08/04 17:23:23 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	img_writer(int fd, t_vars *cube, t_bitmap *bmp)
{
	int x;
	int y;
	int *image;

	if (!(image = malloc(bmp->biwidth * bmp->biheight * (sizeof(int)))))
		return (ft_err("Malloc error", 0));
	y = 0;
	while (y < bmp->biheight)
	{
		x = 0;
		while (x < bmp->biwidth)
		{
			image[y * bmp->biwidth + x] = *(int*)(cube->img.addr +\
			((bmp->biheight - y) * cube->img.line_length + x *\
			(cube->img.bits_per_pixel / 8)));
			x++;
		}
		y++;
	}
	write(fd, image, bmp->bisizeimage);
	free(image);
	return (1);
}

static void	bitmap_write(t_bitmap bmp, t_vars *cube)
{
	int fd;

	if ((fd = open("cub3d_screenshot.bmp", O_WRONLY | O_CREAT |
	O_TRUNC | O_APPEND, 0777)) < 0)
		return (perror("Error\n"));
	write(fd, &bmp.bftype, 2);
	write(fd, &bmp.bfsize, 4);
	write(fd, &bmp.bfreserved1, 2);
	write(fd, &bmp.bfreserved2, 2);
	write(fd, &bmp.bfoffbits, 4);
	write(fd, &bmp.bisize, 4);
	write(fd, &bmp.biwidth, 4);
	write(fd, &bmp.biheight, 4);
	write(fd, &bmp.biplanes, 2);
	write(fd, &bmp.bibitcount, 2);
	write(fd, &bmp.bicompression, 4);
	write(fd, &bmp.bisizeimage, 4);
	write(fd, &bmp.bixpelspermeter, 4);
	write(fd, &bmp.biypelspermeter, 4);
	write(fd, &bmp.biclrused, 4);
	write(fd, &bmp.biclrimportant, 4);
	img_writer(fd, cube, &bmp);
	close(fd);
}

void		bmp_saver(t_vars *cube)
{
	t_bitmap	bmp;

	bmp.bftype[0] = 'B';
	bmp.bftype[1] = 'M';
	bmp.bfsize = 54 + 4 * (g_cube.r_x * g_cube.r_y);
	bmp.bfreserved1 = 0;
	bmp.bfreserved2 = 0;
	bmp.bfoffbits = 54;
	bmp.bisize = 40;
	bmp.biwidth = g_cube.r_x;
	bmp.biheight = g_cube.r_y;
	bmp.biplanes = 1;
	bmp.bibitcount = 32;
	bmp.bicompression = 0;
	bmp.bisizeimage = 4 * g_cube.r_y * g_cube.r_x;
	bmp.bixpelspermeter = 0;
	bmp.biypelspermeter = 0;
	bmp.biclrused = 0;
	bmp.biclrimportant = 0;
	bitmap_write(bmp, cube);
	destroy_win(cube);
}

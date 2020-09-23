/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:48:44 by rbeach            #+#    #+#             */
/*   Updated: 2020/08/01 21:13:13 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		print_sprite_pixel(t_vars *cube, int *offset, int size, int *cord)
{
	int		color;

	color = color_check(cube->s, (int)((float)cube->s.w /
	size * cord[0]), (int)((float)cube->s.h / size * cord[1]));
	if (color > 0)
	{
		my_mlx_pixel_put(&cube->img, offset[0] + cord[0],\
		offset[1] + cord[1], color);
	}
}

void		line_print(int x, double *p, t_vars *cube, double rad)
{
	int		height;
	int		y_start;
	int		cord[2];

	cord[0] = x;
	cord[1] = 0;
	height = g_cube.r_y / (p[2] * cos(rad - g_cube.view_dir)) * g_cube.scale;
	y_start = (g_cube.r_y - height) / 2;
	while (cord[1] < g_cube.r_y)
	{
		if (cord[1] < y_start)
			my_mlx_pixel_put(&cube->img, x, cord[1], g_cube.ceil_col);
		else if (cord[1] >= y_start && cord[1] < y_start + height)
			texturer(cube, cord, height, p);
		else
			my_mlx_pixel_put(&cube->img, x, cord[1], g_cube.floor_col);
		cord[1]++;
	}
}

void		print_rays(t_vars *cube)
{
	double	current;
	double	finish;
	double	step;
	int		i;

	i = 0;
	current = g_cube.view_dir - (g_cube.vow / 2);
	finish = g_cube.view_dir + (g_cube.vow / 2);
	step = (finish - current) / (g_cube.r_x);
	while (i < g_cube.r_x)
	{
		print_ray(rad_abs(current), cube, i, g_cube.my_pos);
		current += step;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 22:18:48 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/30 16:49:07 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		north_texture(t_vars *cube, int *cord, int height, double *p)
{
	float	y;
	float	x;
	float	h;
	int		color;

	y = cord[1] - ((g_cube.r_y - height) / 2);
	h = (float)height / (float)g_cube.y_col;
	if (y)
		y = (y - (int)(y / h) * h) * cube->no.h / h;
	x = p[0] - (int)(p[0] / g_cube.box_side) * g_cube.box_side;
	if (x)
	{
		x = x - (int)(x / ((float)g_cube.box_side / g_cube.x_col)) *\
		((float)g_cube.box_side / g_cube.x_col);
		x = x / ((float)g_cube.box_side / g_cube.x_col / cube->no.w);
	}
	color = color_check(cube->no, (int)x, (int)y);
	my_mlx_pixel_put(&cube->img, cord[0], cord[1], color);
}

static void		south_texture(t_vars *cube, int *cord, int height, double *p)
{
	float	y;
	float	x;
	float	h;
	int		color;

	y = cord[1] - ((g_cube.r_y - height) / 2);
	h = (float)height / (float)g_cube.y_col;
	if (y)
		y = (y - (int)(y / h) * h) * cube->so.h / h;
	x = p[0] - (int)(p[0] / g_cube.box_side) * g_cube.box_side;
	if (x)
	{
		x = x - (int)(x / ((float)g_cube.box_side / g_cube.x_col)) *\
		((float)g_cube.box_side / g_cube.x_col);
		x = x / ((float)g_cube.box_side / g_cube.x_col / cube->so.w);
	}
	color = color_check(cube->so, (int)x, (int)y);
	my_mlx_pixel_put(&cube->img, cord[0], cord[1], color);
}

static void		west_texture(t_vars *cube, int *cord, int height, double *p)
{
	float	y;
	float	x;
	float	h;
	int		color;

	h = (float)height / (float)g_cube.y_col;
	y = cord[1] - ((g_cube.r_y - height) / 2);
	if (y)
		y = (y - (int)(y / h) * h) * cube->we.h / h;
	x = p[1] - (int)(p[1] / g_cube.box_side) * g_cube.box_side;
	if (x)
	{
		x = x - (int)(x / ((float)g_cube.box_side / g_cube.x_col)) *\
		((float)g_cube.box_side / g_cube.x_col);
		x = x / ((float)g_cube.box_side / g_cube.x_col / cube->we.w);
	}
	color = color_check(cube->we, (int)x, (int)y);
	my_mlx_pixel_put(&cube->img, cord[0], cord[1], color);
}

static void		east_texture(t_vars *cube, int *cord, int height, double *p)
{
	float	y;
	float	x;
	float	h;
	int		color;

	h = (float)height / (float)g_cube.y_col;
	y = cord[1] - ((g_cube.r_y - height) / 2);
	if (y)
		y = (y - (int)(y / h) * h) * cube->ea.h / h;
	x = p[1] - (int)(p[1] / g_cube.box_side) * g_cube.box_side;
	if (x)
	{
		x = x - (int)(x / ((float)g_cube.box_side / g_cube.x_col)) *\
		((float)g_cube.box_side / g_cube.x_col);
		x = x / ((float)g_cube.box_side / g_cube.x_col / cube->ea.w);
	}
	color = color_check(cube->ea, (int)x, (int)y);
	my_mlx_pixel_put(&cube->img, cord[0], cord[1], color);
}

void			texturer(t_vars *cube, int *cord, int height, double *p)
{
	if (p[3] == 1)
		south_texture(cube, cord, height, p);
	else if (p[3] == 2)
		north_texture(cube, cord, height, p);
	else if (p[3] == 3)
		west_texture(cube, cord, height, p);
	else if (p[3] == 4)
		east_texture(cube, cord, height, p);
}

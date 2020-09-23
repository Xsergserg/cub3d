/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:31:22 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/31 20:04:07 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	y_crosser2(double rad, double *p, double *dis)
{
	if (p[0] < 0 || p[0] > g_cube.cols * g_cube.box_side || p[1] < 0 ||
	p[1] > g_cube.lines * g_cube.box_side)
	{
		p[2] = -1;
		return ;
	}
	while (ft_strchr("02NSWE", g_cube.map[(int)(p[1] / g_cube.box_side)]\
	[(int)(p[0] / g_cube.box_side)]))
	{
		p[0] += dis[0];
		p[1] += dis[1];
		if (p[0] < 0 || p[0] > g_cube.cols * g_cube.box_side || p[1] < 0 ||
		p[1] > g_cube.lines * g_cube.box_side)
		{
			p[2] = -1;
			return ;
		}
	}
	p[2] = (g_cube.my_pos[0] - p[0]) / cos(rad);
	if (p[2] < 0)
		p[2] = p[2] * (-1);
}

static void	y_crosser(double rad, double *p, float *cord)
{
	double	dis[2];

	if (rad > M_PI)
		p[1] = floor(cord[1] / g_cube.box_side) * g_cube.box_side - 0.00001;
	else if (rad < M_PI)
		p[1] = floor(cord[1] / g_cube.box_side) * g_cube.box_side +\
		g_cube.box_side;
	else
	{
		p[2] = -1;
		return ;
	}
	if (rad > M_PI)
		dis[1] = -g_cube.box_side;
	else
		dis[1] = g_cube.box_side;
	p[0] = cord[0] - (cord[1] - p[1]) / tan(rad);
	if (rad > M_PI / 2 && rad < 3 * M_PI / 2)
		dis[0] = -num_abs(g_cube.box_side / tan(rad));
	else
		dis[0] = num_abs(g_cube.box_side / tan(rad));
	y_crosser2(rad, p, dis);
}

static void	x_crosser2(double rad, double *p, double *dis)
{
	if (p[0] < 0 || p[0] > g_cube.cols * g_cube.box_side || p[1] < 0 ||
	p[1] > g_cube.lines * g_cube.box_side)
	{
		p[2] = -1;
		return ;
	}
	while (ft_strchr("02NSWE", g_cube.map[(int)(p[1] / g_cube.box_side)]\
	[(int)(p[0] / g_cube.box_side)]))
	{
		p[0] += dis[0];
		p[1] += dis[1];
		if (p[0] < 0 || p[0] > g_cube.cols * g_cube.box_side || p[1] < 0 ||
		p[1] > g_cube.lines * g_cube.box_side)
		{
			p[2] = -1;
			return ;
		}
	}
	p[2] = (g_cube.my_pos[0] - p[0]);
	p[2] = p[2] / cos(rad);
	if (p[2] < 0)
		p[2] = p[2] * (-1);
}

static void	x_crosser(double rad, double *p, float *cord)
{
	double		dis[2];

	if ((rad > (M_PI / 2)) && (rad < 3 * (M_PI / 2)))
		p[0] = floor(cord[0] / g_cube.box_side) * g_cube.box_side - 0.00001;
	else if ((rad < (M_PI / 2)) || (rad > (3 * M_PI / 2)))
		p[0] = floor(cord[0] / g_cube.box_side) * g_cube.box_side +\
		g_cube.box_side;
	else
	{
		p[2] = -1;
		return ;
	}
	if ((rad > (M_PI / 2)) && (rad < (3 * M_PI / 2)))
		dis[0] = -g_cube.box_side;
	else
		dis[0] = g_cube.box_side;
	p[1] = cord[1] - (cord[0] - p[0]) * tan(rad);
	if (rad > M_PI)
		dis[1] = -num_abs(g_cube.box_side * tan(rad));
	else
		dis[1] = num_abs(g_cube.box_side * tan(rad));
	x_crosser2(rad, p, dis);
}

void		print_ray(double rad, t_vars *cube, int m, float *cord)
{
	double	ver[5];
	double	hor[5];
	double	*p;

	y_crosser(rad, hor, cord);
	x_crosser(rad, ver, cord);
	if (hor[2] < 0 || ver[2] < 0)
		p = hor[2] < 0 ? ver : hor;
	else
		p = ver[2] < hor[2] ? ver : hor;
	if (p == hor)
		p[3] = rad < M_PI ? 1 : 2;
	else if (p == ver)
		p[3] = rad > M_PI / 2 && rad < 3 * M_PI / 2 ? 3 : 4;
	g_cube.col_dist[m] = p[2];
	line_print(m, p, cube, rad);
}

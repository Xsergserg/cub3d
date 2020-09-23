/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:46:00 by rbeach            #+#    #+#             */
/*   Updated: 2020/08/01 21:17:06 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				sprite_fuller(void)
{
	int	x;
	int	y;
	int i;

	if (!(g_cube.sp = malloc(g_cube.sprite_col * sizeof(t_sp))))
		return (0);
	ft_memset(g_cube.sp, 0, g_cube.sprite_col * sizeof(t_sp));
	x = 0;
	i = 0;
	while (x < g_cube.cols)
	{
		y = 0;
		while (y < g_cube.lines)
		{
			if (g_cube.map[y][x] == '2')
			{
				g_cube.sp[i].x = x * g_cube.box_side + g_cube.box_side / 2;
				g_cube.sp[i].y = y * g_cube.box_side + g_cube.box_side / 2;
				i++;
			}
			y++;
		}
		x++;
	}
	return (1);
}

static void		sprite_texturer(t_vars *cube, int size, int *offset, float dist)
{
	int	cord[2];
	int	x_lim;
	int	y_lim;

	cord[0] = offset[0] < 0 ? -offset[0] : 0;
	x_lim = offset[0] + size >= g_cube.r_x ? g_cube.r_x - offset[0] : size;
	y_lim = offset[1] + size >= g_cube.r_y ? g_cube.r_y - offset[1] : size;
	while (cord[0] < x_lim)
	{
		cord[1] = offset[1] < 0 ? -offset[1] : 0;
		if (dist < g_cube.col_dist[offset[0] + cord[0]])
		{
			while (cord[1] < y_lim)
			{
				print_sprite_pixel(cube, offset, size, cord);
				cord[1]++;
			}
		}
		cord[0]++;
	}
}

static void		print_sprite(t_sp *cord, t_vars *cube)
{
	float	sprite_dir;
	int		size;
	int		offset[2];

	sprite_dir = atan2(cord->y - g_cube.my_pos[1], cord->x - g_cube.my_pos[0]);
	while (sprite_dir - g_cube.view_dir > M_PI)
		sprite_dir -= 2 * M_PI;
	while (sprite_dir - g_cube.view_dir < -M_PI)
		sprite_dir += 2 * M_PI;
	size = g_cube.r_y / cord->dist * g_cube.scale;
	offset[0] = (sprite_dir - g_cube.view_dir) * (g_cube.r_x /\
	(g_cube.view_angle * M_PI / 180)) + g_cube.r_x / 2 - size / 2;
	offset[1] = g_cube.r_y / 2 - size / 2;
	if (offset[0] < g_cube.r_x || offset[0] + size >= 0)
		sprite_texturer(cube, size, offset, cord->dist);
}

static void		sprite_sort(void)
{
	int		i;
	int		m;
	int		more;
	t_sp	tmp;

	i = g_cube.sprite_col - 1;
	more = 1;
	while (i && more)
	{
		more = 0;
		m = g_cube.sprite_col;
		while (m > 1)
		{
			if (g_cube.sp[m - 1].dist > g_cube.sp[m - 2].dist)
			{
				tmp = g_cube.sp[m - 1];
				g_cube.sp[m - 1] = g_cube.sp[m - 2];
				g_cube.sp[m - 2] = tmp;
				more = 1;
			}
			m--;
		}
		i--;
	}
}

void			print_sprites(t_vars *cube)
{
	int i;

	i = 0;
	while (i < g_cube.sprite_col)
	{
		g_cube.sp[i].dist = num_abs(sqrt(pow(g_cube.my_pos[0] -\
		g_cube.sp[i].x, 2) + pow(g_cube.my_pos[1] - g_cube.sp[i].y, 2)));
		i++;
	}
	i = 0;
	if (g_cube.sprite_col > 1)
		sprite_sort();
	while (i < g_cube.sprite_col)
	{
		print_sprite(&g_cube.sp[i], cube);
		i++;
	}
}

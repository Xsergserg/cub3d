/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:50:44 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/30 16:47:33 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	key_strafe(t_vars *cube, int key)
{
	float	new_pos[2];

	if (key == 0x61 || key == 0)
	{
		new_pos[0] = g_cube.my_pos[0] + g_cube.step *\
		cos(g_cube.view_dir - M_PI / 2) / 2;
		new_pos[1] = g_cube.my_pos[1] + g_cube.step *\
		sin(g_cube.view_dir - M_PI / 2) / 2;
	}
	else
	{
		new_pos[0] = g_cube.my_pos[0] +
		g_cube.step * cos(g_cube.view_dir + M_PI / 2);
		new_pos[1] = g_cube.my_pos[1] +
		g_cube.step * sin(g_cube.view_dir + M_PI / 2);
	}
	if (ft_strchr("02NSWE", g_cube.map[(int)(new_pos[1] / g_cube.box_side)]\
	[(int)(new_pos[0] / g_cube.box_side)]))
	{
		g_cube.my_pos[1] = new_pos[1];
		g_cube.my_pos[0] = new_pos[0];
		map_creator(cube);
		mlx_put_image_to_window(cube->mlx, cube->win, cube->img.img, 0, 0);
	}
}

static void	key_right_left(t_vars *cube, int key)
{
	g_cube.view_dir = (key == 0xff53 || key == 124) ?
	rad_abs(g_cube.view_dir + g_cube.rot) :\
	rad_abs(g_cube.view_dir - g_cube.rot);
	map_creator(cube);
}

static void	key_back_forward(t_vars *cube, int key)
{
	float	new_pos[2];

	if (key == 0xff52 || key == 0x77 || key == 126 || key == 13)
	{
		new_pos[0] = g_cube.my_pos[0] + g_cube.step * cos(g_cube.view_dir);
		new_pos[1] = g_cube.my_pos[1] + g_cube.step * sin(g_cube.view_dir);
	}
	else
	{
		new_pos[0] = g_cube.my_pos[0] +
		g_cube.step * cos(g_cube.view_dir + M_PI);
		new_pos[1] = g_cube.my_pos[1] +
		g_cube.step * sin(g_cube.view_dir + M_PI);
	}
	if (ft_strchr("02NSWE", g_cube.map[(int)(new_pos[1] / g_cube.box_side)]\
	[(int)(new_pos[0] / g_cube.box_side)]))
	{
		g_cube.my_pos[1] = new_pos[1];
		g_cube.my_pos[0] = new_pos[0];
		map_creator(cube);
		mlx_put_image_to_window(cube->mlx, cube->win, cube->img.img, 0, 0);
	}
}

int			key_handle(int keycode, t_vars *vars)
{
	if (keycode == 0xff52 || keycode == 0x77 || keycode == 0xff54 ||
	keycode == 0x73 || keycode == 126 || keycode == 125 || keycode == 13 \
	|| keycode == 1)
		key_back_forward(vars, keycode);
	if (keycode == 0xff53 || keycode == 0xff51 || keycode == 124 ||
	keycode == 123)
		key_right_left(vars, keycode);
	if (keycode == 0x61 || keycode == 0x64 || keycode == 2 || keycode == 0)
		key_strafe(vars, keycode);
	if (keycode == 65307 || keycode == 53)
		destroy_win(vars);
	return (1);
}

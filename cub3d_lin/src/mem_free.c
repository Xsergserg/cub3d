/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:30:04 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/30 16:47:57 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_err(char *msg, char **text)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (text)
		full_mem_free(text);
	return (0);
}

int			full_mem_free(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (0);
}

int			mem_free(char **ptr, int i)
{
	int m;

	m = 0;
	while (m < i)
	{
		free(ptr[m]);
		ptr[m] = NULL;
		m++;
	}
	free(ptr);
	ptr = NULL;
	return (0);
}

void		struct_free(void)
{
	if (g_cube.so)
		free(g_cube.so);
	if (g_cube.no)
		free(g_cube.no);
	if (g_cube.ea)
		free(g_cube.ea);
	if (g_cube.we)
		free(g_cube.we);
	if (g_cube.sprite)
		free(g_cube.sprite);
	if (g_cube.col_dist)
		free(g_cube.col_dist);
	if (g_cube.sp)
		free(g_cube.sp);
	if (g_cube.map_exist)
		full_mem_free(g_cube.map);
}

void		cube_free(t_vars *cube)
{
	if (cube->img.img)
		mlx_destroy_image(cube->mlx, cube->img.img);
	if (cube->so.img)
		mlx_destroy_image(cube->mlx, cube->so.img);
	if (cube->no.img)
		mlx_destroy_image(cube->mlx, cube->no.img);
	if (cube->ea.img)
		mlx_destroy_image(cube->mlx, cube->ea.img);
	if (cube->we.img)
		mlx_destroy_image(cube->mlx, cube->we.img);
	if (cube->s.img)
		mlx_destroy_image(cube->mlx, cube->s.img);
	if (cube->win)
		mlx_destroy_window(cube->mlx, cube->win);
	free(cube->mlx);
}

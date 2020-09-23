/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 09:30:41 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/30 16:49:27 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			color_fuller(char x)
{
	int *ptr;
	int *arr;

	arr = NULL;
	ptr = NULL;
	if (x == 'C')
	{
		ptr = &g_cube.ceil_col;
		arr = g_cube.ceil;
	}
	else
	{
		ptr = &g_cube.floor_col;
		arr = g_cube.floor;
	}
	*ptr = arr[0] * 256 * 256 + arr[1] * 256 + arr[2];
	return (1);
}

double		rad_abs(double rad)
{
	if (rad < 0)
		rad += 2 * M_PI;
	if (rad > (2 * M_PI))
		rad -= (2 * M_PI);
	return (rad);
}

double		num_abs(double num)
{
	return (num < 0 ? -num : num);
}

int			color_check(t_data data, int x, int y)
{
	return (*(unsigned int*)(data.addr + (y * data.line_length +\
	x * (data.bits_per_pixel / 8))));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfc_opt_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:32:01 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/30 16:48:47 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	color_checker(char x)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (x == 'C' && (g_cube.ceil[i] < 0 || g_cube.ceil[i] > 255))
			return (0);
		if (x == 'F' && (g_cube.floor[i] < 0 || g_cube.floor[i] > 255))
			return (0);
		i++;
	}
	return (color_fuller(x));
}

static int	digit_checker(char **arr_color)
{
	int i;
	int m;

	i = 0;
	m = 0;
	while (arr_color[i])
	{
		m = 0;
		while (arr_color[i][m])
		{
			if (!ft_isdigit(arr_color[i][m]))
				return (0);
			m++;
		}
		i++;
	}
	return (1);
}

static int	color_writer(char *color, char x)
{
	char	**arr_color;
	int		arg_num;

	arg_num = 0;
	if (!(arr_color = ft_split(color, ',')))
		return (0);
	while (arr_color[arg_num])
		arg_num++;
	if (arg_num != 3 || !digit_checker(arr_color))
		return (full_mem_free(arr_color));
	if (x == 'F')
	{
		g_cube.floor[0] = ft_atoi(arr_color[0]);
		g_cube.floor[1] = ft_atoi(arr_color[1]);
		g_cube.floor[2] = ft_atoi(arr_color[2]);
	}
	if (x == 'C')
	{
		g_cube.ceil[0] = ft_atoi(arr_color[0]);
		g_cube.ceil[1] = ft_atoi(arr_color[1]);
		g_cube.ceil[2] = ft_atoi(arr_color[2]);
	}
	full_mem_free(arr_color);
	return (color_checker(x));
}

int			struct_sfc_fuller(char **line, int arg_num)
{
	if (arg_num == 2 && !ft_strncmp(line[0], "S", 2) && !g_cube.sprite)
		return ((g_cube.sprite = ft_strdup(line[1])) ? 1 : 0);
	if (arg_num == 2 && !ft_strncmp(line[0], "F", 2) && g_cube.floor[0] < 0)
		return (color_writer(line[1], 'F'));
	if (arg_num == 2 && !ft_strncmp(line[0], "C", 2) && g_cube.ceil[0] < 0)
		return (color_writer(line[1], 'C'));
	return (0);
}

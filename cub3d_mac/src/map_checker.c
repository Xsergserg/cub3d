/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:02:03 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/31 18:45:36 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	my_pos_fuller(int y, int x, char sow)
{
	int angle;

	if (sow == 'S')
		angle = 90;
	if (sow == 'N')
		angle = 270;
	if (sow == 'E')
		angle = 0;
	if (sow == 'W')
		angle = 180;
	g_cube.view_dir = angle * M_PI / 180;
	g_cube.box_side = 2;
	g_cube.my_pos[0] = x * g_cube.box_side + (g_cube.box_side / 2);
	g_cube.my_pos[1] = y * g_cube.box_side + (g_cube.box_side / 2);
	return (1);
}

static int	sym_check(int i, int m)
{
	if (ft_strchr(" 1", g_cube.map[i][m]))
		return (1);
	if (i == 0 || m == 0 || i == g_cube.lines - 1 || m == g_cube.cols - 1)
		return (0);
	if (g_cube.map[i - 1][m] == ' ' || g_cube.map[i + 1][m] == ' ' ||
	g_cube.map[i][m - 1] == ' ' || g_cube.map[i][m + 1] == ' ')
		return (0);
	return (1);
}

int			map_checker(void)
{
	int i;
	int m;
	int x;

	i = 0;
	x = 0;
	while (g_cube.map[i])
	{
		m = 0;
		while (g_cube.map[i][m])
		{
			if (!ft_strchr(" 012NSEW", g_cube.map[i][m]))
				return (ft_err("Wrong syms on map", NULL));
			if (ft_strchr("NSEW", g_cube.map[i][m]))
				x += my_pos_fuller(i, m, g_cube.map[i][m]);
			if (!sym_check(i, m))
				return (ft_err("Wrong map", NULL));
			if (g_cube.map[i][m] == '2')
				g_cube.sprite_col++;
			m++;
		}
		i++;
	}
	return (x == 1 ? 1 : ft_err("Start pos err", NULL));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 11:19:11 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/31 19:15:37 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	arg_checker(int argc, char **argv)
{
	int a_l;

	if (argc == 1)
		return (ft_err("Too few arguments", NULL));
	if (argc > 3)
		return (ft_err("Too many arguments", NULL));
	a_l = ft_strlen(argv[1]);
	if (a_l < 5 || argv[1][a_l - 1] != 'b' || argv[1][a_l - 2] != 'u' ||
	argv[1][a_l - 3] != 'c' || argv[1][a_l - 4] != '.')
		return (ft_err("Wrong extension, not \".cub\"", NULL));
	if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2]) + 1))
		return (ft_err("Unknown flag", NULL));
	return (1);
}

static int	variables_fuller(void)
{
	g_cube.view_angle = 66;
	g_cube.vow = g_cube.view_angle * M_PI / 180;
	g_cube.y_col = 1;
	g_cube.x_col = 2;
	g_cube.scale = 1;
	g_cube.step = 1;
	g_cube.rot = 0.05;
	if (!(g_cube.col_dist = malloc(g_cube.r_x * sizeof(double))))
		return (ft_err("g_cube.col_dist malloc err", 0));
	if (!sprite_fuller())
		return (ft_err("g_cube.sp malloc err", 0));
	return (1);
}

int			main(int argc, char **argv)
{
	if (!arg_checker(argc, argv))
		return (1);
	ft_memset(&g_cube, 0, sizeof(g_cube));
	ft_memset(&g_cube.floor, -1, sizeof(int) * 3);
	ft_memset(&g_cube.ceil, -1, sizeof(int) * 3);
	if (argc == 3)
		g_cube.save = 1;
	if (file_opener(argv[1]))
	{
		if (variables_fuller())
			cube_graph();
	}
	struct_free();
	return (1);
}

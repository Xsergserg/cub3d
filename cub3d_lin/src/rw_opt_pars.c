/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rw_opt_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:30:55 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/30 16:48:43 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	digit_test(char *test)
{
	int i;

	i = 0;
	while (test[i])
	{
		if (!ft_isdigit(test[i]))
			return (0);
		i++;
	}
	return (1);
}

int			struct_rw_fuller(char **line, int arg_num)
{
	if (arg_num == 3 && !ft_strncmp(line[0], "R", 2) && !g_cube.r_x &&
	!g_cube.r_y && digit_test(line[1]) && digit_test(line[2]))
	{
		g_cube.r_x = ft_atoi(line[1]);
		g_cube.r_y = ft_atoi(line[2]);
		return (1);
	}
	if (arg_num == 2 && !ft_strncmp(line[0], "SO", 3) && !g_cube.so)
		return ((g_cube.so = ft_strdup(line[1])) ? 1 : 0);
	if (arg_num == 2 && !ft_strncmp(line[0], "NO", 3) && !g_cube.no)
		return ((g_cube.no = ft_strdup(line[1])) ? 1 : 0);
	if (arg_num == 2 && !ft_strncmp(line[0], "WE", 3) && !g_cube.we)
		return ((g_cube.we = ft_strdup(line[1])) ? 1 : 0);
	if (arg_num == 2 && !ft_strncmp(line[0], "EA", 3) && !g_cube.ea)
		return ((g_cube.ea = ft_strdup(line[1])) ? 1 : 0);
	return (0);
}

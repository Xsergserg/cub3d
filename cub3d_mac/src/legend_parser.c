/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:00:47 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/30 16:47:37 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	legend_selector(char *line)
{
	char	**split_line;
	int		arg_num;

	arg_num = 0;
	if (!(split_line = ft_split(line, ' ')))
		return (ft_err("Malloc problem", 0));
	while (split_line[arg_num])
		arg_num++;
	if (!(struct_rw_fuller(split_line, arg_num) ||
	struct_sfc_fuller(split_line, arg_num)))
		return (ft_err("Wrong legend", split_line));
	full_mem_free(split_line);
	return (1);
}

static int	legend_checker(char **text, int i)
{
	if (!(g_cube.no && g_cube.so && g_cube.ea && g_cube.we && g_cube.sprite &&
	g_cube.floor[0] >= 0 && g_cube.ceil[0] >= 0 && g_cube.r_x > 0 &&
	g_cube.r_y > 0))
		return (ft_err("Wrong data in legend", text));
	return (map_parser(text, i));
}

int			legend_parser(char **text)
{
	int i;

	i = 0;
	while (text[i])
	{
		if (text[i][0])
		{
			if (ft_strncmp(text[i], "R ", 2) &&
			ft_strncmp(text[i], "SO ", 3) && ft_strncmp(text[i], "NO ", 3) &&
			ft_strncmp(text[i], "WE ", 3) && ft_strncmp(text[i], "EA ", 3) &&
			ft_strncmp(text[i], "S ", 2) && ft_strncmp(text[i], "F ", 2) &&
			ft_strncmp(text[i], "C ", 2))
				return (legend_checker(text, i));
			if (!legend_selector(text[i]))
				return (full_mem_free(text));
		}
		i++;
	}
	return (ft_err("legend or map are empty", text));
}

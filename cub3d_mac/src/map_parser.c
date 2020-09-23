/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:44:13 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/30 16:47:46 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_strcpy(char *dest, const char *src)
{
	int				i;

	i = 0;
	if (!src)
		return ;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
}

static int	map_fuller(char **text, int i)
{
	int m;

	m = 0;
	while (text[i + m] && text[i + m][0])
	{
		if (!(g_cube.map[m] = (char*)malloc(sizeof(char) * (g_cube.cols + 1))))
			return (mem_free(g_cube.map, m));
		ft_memset(g_cube.map[m], ' ', (sizeof(char) * g_cube.cols));
		g_cube.map[m][g_cube.cols] = '\0';
		ft_strcpy(g_cube.map[m], text[i + m]);
		m++;
	}
	full_mem_free(text);
	return (1);
}

static int	extra_lines_check(char **text, int i)
{
	int m;

	m = 0;
	while (text[i + m])
	{
		if (text[i + m][0])
			return (0);
		m++;
	}
	return (1);
}

int			map_parser(char **text, int i)
{
	while (text[i] && !text[i][0])
		i++;
	while (text[i + g_cube.lines] && text[i + g_cube.lines][0] &&
	text[i + g_cube.lines][0] != '\n')
	{
		if (ft_strlen(text[i + g_cube.lines]) > g_cube.cols)
			g_cube.cols = ft_strlen(text[i + g_cube.lines]);
		g_cube.lines++;
	}
	if (!extra_lines_check(text, i + g_cube.lines))
		return (ft_err("Unnecessary not empty extra lines", text));
	if (g_cube.lines < 3 && g_cube.cols < 3)
		return (ft_err("Too small map", text));
	if (!(g_cube.map = (char**)malloc(sizeof(char*) * (g_cube.lines + 1))))
		return (ft_err("Map malloc error", text));
	g_cube.map_exist = 1;
	g_cube.map[g_cube.lines] = 0;
	if (!map_fuller(text, i))
		return (ft_err("Map fuller error", text));
	return (map_checker());
}

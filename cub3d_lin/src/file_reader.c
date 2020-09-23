/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:46:31 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/30 16:47:22 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	text_fuller(char **text, int l_num, char *filename)
{
	int i;
	int fd;

	i = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		perror("Error\n");
		free(text);
		return (0);
	}
	while (i < l_num)
	{
		if ((get_next_line(fd, &text[i])) < 0)
		{
			ft_err("text_fuller malloc error", NULL);
			return (mem_free(text, i));
		}
		i++;
	}
	close(fd);
	return (legend_parser(text));
}

int			file_opener(char *filename)
{
	int		fd;
	int		l_num;
	char	**text;
	char	buf[1];

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		perror("Error\n");
		return (0);
	}
	l_num = 1;
	while (read(fd, buf, 1))
		if (buf[0] == '\n')
			l_num++;
	close(fd);
	if (!(text = (char**)malloc(sizeof(char*) * (l_num + 1))))
	{
		perror("Error\n");
		return (0);
	}
	text[l_num] = 0;
	return (text_fuller(text, l_num, filename));
}

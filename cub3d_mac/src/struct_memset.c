/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_memset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:03:24 by rbeach            #+#    #+#             */
/*   Updated: 2020/07/30 16:48:52 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	struct_memset(t_vars *cube)
{
	cube->img.img = NULL;
	cube->so.img = NULL;
	cube->no.img = NULL;
	cube->ea.img = NULL;
	cube->we.img = NULL;
	cube->s.img = NULL;
}

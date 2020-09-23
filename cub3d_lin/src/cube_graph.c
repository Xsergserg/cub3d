/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:27:56 by rbeach            #+#    #+#             */
/*   Updated: 2020/08/01 21:15:54 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			destroy_win(t_vars *cube)
{
	cube_free(cube);
	struct_free();
	exit(1);
}

static void	adress_texture_fuller(t_vars *cube)
{
	cube->no.addr = mlx_get_data_addr(cube->no.img, &cube->no.bits_per_pixel,\
	&cube->no.line_length, &cube->no.endian);
	cube->so.addr = mlx_get_data_addr(cube->so.img, &cube->so.bits_per_pixel,\
	&cube->so.line_length, &cube->so.endian);
	cube->we.addr = mlx_get_data_addr(cube->we.img, &cube->we.bits_per_pixel,\
	&cube->we.line_length, &cube->we.endian);
	cube->ea.addr = mlx_get_data_addr(cube->ea.img, &cube->ea.bits_per_pixel,\
	&cube->ea.line_length, &cube->ea.endian);
	cube->s.addr = mlx_get_data_addr(cube->s.img, &cube->s.bits_per_pixel,\
	&cube->s.line_length, &cube->s.endian);
}

static int	textures_fuller(t_vars *cube)
{
	struct_memset(cube);
	cube->no.img = mlx_xpm_file_to_image(cube->mlx,\
	g_cube.no, &cube->no.w, &cube->no.h);
	cube->so.img = mlx_xpm_file_to_image(cube->mlx,\
	g_cube.so, &cube->so.w, &cube->so.h);
	cube->we.img = mlx_xpm_file_to_image(cube->mlx,\
	g_cube.we, &cube->we.w, &cube->we.h);
	cube->ea.img = mlx_xpm_file_to_image(cube->mlx,\
	g_cube.ea, &cube->ea.w, &cube->ea.h);
	cube->s.img = mlx_xpm_file_to_image(cube->mlx,\
	g_cube.sprite, &cube->s.w, &cube->s.h);
	if (!cube->no.img || !cube->so.img || !cube->we.img ||
	!cube->ea.img || !cube->s.img)
	{
		ft_err("Can't make xpm_file_to_image", 0);
		destroy_win(cube);
	}
	adress_texture_fuller(cube);
	return (1);
}

void		map_creator(t_vars *cube)
{
	t_data	new_img;
	t_data	*old_img;

	new_img.img = mlx_new_image(cube->mlx, g_cube.r_x, g_cube.r_y);
	new_img.addr = mlx_get_data_addr(new_img.img,\
	&new_img.bits_per_pixel, &new_img.line_length, &new_img.endian);
	old_img = NULL;
	if (cube->img.img)
		old_img = cube->img.img;
	cube->img = new_img;
	print_rays(cube);
	print_sprites(cube);
	if (g_cube.save)
		return (bmp_saver(cube));
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img.img, 0, 0);
	if (old_img)
		mlx_destroy_image(cube->mlx, old_img);
}

void		cube_graph(void)
{
	t_vars	cube;
	int		sizex;
	int		sizey;

	cube.mlx = NULL;
	cube.mlx = mlx_init();
	mlx_do_key_autorepeaton(cube.mlx);
	cube.win = NULL;
	textures_fuller(&cube);
	if (!g_cube.save)
	{
		mlx_get_screen_size(cube.mlx, &sizex, &sizey);
		g_cube.r_x = (g_cube.r_x > sizex && !g_cube.save) ? sizex : g_cube.r_x;
		g_cube.r_y = (g_cube.r_y > sizey && !g_cube.save) ? sizey : g_cube.r_y;
		cube.win = mlx_new_window(cube.mlx, g_cube.r_x, g_cube.r_y, "Cube3D");
	}
	map_creator(&cube);
	mlx_hook(cube.win, 2, 1L << 0, &key_handle, &cube);
	mlx_hook(cube.win, 17, 0L, &destroy_win, &cube);
	mlx_loop(cube.mlx);
}

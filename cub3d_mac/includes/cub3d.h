/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 11:31:48 by rbeach            #+#    #+#             */
/*   Updated: 2020/08/01 20:55:32 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define M_PI 3.1415926
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct {
	char	bftype[2];
	int		bfsize;
	short	bfreserved1;
	short	bfreserved2;
	int		bfoffbits;
	int		bisize;
	int		biwidth;
	int		biheight;
	short	biplanes;
	short	bibitcount;
	int		bicompression;
	int		bisizeimage;
	int		bixpelspermeter;
	int		biypelspermeter;
	int		biclrused;
	int		biclrimportant;
}			t_bitmap;

typedef struct {
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
	void	*img;
	char	*addr;
}			t_data;

typedef struct {
	t_data	img;
	t_data	no;
	t_data	ea;
	t_data	we;
	t_data	so;
	t_data	s;
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct {
	int		x;
	int		y;
	float	dist;
}			t_sp;

typedef struct {
	int		r_x;
	int		r_y;
	int		box_side;
	char	*so;
	char	*no;
	char	*ea;
	char	*we;
	char	*sprite;
	int		cols;
	int		lines;
	float	step;
	float	rot;
	int		min_dis;
	int		ray_color;
	float	my_pos[2];
	double	view_dir;
	float	vow;
	int		view_angle;
	int		floor[3];
	int		ceil[3];
	int		floor_col;
	int		ceil_col;
	int		map_exist;
	float	y_col;
	float	x_col;
	int		scale;
	char	**map;
	double	*col_dist;
	int		sprite_col;
	int		save;
	t_sp	*sp;
}			t_leg;

t_leg		g_cube;

int			file_opener (char *filename);
int			ft_err(char *msg, char **text);
int			mem_free(char **ptr, int i);
int			full_mem_free(char **ptr);
void		struct_free(void);
void		cube_free(t_vars *cube);
int			legend_parser(char **text);
int			struct_rw_fuller(char **line, int arg_num);
int			struct_sfc_fuller(char **line, int arg_num);
int			map_parser(char **text, int i);
int			map_checker(void);
void		cube_graph(void);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		print_objects(t_data *img, t_data *img2);
int			key_handle(int keycode, t_vars *cube);
void		map_creator(t_vars *cube);
int			color_check(t_data data, int x, int y);
int			color_fuller (char x);
void		print_rays(t_vars *cube);
void		print_ray (double rad, t_vars *cube, int m, float *cord);
double		rad_abs(double rad);
double		num_abs(double num);
void		line_print(int x, double *p, t_vars *cube, double rad);
int			sprite_fuller();
void		print_sprites(t_vars *cube);
void		texturer (t_vars *cube, int *cord, int height, double *p);
void		bmp_saver(t_vars *cube);
int			destroy_win(t_vars *cube);
void		struct_memset(t_vars *cube);
void		print_sprite_pixel(t_vars *cube, int *offset, int size, int *cord);

#endif

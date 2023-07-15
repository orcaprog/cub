/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:56:05 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/15 16:21:59 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"

# define MOVE_SPEED 20
# define M_G 14
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img_b;
	void	*img_n;
	void	*img_s;
	void	*img_w;
	void	*img_e;
	void	*i_w0;
	void	*i_w1;
	void	*i_w2;
	void	*i_w3;
	void	*i_c;
	void	*i_c1;
	void	*k_0;
	void	*k_1;
	void	*k_2;
	void	*k_3;
	void	*p_s;
	
	
}	t_mlx;

typedef struct s_point
{
	int		check;
	double x;
	double y;
	double r;
} t_point;

typedef struct s_img
{
	char	dir;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		heigth;
	char	*addr;
	void	*ptr;
	struct s_img *next;
} t_img;

typedef struct s_var
{
	int		x;
	int		y;
	int		s_x;
	int		end_x;
	int		s_y;
	int		end_y;
	int		org_x;
	int		org_y;
	int		check;
	double	cor_rd;
} t_var;

typedef struct s_info
{
	int		check_shot;
	int		numb_shot;
	int		change_wap;
	int		x_mouse;
	int		y_mouse;
	int		size;
	int		width;
	double	width1;
	int		d;
	int		f;
	int		c;
	int		x_d;
	int		y_d;
	int		p_v;
	double	x;
	double	y;
	double	p_x;
	double	p_y;
	t_img	*img;
	t_img	*big_img;
	t_img	*mini_img;
	char	**map;
	char	**map0;
	double	corner;
	double	r_corner;
	double	last_r;
	t_mlx	*mlx;
}	t_info;

int		mouse_view(int x, int y, t_info *cub);
void	check_cmp(char **map);
void	ft_puterr(char *err);
void	check_cmp_valid(char **map);
char	**get_map(char *file);
void	check_nwline(char *map);
void	store_info(char **map, t_info *cub);
int		my_color(char *color);
void	point_of_view(t_info *data);
void	cheak_map(char **map);
void	put_pix(t_info *cub,t_img *img, int color);
void	move_right(t_info *data,int size);
void	move_left(t_info *data,int size);
void	move_up(t_info *data,int size);
void	move_down(t_info *data,int size);
int		input_key(int key, t_info *data);
int		prm_moves(char **map,int x ,int y);
int		a_event1(int key, t_info *cub);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	draw_mini_map(t_info *cub);
t_img	*new_img(t_info *cub,char *str, char c);
void	add_img(t_img **lst, t_img *new);
void	check_name_map(char *nmap);
t_info	get_position(char **str);
void	put_pix_mini(t_img*img, double x, double y, int color);
void	change_wap(t_info *cub);
void	draw_wap(t_info *cub,void *img,int x,int  y);
void	put_pistol(t_info *cub);
void	put_knife(t_info *cub);
void	get_xpm_file(t_info *cub);
int		draw_wapeans(t_info *cub);


// aelidrys
void	ft_error(void);
void	ft_free(char **str);
char	**get_element(char *str);
int		size_of_arry(char **arry);
int		str_comp(char *s1, char *s2);
void	draw_simple_map(t_info *cub);
int		a_event(int key, t_info *cub);
int		check_first_element(char **arry);
void	start_cub(t_info *cub, char **av);
t_point	draw_ray(t_info *cub, double cor_rd);
int		get_color(t_img *data, int x, int y);
int		draw_rays(t_info *cub, double cor_rd);
void	det_direction(t_info *cub, double cor_rd);
void	draw_east_walls(t_info *cub, t_point p, int a);
void	draw_west_walls(t_info *cub, t_point p, int a);
void	draw_south_walls(t_info *cub, t_point p, int a);
void	draw_north_walls(t_info *cub, t_point p, int a);
void	my_mlx_pixel_put1(t_img *data, int x, int y, int color);
t_point	det_coord_x(t_info *cub, double cor_rd, int k, int size);
t_point	det_coord_y(t_info *cub, double cor_rd, int k, int size);
int		is_coord_in_map_range(t_info *cub, double x, double y, int size);

#endif
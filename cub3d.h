/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:27:45 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/21 06:25:19 by aelidrys         ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img_b;
	void	*img_n;
	void	*img_s;
	void	*img_w;
	void	*img_e;
}	t_mlx;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	int		check;
	double x;
	double y;
	double r;
} t_point;
typedef struct s_info
{
	int		width;
	int		d;
	int		f;
	int		c;
	int		x_d;
	int		y_d;
	int		p_v;
	double		x;
	double		y;
	double	p_x;
	double	p_y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**map;
	char	**map0;
	double	corner;
	double	r_corner;
	double	last_r;
	t_data	*img;
	t_mlx	*mlx;
}	t_info;


void	check_cmp(char **map);
void	ft_puterr(char *err);
void	check_cmp_valid(char **map);
char	**get_map(char *file);
void	check_nwline(char *map);
void	store_info(char **map, t_info *cub);
int		my_color(char *color);
void	point_of_view(t_info *data);
void	cheak_map(char **map);
void	put_pix(t_info *cub,t_data *img, int color);
void	move_right(t_info *data);
void	move_left(t_info *data);
void	move_up(t_info *data);
void	move_down(t_info *data);
int		input_key(int key, t_info *data);
int		prm_moves(char **map,int x ,int y);
t_point	find_cord_x(t_info *data);
int		a_event1(int key, t_info *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_simple_map1(t_info *cub);

// aelidrys
void	ft_error(void);
void	ft_free(char **str);
char	**get_element(char *str);
int		size_of_arry(char **arry);
int		str_comp(char *s1, char *s2);
void	draw_simple_map(t_info *cub);
int		a_event(int key, t_info *cub);
int		check_first_element(char **arry);
void	draw_ray(t_info *cub, int ri, int rf, int color);
void	det_direction(t_info *cub, double cor_rd);
t_point	det_coord_x(t_info *cub, double cor_rd, int k[2]);
t_point	det_coord_y(t_info *cub, double cor_rad, int k[2]);
int		is_coord_in_map_range(t_info *cub, double x, double y);
int		draw_rays(t_info *cub, double cor_rd, int color);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:27:45 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/11 11:07:45 by abouassi         ###   ########.fr       */
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


typedef struct s_info
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	int		p_v;
	char	**map;
	int		x;
	int		y;
	double	corner;
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
void    put_pix(t_info *cub, int color);
void    move_right(t_info *data);
void    move_left(t_info *data);
void    move_up(t_info *data);
void    move_down(t_info *data);

// aelidrys
void	ft_free(char **str);
char	**get_element(char *str);
int		size_of_arry(char **arry);
int		str_comp(char *s1, char *s2);
void	draw_simple_map(t_info *cub);
int		check_first_element(char **arry);

#endif
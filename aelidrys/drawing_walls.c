/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 07:36:49 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/15 17:11:32 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_img	*get_img(t_info *cub, char dir)
{
	t_img	*tmp;

	tmp = cub->img;
	while (tmp)
	{
		if (tmp->dir == dir)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	draw_east_walls(t_info *cub, t_point p, int a)
{
	double	y;
	float	grid_y;
	int		start;
	t_img	*img;

	img = get_img(cub, 'E');
	if (cub->map[(int)(p.y / 100)][(int)(p.x / 100)] == 'D')
		img = cub->img_d;
	grid_y = (img->heigth * 1.0)/(a * 2);
	if (a > 500)
		y = (a - 500) * grid_y;
	if (a >= 500)
		a = 500;
	start = (1000 - a * 2)/2;
	cub->width1 = (int)(img->width * (p.y / cub->size)) % img->width;
	while (start < 500 + a)
	{
		my_mlx_pixel_put1(cub->big_img, cub->width, start++, get_color(img,cub->width1,y));
		y += grid_y;
	}
}

void	draw_west_walls(t_info *cub, t_point p, int a)
{
	double	y;
	float	grid_y;
	int		start;
	t_img	*img;

	img = get_img(cub, 'W');
	if (cub->map[(int)(p.y / 100)][(int)(p.x / 100) - 1] == 'D')
		img = cub->img_d;
	grid_y = (img->heigth * 1.0)/(a * 2);
	if (a > 500)
		y = (a - 500) * grid_y;
	if (a >= 500)
		a = 500;
	start = (1000 - a * 2)/2;
	cub->width1 = (int)(img->width * (p.y / cub->size)) % img->width;
	while (start < 500 + a)
	{
		my_mlx_pixel_put1(cub->big_img, cub->width, start++, get_color(img, cub->width1,y));
		y += grid_y;
	}
}

void	draw_north_walls(t_info *cub, t_point p, int a)
{
	double	y;
	float	grid_y;
	int		start;
	t_img	*img;

	img = get_img(cub, 'N');
	if (cub->map[(int)(p.y / 100) - 1][(int)(p.x / 100)] == 'D')
		img = cub->img_d;
	grid_y = (img->heigth * 1.0) / (a * 2);
	if (a > 500)
		y = (a - 500) * grid_y;
	if (a >= 500)
		a = 500;
	start = (1000 - a * 2)/2;
	cub->width1 = (int)(img->width * (p.x / cub->size)) % img->width;
	while (start < 500 + a)
	{
		my_mlx_pixel_put1(cub->big_img, cub->width, start++, get_color(img,cub->width1,y));
		y += grid_y;
	}
}
void	draw_south_walls(t_info *cub, t_point p, int a)
{
	double	y;
	float	grid_y;
	int		start;
	t_img	*img;

	img = get_img(cub, 'S');
	if (cub->map[(int)(p.y / 100)][(int)(p.x / 100)] == 'D')
		img = cub->img_d;
	grid_y = (img->heigth * 1.0) / (a * 2);
	if (a > 500)
		y = (a - 500) * grid_y;
	if (a >= 500)
		a = 500;
	start = (1000 - a * 2)/2;
	cub->width1 = (int)(img->width * (p.x / cub->size)) % img->width;
	while (start < 500 + a)
	{
		my_mlx_pixel_put1(cub->big_img, cub->width, start++, get_color(img,cub->width1,y));
		y += grid_y;
	}
}

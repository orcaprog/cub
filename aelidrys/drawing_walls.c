/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 07:36:49 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/25 11:13:22 by aelidrys         ###   ########.fr       */
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
	t_img	*img_e;

	img_e = get_img(cub, 'E');
	grid_y = (img_e->heigth * 1.0)/(a * 2);
	if (a > 500)
		y = (a - 500) * grid_y;
	if (a >= 500)
		a = 500;
	start = (1000 - a * 2)/2;
	cub->width1 = (int)(img_e->width * (p.y / cub->size)) % img_e->width;
	while (start < 500 + a)
	{
		my_mlx_pixel_put(cub->big_img, cub->width, start++, get_color(img_e,cub->width1,y));
		y += grid_y;
	}
}

void	draw_west_walls(t_info *cub, t_point p, int a)
{
	double	y;
	float	grid_y;
	int		start;
	t_img	*img_w;

	img_w = get_img(cub, 'W');
	grid_y = (img_w->heigth * 1.0)/(a * 2);
	if (a > 500)
		y = (a - 500) * grid_y;
	if (a >= 500)
		a = 500;
	start = (1000 - a * 2)/2;
	cub->width1 = (int)(img_w->width * (p.y / cub->size)) % img_w->width;
	while (start < 500 + a)
	{
		my_mlx_pixel_put(cub->big_img, cub->width, start++, get_color(img_w,cub->width1,y));
		y += grid_y;
	}
}

void	draw_north_walls(t_info *cub, t_point p, int a)
{
	double	y;
	float	grid_y;
	int		start;
	t_img	*img_n;

	img_n = get_img(cub, 'N');
	grid_y = (img_n->heigth * 1.0) / (a * 2);
	if (a > 500)
		y = (a - 500) * grid_y;
	if (a >= 500)
		a = 500;
	start = (1000 - a * 2)/2;
	cub->width1 = (int)(img_n->width * (p.x / cub->size)) % img_n->width;
	while (start < 500 + a)
	{
		my_mlx_pixel_put(cub->big_img, cub->width, start++, get_color(img_n,cub->width1,y));
		y += grid_y;
	}
}
void	draw_south_walls(t_info *cub, t_point p, int a)
{
	double	y;
	float	grid_y;
	int		start;
	t_img	*img_s;

	img_s = get_img(cub, 'S');
	grid_y = (img_s->heigth * 1.0) / (a * 2);
	if (a > 500)
		y = (a - 500) * grid_y;
	if (a >= 500)
		a = 500;
	start = (1000 - a * 2)/2;
	cub->width1 = (int)(img_s->width * (p.x / cub->size)) % img_s->width;
	while (start < 500 + a)
	{
		my_mlx_pixel_put(cub->big_img, cub->width, start++, get_color(img_s,cub->width1,y));
		y += grid_y;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:29:23 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/15 17:08:54 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	draw_walls(t_info *cub, double cor_rad, t_point p)
{
	int	a;
	int	i;
	int start;

	i = 0;
	a = (cub->size / (p.r * fabs(cos(((cub->r_corner - cub->corner) * M_PI) / 180)))) * 500;
	if (sin(cor_rad) > 0 && cub->d == 0)
		draw_north_walls(cub, p, a);
	if (sin(cor_rad) < 0 && cub->d == 0)
		draw_south_walls(cub, p, a);
	if (cos(cor_rad) > 0 && cub->d == 1)
		draw_east_walls(cub, p, a);
	if (cos(cor_rad) < 0 && cub->d == 1)
		draw_west_walls(cub, p, a);
	if (a >= 500)
		a = 500;
	start = (1000 - a * 2) / 2;
	while (i <= start)
	{
		my_mlx_pixel_put1(cub->big_img, cub->width, i, cub->c);
		my_mlx_pixel_put1(cub->big_img, cub->width, 500 + a + i++, cub->f);
	}
}

int	draw_rays(t_info *cub, double corner)
{
	t_point	p;
	double	cor_rad;

	corner = cub->corner + 30;
	cub->r_corner = cub->corner - 30;
	cub->width = 0;
	while (corner >= cub->r_corner)
	{
		cor_rad = (M_PI * cub->r_corner) / 180.0;
		p = draw_ray(cub, cor_rad);
		draw_walls(cub,cor_rad, p);
		cub->r_corner += 0.05;
		cub->width++;
	}
	return (0);
}

t_point	draw_ray(t_info *cub, double cor_rad)
{
	t_point	px;
	t_point	py;

	det_direction(cub, cor_rad);
	px = det_coord_x(cub, cor_rad, 0, cub->size);
	py = det_coord_y(cub, cor_rad, 0, cub->size);
	if (py.r > px.r)
		cub->d = 0;
	if (px.r > py.r)
	{
		cub->d = 1;
		px = py;
	}
	return (px);
}



int	a_event(int key, t_info *cub)
{
	if (key == 49)
		cub->check_o_d = 1;
	input_key(key, cub);
	if ((int)cub->corner == 360)
		cub->corner = 0;
	if (key == 124)
		cub->corner+=10;
	if (key == 123)
		cub->corner-=10;
	if (key == 48)
		cub->check_shot = 1;
	if (key == 6)
	{
		if (cub->change_wap == 1)
			cub->change_wap = 0;
		else
			cub->change_wap++;
	}
	draw_simple_map(cub);
	return (0);
}


int	draw_simple_map(t_info *cub)
{
	draw_rays(cub, 0);
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->big_img->ptr, 0, 0);
	draw_mini_map(cub);
	change_wap(cub);
	mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->p_s,580, 480);
	if (!cub->check_shot && !cub->change_wap)
		mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->i_w0,400, 600);
	if (!cub->check_shot && cub->change_wap)
		mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->k_0,400, 600);
	draw_mini_map(cub);
	return (0);
}

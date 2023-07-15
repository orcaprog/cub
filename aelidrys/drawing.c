/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:29:23 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/15 16:22:20 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int	get_color(t_img *img, int x, int y)
{
	char	*dst;
	int color = 0;

	if (x < 0 || x >= img->width || y < 0 || y >= img->heigth)
		return 0;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(int*)dst;
	return (color);
}

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

void	check_open_door(t_info *cub, int key)
{
	float	cor_rad;
	t_point	px;
	t_point	py;
	int		d;

	d = 0;
	cor_rad = (M_PI * cub->corner) / 180.0;
	det_direction(cub, cor_rad);
	px = det_coord_x(cub, cor_rad, 0, cub->size);
	py = det_coord_y(cub, cor_rad, 0, cub->size);
	if (px.r < py.r)
		d = 1;
	if (px.r > py.r)
		px = py;
	if (px.r > 150 || key != 49)
		return ;
	cub->check_o_d = 1;
}

int	open_door(t_info *cub)
{
	float cor_rad;
	t_point	px;
	t_point	py;
	int		d;

	d = 0;
	cor_rad = (M_PI * cub->corner) / 180.0;
	det_direction(cub, cor_rad);
	px = det_coord_x(cub, cor_rad, 0, cub->size);
	py = det_coord_y(cub, cor_rad, 0, cub->size);
	if (px.r < py.r)
		d = 1;
	if (px.r > py.r)
		px = py;
	if (cub->check_o_d == 1)
		cub->open_d++;
	printf("%d\n",cub->open_d);
	if (d == 1 && sin(cor_rad) < 0 && cub->check_o_d == 1)//S
		if (cub->map[(int)(px.y / 100)][(int)(px.x / 100)] == 'D'){
			if (cub->open_d % 10 == 0){
				cub->img_d = cub->img_d->next;
				printf("enter\n");
			}
			// if (cub->open_d == 4000)
			// 	cub->map[(int)(px.y / 100)][(int)(px.x / 100)] = '0';
	}
	if (d == 1 && sin(cor_rad) > 0 && cub->check_o_d == 1)//N
		if (cub->map[(int)(px.y / 100) - 1][(int)(px.x / 100)] == 'D'){
			cub->map[(int)(px.y / 100) - 1][(int)(px.x / 100)] = '0';
	}
	if (d == 0 && cos(cor_rad) < 0 && cub->check_o_d == 1)//W
		if (cub->map[(int)(px.y / 100)][(int)(px.x / 100) - 1] == 'D'){
			cub->map[(int)(px.y / 100)][(int)(px.x / 100) - 1] = '0';
	}
	if (d == 0 && cos(cor_rad) > 0 && cub->check_o_d == 1)//E
		if (cub->map[(int)(px.y / 100)][(int)(px.x / 100)] == 'D'){
			cub->map[(int)(px.y / 100)][(int)(px.x / 100)] = '0';
	}
	if (cub->open_d == 30)
	{
		cub->open_d = 0;
		cub->check_o_d = 0;
	}
	return (0);
}

// int	a_event0(int key, t_info *cub){

// 	input_key(key, cub);
// 	return (0);
// }


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
	return (0);
}


int	draw_simple_map(t_info *cub)
{
	if (cub->check_o_d == 1)
		open_door(cub);
	draw_rays(cub, 0);
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->big_img->ptr, 0, 0);
	draw_mini_map(cub);
	return (0);
}

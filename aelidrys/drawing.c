/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:29:23 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/24 13:04:01 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int	get_color(t_img *data, int x, int y)
{
	char	*dst;
	int color = 0;

	if (x < 0 || x >= 100 || y < 0 || y >= 100)
		return 0;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(int*)dst;
	return (color);
}

void	draw_walls(t_info *cub, double cor_rad, t_point p)
{
	int	a;
	int	i;
	int start;

	i = 0;
	// heigth_of_win/2 = 500
	a = (100/(p.r * fabs(cos(((cub->r_corner-cub->corner) * M_PI) / 180)))) * 400;
	if (cub->d == 1)
		draw_vertical_walls(cub, p, cor_rad, a);
	if (cub->d == 0)
		draw_horizontal_walls(cub, p, cor_rad, a);
	if (a >= 500)
		a = 499;
	start = (1000 - a * 2)/2;
	while (i <= start)
	{
		my_mlx_pixel_put(&cub->img[0], cub->width, i, 2463422);
		my_mlx_pixel_put(&cub->img[0], cub->width, 500 + a + i++, 8011295);
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
		cor_rad = (M_PI * cub->r_corner) / 180.0000;
		p = draw_ray(cub, cor_rad);
		draw_walls(cub,cor_rad, p);
		cub->r_corner += 0.05;
		cub->width++;
	}
	return (0);
}

t_point	draw_ray(t_info *cub, double cor_rad)
{
	t_point	p1;
	t_point	p2;
	int k[2];

	det_direction(cub, cor_rad);
	p1 = det_coord_x(cub, cor_rad,k);
	p2 = det_coord_y(cub, cor_rad,k);
	if (p2.r > p1.r)
		cub->d = 0;
	if (p1.r > p2.r)
	{
		cub->d = 1;
		p1 = p2;
	}
	return (p1);
	// rf = p1.r;
	// x = cub->x + 5 * cos(cor_rd);
	// y = cub->y - 5 * sin(cor_rd);
	// while (ri < rf)
	// {
	// 	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, x, y, color);
	// 	x += cos(cor_rd);
	// 	y -= sin(cor_rd);
	// 	ri = sqrt(pow(floor(cub->x - x),2) + pow(floor(cub->y - y),2));
	// }
	//2463422 blue
	//8403230 maron
	//14605267 gree
}

int	a_event(int key, t_info *cub)
{
	input_key(key, cub);
	draw_simple_map(cub);
	if ((int)cub->corner == 360)
		cub->corner = 0;
	if (key == 124)
	{
		cub->corner+=10;
		draw_simple_map(cub);
	}
	if (key == 123)
	{
		cub->corner-=10;
		draw_simple_map(cub);
	}
	return (0);
}


void	draw_simple_map(t_info *cub)
{
	int x = 0;
	int y = 0;
	// t_img	img1;

	y = 0;
	while (cub->map[y] && y < 6)
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '1')
				mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win,
					cub->mlx->img_b, x * 100, y * 100);
			if (cub->map[y][x] != '1')
				mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win,
					cub->mlx->img_n, x * 100, y * 100);
			x++;
		}
		y++;
	}
	draw_rays(cub, 0);
	// put_pix(cub,&cub->img[1],14753280);
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img[0].img, 0, 0);
	// mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img[1].img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 07:36:49 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/24 11:07:06 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_color1(t_img *data, int x, int y)
{
	char	*dst;
	int color = 0;

	if (x < 0 || x >= 720 || y < 0 || y >= 776)
		return 0;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(int*)dst;
	return (color);
}

void	draw_vertical_walls(t_info *cub, t_point p, double cor_rad, int a)
{
	double	y;
	float	grid_y;
	int		start;

	grid_y = 50.0/a;
	if (a > 500)
		y = (a - 500) * grid_y;
	if (a >= 500)
		a = 499;
	start = (1000 - a * 2)/2;
	cub->width1 = ((int)p.y % 100);
	while (cos(cor_rad) > 0 && start < 500 + a)
	{
		my_mlx_pixel_put(&cub->img[0], cub->width, start++, get_color(&cub->img[4],cub->width1,y));
		y += grid_y;
	}
	while (cos(cor_rad) < 0 && start < 500 + a)
	{
		my_mlx_pixel_put(&cub->img[0], cub->width, start++, get_color(&cub->img[2],cub->width1,y));
		y += grid_y;
	}
}

void	draw_horizontal_walls(t_info *cub, t_point p, double cor_rad, int a)
{
	double	y;
	float	grid_y;
	int		start;

	a = (100/(p.r * fabs(cos(((cub->r_corner-cub->corner) * M_PI) / 180)))) * 400;
	grid_y = 776.0/(a*2);
	if (a > 500)
		y = (a - 500) * grid_y;
	if (a >= 500)
		a = 499;
	start = (1000 - a * 2)/2;
	cub->width1 = (int)(720 * (p.x / 100)) % 720;
	// printf("width = %lf\n", grid_y);
	while (sin(cor_rad) > 0 && start < 500 + a)
	{
		my_mlx_pixel_put(&cub->img[0], cub->width, start++, get_color1(&cub->img[3],cub->width1,y));
		y += grid_y;
	}
	while (sin(cor_rad) < 0 && start < 500 + a)
	{
		my_mlx_pixel_put(&cub->img[0], cub->width, start++, 10723998);
		y += grid_y;
	}
}

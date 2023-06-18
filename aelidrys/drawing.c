/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:29:23 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/18 11:05:48 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_rays(t_info *cub, double cor_rd, int color)
{
	(void)color;
	cor_rd = cub->corner + 30;
	cub->corner -= 30;
	// printf("first = %lf last = %lf\n",cub->corner,cor_rd);
	while (cor_rd >= cub->corner)
	{
		draw_ray(cub, 0, 0, color);
		cub->corner += 0.2;
	}
	// printf("first = %lf\n",cub->corner);
	cub->corner = cor_rd - 30;
	return (0);
}

void	draw_ray(t_info *cub, int ri, int rf, int color)
{
	double	x;
	double	y;
	double	cor_rd;
	t_point	p1;
	t_point	p2;

	ri = 0;
	cor_rd = (M_PI * cub->corner)/180.0000;
	det_direction(cub, cor_rd);
	p1 = det_coord_y(cub, cor_rd,0,0);
	p2 = det_coord_x(cub, cor_rd,0,0);
	if (p1.r > p2.r)
		p1.r = p2.r;
	rf = p1.r;
	x = cub->x + 5 * cos(cor_rd);
	y = cub->y - 5 * sin(cor_rd);
	// printf("----p1(%lf,%lf]) ----\n",p1.x,p1.y);
	// printf("\n----p2(%lf,%lf]) ----\n",p2.x,p2.y);
	// printf("$$$$p.r = %lf && RF = %d$$$$\n++++++++++++++\n",p1.r,rf);
	while (ri < rf)
	{
		mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, x, y, color);
		x += cos(cor_rd);
		y -= sin(cor_rd);
		ri = sqrt(pow(floor(cub->x - x),2) + pow(floor(cub->y - y),2));
		if (ri < 0)
			ri *=-1;
	}
}

int	a_event(int key, t_info *cub)
{
	draw_rays(cub, 0, 0);
	input_key(key, cub);
	draw_rays(cub, 0, 16777215);
	if (key == 124)
	{
		draw_rays(cub, 0, 0);
		cub->corner-=4;
		draw_rays(cub, 0, 16777215);
	}
	if (key == 123)
	{
		draw_rays(cub, 0, 0);
		cub->corner+=4;
		draw_rays(cub, 1, 16777215);
	}
	return (0);
}

void	draw_simple_map(t_info *cub)
{
	int x = 0;
	int y = 0;

	cub->corner = 180;
	cub->mlx->ptr = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->ptr, 1000, 700, "CUB");
	cub->mlx->img_b = mlx_xpm_file_to_image(cub->mlx->ptr, cub->no, &x, &y);
	if (!cub->mlx->img_b)
		ft_error();
	y = 0;
	while (cub->map[y])
	{
		// printf("map = %s\n", cub->map[y]);
		x = 0;
		while (cub->map[y][x]){
			if (cub->map[y][x] == '1')
				mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win,
					cub->mlx->img_b, x * 100, y * 100);
			x++;
		}
		y++;
	}
	draw_rays(cub, 0, 16777215);
}

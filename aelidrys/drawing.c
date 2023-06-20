/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:29:23 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/20 18:58:28 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_rays(t_info *cub, double cor_rd, int color)
{
	(void)color;
	cor_rd = cub->corner + 30;
	cub->r_corner = cub->corner - 30;
	cub->width = 0;
	while (cor_rd >= cub->r_corner)
	{
		draw_ray(cub, 0, 0, color);
		cub->r_corner += 0.06;
		cub->width++ ;
	}
	return (0);
}

void	draw_ray(t_info *cub, int ri, int rf, int color)
{
	double	x;
	double	y;
	double	cor_rd;
	t_point	p1;
	t_point	p2;
	int d = 0;
	int k[2];

	ri = 0;
	(void)color;
	cor_rd = (M_PI * cub->r_corner)/180.0000;
	det_direction(cub, cor_rd);
	p1 = det_coord_x(cub, cor_rd,k);
	p2 = det_coord_y(cub, cor_rd,k);
	// printf("r1 = %lf  r2 = %lf\n",p1.r,p2.r);
	if (p1.r > p2.r){
		d = 1;
		p1.r = p2.r;
	}
	else if ((int)p1.r == (int)p2.r){
		p1.r = cub->last_r;
	}
	cub->last_r = p1.r;
	rf = p1.r;
	x = cub->x + 5 * cos(cor_rd);
	y = cub->y - 5 * sin(cor_rd);
	// printf("----p1(%lf,%lf]) ----\n",p1.x,p1.y);
	// printf("\n----p2(%lf,%lf]) ----\n",p2.x,p2.y);
	// printf("$$$$p.r = %lf && RF = %d$$$$\n++++++++++++++\n",p1.r,rf);
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
	y=250;
	double a = (500/(p1.r*fabs(cos(((cub->r_corner-cub->corner)*M_PI)/180))))*50;
	if (a > 250)
		a = 250;
	for (int i = 0;i<y-a;i++){
		my_mlx_pixel_put(&cub->img[0], cub->width, y-a-i, 2463422);
		my_mlx_pixel_put(&cub->img[0], cub->width, y+a+i, 8011295);
	}
	if (sin(cor_rd)>0 && d == 0){
		for (int i = 0;i<a;i++){
			my_mlx_pixel_put(&cub->img[0], cub->width, y+i, 14605267);
			my_mlx_pixel_put(&cub->img[0], cub->width, y-i, 14605267);
		}
	}
	else if (sin(cor_rd)<0 && d == 0){
		for (int i = 0;i<a;i++){
			my_mlx_pixel_put(&cub->img[0], cub->width, y+i, 14605267);
			my_mlx_pixel_put(&cub->img[0], cub->width, y-i, 14605267);
		}
	}
	else if (cos(cor_rd)>0 && d == 1){
		for (int i = 0;i<a;i++){
			my_mlx_pixel_put(&cub->img[0], cub->width, y+i, 10723998);
			my_mlx_pixel_put(&cub->img[0], cub->width, y-i, 10723998);
		}
	}
	else{
		for (int i = 0;i<a;i++){
			my_mlx_pixel_put(&cub->img[0], cub->width, y+i, 10723998);
			my_mlx_pixel_put(&cub->img[0], cub->width, y-i, 10723998);
		}
	}
}

int	a_event(int key, t_info *cub)
{
	input_key(key, cub);
	// mlx_clear_window(cub->mlx->ptr, cub->mlx->win);
	draw_simple_map(cub);
	if ((int)cub->corner == 360)
		cub->corner = 0;
	if (key == 124)
	{
		cub->corner+=10;
		// mlx_clear_window(cub->mlx->ptr, cub->mlx->win);
		draw_simple_map(cub);
	}
	if (key == 123)
	{
		cub->corner-=10;
		// mlx_clear_window(cub->mlx->ptr, cub->mlx->win);
		draw_simple_map(cub);
	}
	return (0);
}

void	draw_simple_map(t_info *cub)
{
	int x = 0;
	int y = 0;

	y = 0;
	while (cub->map[y] && y < 5)
	{
		x = 0;
		while (cub->map[y][x]){
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
	draw_rays(cub, 0, 16777215);
	// put_pix(cub,&cub->img[1],14753280);
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img[0].img, 0, 500);
	// mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img[1].img, 0, 0);
}

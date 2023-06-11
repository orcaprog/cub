/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:29:23 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/11 16:21:38 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ray(t_info *cub, int o, int color)
{
	double	x;
	double	y;
	double	res;
	double	res0;

	res0 = (3.14159265359 * (cub->corner+o))/180.0000;
	res = (3.14159265359 * cub->corner)/180.0000;
	printf("res0 = cos(%lf) = %lf\n", cub->corner-1,cos(res0));
	printf("res = cos(%lf) = %lf\n", cub->corner,cos(res));
	x = cub->x - 5 * cos(res0);
	y = cub->y - 5 * sin(res0);
	for (int i = 0; i < 50; i++){
		mlx_pixel_put(cub->mlx->ptr,cub->mlx->win,x,y,0);
		x -= cos(res0);
		y -= sin(res0);
	}
	x = cub->x - 5 * cos(res);
	y = cub->y - 5 * sin(res);
	for (int i = 0; i < 50; i++){
		mlx_pixel_put(cub->mlx->ptr,cub->mlx->win,x,y,color);
		x -= cos(res);
		y -= sin(res);
	}
}

int	a_event(int key, t_info *cub)
{
	input_key(key, cub);
	draw_ray(cub, 0, 16777215);
	if (key == 124)
	{
		cub->corner++;
		draw_ray(cub, -1, 16777215);
	}
	if (key == 123)
	{
		cub->corner--;
		draw_ray(cub, 1, 16777215);
	}
	return (0);
}

void	draw_simple_map(t_info *cub)
{
	int a = 0;
	int b = 0;

	cub->corner = 90;
	cub->mlx->ptr = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->ptr,1000,700,"CUB");
	cub->mlx->img_b = mlx_xpm_file_to_image(cub->mlx->ptr,cub->no,&a,&b);
	if (!cub->mlx->img_b)
		ft_error();
	b = 0;
	while (b < 700)
	{
		a = 0;
		while (a < 1000){
			if (b  == 0)
				mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->img_b,a,b);
			else if (b == 300){
				if (a != 400 && a != 500)
					mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->img_b,a,b);
			}
			else if (b == 600)
				mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->img_b,a,b);
			else{
				mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->img_b,0,b);
				mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->img_b,900,b);
				break;
			}
			a += 100;
		}
		b += 100;
	}
	draw_ray(cub,0, 16777215);
}

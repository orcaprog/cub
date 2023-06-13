/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:29:23 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/13 13:07:29 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ray(t_info *cub, int o, int color)
{
	double	x;
	double	y;
	double	cor_rd;

	(void)o;
	cor_rd = (3.14159265359 * cub->corner)/180.0000;
	if (color){
		printf("tan(%lf) = %lf\n",cub->corner,tan(cor_rd));
		printf("cos(%lf) = %lf\n", cub->corner,cos(cor_rd));
		printf("sin(%lf) = %lf\n----------\n", cub->corner,sin(cor_rd));
	}
	x = cub->x + 5 * cos(cor_rd);
	y = cub->y - 5 * sin(cor_rd);
	for (int i = 0; i < 50; i++){
		mlx_pixel_put(cub->mlx->ptr,cub->mlx->win,x,y,color);
		x += cos(cor_rd);
		y -= sin(cor_rd);
	}
}

int	a_event(int key, t_info *cub)
{
	draw_ray(cub, 0, 0);
	input_key(key, cub);
	draw_ray(cub, 0, 16777215);
	if (key == 124)
	{
		draw_ray(cub, 0, 0);
		cub->corner--;
		draw_ray(cub, 0, 16777215);
	}
	if (key == 123)
	{
		draw_ray(cub, 0, 0);
		cub->corner++;
		draw_ray(cub, 1, 16777215);
	}
	return (0);
}

void	draw_simple_map(t_info *cub)
{
	int x = 0;
	int y = 0;

	cub->corner = 90;
	cub->mlx->ptr = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->ptr,1000,700,"CUB");
	cub->mlx->img_b = mlx_xpm_file_to_image(cub->mlx->ptr,cub->no,&x,&y);
	if (!cub->mlx->img_b)
		ft_error();
	y = 0;
	while (cub->map[y])
	{
		printf("map = %s\n", cub->map[y]);
		x = 0;
		while (cub->map[y][x]){
			if (cub->map[y][x] == '1')
				mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->img_b,x*100,y*100);
			x++;
		}
		y++;
	}
	draw_ray(cub,0, 16777215);
}

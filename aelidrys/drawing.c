/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:29:23 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/10 13:57:14 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_exit(void)
{
	write(1,"YOU ARE EXIT FROM CUB\n",22);
	exit(0);
}

void	draw_simple_map(t_info *cub)
{
	cub->mlx = malloc(sizeof(t_mlx));
	cub->mlx->ptr = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->ptr,1000,700,"CUB");
	int a = 0;
	while (a <= 700){
		for (int i = 0; i <= 1000; i++)
			mlx_pixel_put(cub->mlx->ptr,cub->mlx->win,i,a,16777215);
		a += 100;
	}
	a = 0;
	while (a <= 1000){
		for (int i = 0; i <= 700; i++)
			mlx_pixel_put(cub->mlx->ptr,cub->mlx->win,a,i,16777215);
		a += 100;
	}
	int b = 0;
	cub->mlx->img_b = mlx_xpm_file_to_image(cub->mlx->ptr,cub->no,&a,&b);
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
	mlx_hook(cub->mlx->win, 17, 0, ft_exit, NULL);
	mlx_loop(cub->mlx->ptr);
}
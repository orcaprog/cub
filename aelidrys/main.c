/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:26:03 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/15 12:36:03 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int	ft_exit(void)
{
	write(1,"YOU ARE EXIT FROM CUB\n",22);
	exit(0);
}

void	my_mlx_pixel_put1(t_img *data, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || x >= 1200 || y < 0 || y >= 1000)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int ac, char **av)
{
	(void)ac;
	t_info	*cub;

	cub = malloc(sizeof(t_info));
	start_cub(cub, av);
	// draw_simple_map(cub);
	mlx_hook(cub->mlx->win, 17, 0, ft_exit, NULL);
	mlx_hook(cub->mlx->win,2,0,a_event,cub);
	// mlx_hook(cub->mlx->win,2,0,a_event0,cub);
	mlx_hook(cub->mlx->win,6,0,mouse_view,cub);
	// mlx_loop_hook(cub->mlx->ptr,open_door,cub);
	mlx_loop_hook(cub->mlx->ptr,draw_simple_map,cub);
	// mlx_hook(cub->mlx->win,2,0,input_key,cub);
	mlx_loop(cub->mlx->ptr);
}
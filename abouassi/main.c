/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:54:43 by abouassi          #+#    #+#             */
/*   Updated: 2023/07/15 16:20:47 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



int	a_event1(int key, t_info *cub)
{
	input_key(key, cub);
	draw_simple_map(cub);
	if ((int)cub->corner == 360)
		cub->corner = 0;
	if (key == 124)
	{
		cub->corner += 10;
		draw_simple_map(cub);
	}
	if (key == 123)
	{
		cub->corner -= 10;
		draw_simple_map(cub);
	}
	if (key == 48)
		cub->check_shot = 1;
	if (key == 6)
	{
		if (cub->change_wap == 1)
			cub->change_wap = 0;
		else
			cub->change_wap++;
	}
	return (0);
}

// void	draw_simple_map(t_info *cub)
// {
// 	int x = 0;
// 	int y = 0;

// 	y = 0;
// 	x = 0;
// 	// while (cub->map[y] && y < 6)
// 	// {
// 	// 	x = 0;
// 	// 	while (cub->map[y][x])
// 	// 	{
// 	// 		if (cub->map[y][x] == '1')
// 	// 			mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win,
// 	// 				cub->mlx->img_b, x * 100, y * 100);
// 	// 		if (cub->map[y][x] != '1')
// 	// 			mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win,
// 	// 				cub->mlx->img_n, x * 100, y * 100);
// 	// 		x++;
// 	// 	}
// 	// 	y++;
// 	// }
// 	draw_rays(cub, 0);
// 	// put_pix(cub,&cub->img[1],14753280);
// 	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->big_img->ptr, 0, 0);
// 	change_wap(cub);
// 	mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->p_s,580, 480);
// 	if (!cub->check_shot && !cub->change_wap)
// 	{
		
// 		mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->i_w0,400, 600);
// 	}
// 	if (!cub->check_shot && cub->change_wap)
// 	{
		
// 		mlx_put_image_to_window(cub->mlx->ptr,cub->mlx->win,cub->mlx->k_0,400, 600);
// 	}
// 	draw_mini_map(cub);
// 	// void *img = mlx_new_image(cub->mlx->ptr, 300, 210);
// 	// mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, img, 0, 0);
// }

int	main(int ac, char **av)
{
	(void)ac;

	t_info	*cub;
	cub = malloc(sizeof(t_info));
	start_cub(cub, av);
	cub->check_shot = 0;
	cub->numb_shot = 0;
	cub->change_wap = 0;
	get_xpm_file(cub);
	draw_simple_map(cub);
	mlx_loop_hook(cub->mlx->ptr,&draw_wapeans,cub);
	mlx_hook(cub->mlx->win,2,0,a_event1,cub);
	mlx_hook(cub->mlx->win,6,0,mouse_view,cub);
	mlx_loop(cub->mlx->ptr);
}

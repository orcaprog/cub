/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:54:43 by abouassi          #+#    #+#             */
/*   Updated: 2023/07/13 10:25:46 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



// int mapdraw(t_info *cub)
// {
	
// 	//draw_mini_map(cub);
// 	return 0;
// }
int main(int ac , char **av)
{
	(void)ac;
	// char **map;
	t_info *cub;

	//30   -->    x
	//100 --->  750
	
	cub = malloc(sizeof(t_info));
	
	// cub->mlx = malloc(sizeof(t_mlx));
	// cub->big_img = malloc(sizeof(t_img) );
	// cub->no = malloc(sizeof(t_pos));
	// cub->so = malloc(sizeof(t_pos));
	// cub->ea = malloc(sizeof(t_pos));
	// cub->we = malloc(sizeof(t_pos));
	// int i;
	// i = 0;
	// check_name_map(av[1]);
	// map = get_map(av[1]);
	// check_first_element(map);
	// cheak_map(&map[6]);
	// check_cmp(&map[6]);
	// check_cmp_valid(&map[6]);
	// cub->map = &map[6];
	// cub->mlx->ptr = mlx_init();
	// cub->mlx->win = mlx_new_window(cub->mlx->ptr, 1000, 1000, "CUB");
	// store_info(map, cub); // <-------------------------------------------------hadi fin kan3amer no so ea we
	// t_img *tmp;
	// tmp = cub->img;
	// while (tmp)
	// {
	// 	printf("width   ->%d\n hiedth   ->%d\n",tmp->width,tmp->heigth);
	// 	tmp =tmp->next;
	// }
	
	// cub->size = 100;
	// printf("------x%f\n",get_position(&map[6]).x);
	// printf("------y%f\n",get_position(&map[6]).y);
	// cub->x = get_position(&map[6]).x * 100 + 50;
	// cub->y = get_position(&map[6]).y * 100 + 50;
	// // cub->mini_x = cub->x * MINI_GRID/cub->size;
	// // cub->mini_y = cub->y * MINI_GRID/cub->size;
	// cub->move_x = 165;
	// cub->move_y = 105;
	// cub->corner = 180;
	// // if (!cub->mlx->img_b || !cub->mlx->img_n)
	// // 	ft_error();
	// // cub->img[0].ptr = mlx_new_image(cub->mlx->ptr, 1000,500);
	// cub->big_img->ptr = mlx_new_image(cub->mlx->ptr, 350,210);
	// // cub->img[0].addr = mlx_get_data_addr(cub->img[0].ptr, &cub->img[0].bits_per_pixel,&cub->img[0].line_length, &cub->img[0].endian);
	// cub->big_img->addr = mlx_get_data_addr(cub->big_img->ptr, &cub->big_img->bits_per_pixel,&cub->big_img->line_length, &cub->big_img->endian);
	start_cub(cub, av);
	point_of_view(cub);
	draw_mini_map(cub);
	//mlx_hook(cub->mlx->win, 17, 0, ft_exit, NULL);
	//mlx_loop_hook(cub->mlx->ptr,mapdraw,cub);
	mlx_hook(cub->mlx->win,2,0,a_event1,cub);
	
	 mlx_loop(cub->mlx->ptr);
}
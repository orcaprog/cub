/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:54:43 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/22 17:17:29 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



// int mapdraw(t_info *cub)
// {
	
// 	draw_simple_map1(cub);
// 	put_pix(cub,14753280);
// 	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img->img, 0,0);
// 	return 0;
// }
int main(int ac , char **av)
{
	(void)ac;
	char **map;
	t_info *cub;
	cub = malloc(sizeof(t_info));
	cub->mlx = malloc(sizeof(t_mlx));
	cub->img = malloc(sizeof(t_data) * 2);
	cub->no = malloc(sizeof(t_pos));
	cub->so = malloc(sizeof(t_pos));
	cub->ea = malloc(sizeof(t_pos));
	cub->we = malloc(sizeof(t_pos));
	int i;
	i = 0;
	map = get_map(av[1]);
	check_first_element(map);
	cheak_map(&map[6]);
	check_cmp(&map[6]);
	check_cmp_valid(&map[6]);
	cub->map = &map[6];
	cub->mlx->ptr = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->ptr, 1000, 1000, "CUB");
	store_info(map, cub);
	printf("no  x%d   y%d\n",cub->no->x,cub->no->y);
	printf("so  x%d   y%d\n",cub->so->x,cub->so->y);
	printf("ea  x%d   y%d\n",cub->ea->x,cub->ea->y);
	printf("we  x%d   y%d\n",cub->we->x,cub->we->y);
	point_of_view(cub);
	cub->corner = 180;
	cub->x = 750;
	cub->y = 250;
	cub->corner = 180;
	if (!cub->mlx->img_b || !cub->mlx->img_n)
		ft_error();
	cub->img[0].img = mlx_new_image(cub->mlx->ptr, 1000,500);
	cub->img[1].img = mlx_new_image(cub->mlx->ptr, 1000,500);
	cub->img[0].addr = mlx_get_data_addr(cub->img[0].img, &cub->img[0].bits_per_pixel,&cub->img[0].line_length, &cub->img[0].endian);
	cub->img[1].addr = mlx_get_data_addr(cub->img[1].img, &cub->img[1].bits_per_pixel,&cub->img[1].line_length, &cub->img[1].endian);
	draw_simple_map(cub);
	//lx_hook(cub->mlx->win, 17, 0, ft_exit, NULL);
	mlx_hook(cub->mlx->win,2,0,a_event,cub);
	
	 mlx_loop(cub->mlx->ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:54:43 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/20 13:16:08 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



int mapdraw(t_info *cub)
{
	
	draw_simple_map1(cub);
	put_pix(cub,14753280);
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img->img, 0,0);
	return 0;
}
int main(int ac , char **av)
{
	(void)ac;
	char **map;
	t_info *cub;
	cub = malloc(sizeof(t_info));
	cub->mlx = malloc(sizeof(t_mlx));
	cub->img = malloc(sizeof(t_data) * 2);
	int i;
	
	cub->x = 450;
	cub->y = 250;
	i = 0;
	map = get_map(av[1]);
	check_first_element(map);
	cheak_map(&map[6]);
	check_cmp(&map[6]);
	check_cmp_valid(&map[6]);
	cub->map = &map[6];
	store_info(map, cub);
	point_of_view(cub);
	cub->corner = 180;
	cub->mlx->ptr = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->ptr, 1000, 1000, "CUB");
	cub->mlx->img_b = mlx_xpm_file_to_image(cub->mlx->ptr, cub->no, &ac, &ac);
	cub->mlx->img_n = mlx_xpm_file_to_image(cub->mlx->ptr, cub->so, &ac, &ac);

	// cub->img[0].img = mlx_new_image(cub->mlx->ptr, 1000,500);
	// cub->img[1].img = mlx_new_image(cub->mlx->ptr, 1000,500);
	// cub->img[0].addr = mlx_get_data_addr(cub->img[0].img, &cub->img[0].bits_per_pixel,&cub->img[0].line_length, &cub->img[0].endian);
	// cub->img[1].addr = mlx_get_data_addr(cub->img[1].img, &cub->img[1].bits_per_pixel,&cub->img[1].line_length, &cub->img[1].endian);

	if (!cub->mlx->img_b || !cub->mlx->img_n){	
		ft_error();
	}
	draw_simple_map(cub);
	put_pix(cub,14753280);
	mlx_hook(cub->mlx->win, 2, 0,a_event, cub);
	//mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img->img, 0,0);
	
	mlx_loop(cub->mlx->ptr);
}
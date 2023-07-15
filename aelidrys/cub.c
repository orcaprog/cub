/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:22:27 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/14 10:59:30 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_cub(t_info *cub, char **av)
{
	check_name_map(av[1]);
	cub->mlx = malloc(sizeof(t_mlx));
	cub->big_img = malloc(sizeof(t_img));
	cub->mini_img = malloc(sizeof(t_img));
	cub->img = NULL;
	cub->map0 = get_map(av[1]);
	check_first_element(cub->map0);
	cub->map = cub->map0+6;
	cheak_map(cub->map);
	check_cmp(cub->map);
	check_cmp_valid(cub->map);
	cub->mlx->ptr = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->ptr, 1200, 1000, "CUB");
	cub->img_d = new_img(cub, "D1.xpm", 'D');
	store_info(cub->map0, cub);
	cub->x = get_position(cub->map).x * 100 + 50;
	cub->y = get_position(cub->map).y * 100 + 50;
	cub->size = 100;
	cub->corner = 0;
	cub->mini_img->ptr = mlx_new_image(cub->mlx->ptr, 350,210);
	cub->mini_img->addr = mlx_get_data_addr(cub->mini_img->ptr, &cub->mini_img->bits_per_pixel,
		&cub->mini_img->line_length, &cub->mini_img->endian);
	cub->big_img->ptr = mlx_new_image(cub->mlx->ptr, 1200,1000);
	cub->big_img->addr = mlx_get_data_addr(cub->big_img->ptr, &cub->big_img->bits_per_pixel,
		&cub->big_img->line_length, &cub->big_img->endian);
}
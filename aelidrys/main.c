/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:26:03 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/13 09:19:02 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_exit(void)
{
	write(1,"YOU ARE EXIT FROM CUB\n",22);
	exit(0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || x >= 1200 || y < 0 || y >= 1000)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

int main(int ac, char **av)
{
	(void)ac;
	t_info	*cub;

	cub = malloc(sizeof(t_info));
	start_cub(cub, av);
	draw_simple_map(cub);
	mlx_hook(cub->mlx->win, 17, 0, ft_exit, NULL);
	mlx_hook(cub->mlx->win,2,0,a_event,cub);
	mlx_hook(cub->mlx->win,6,0,mouse_view,cub);
	// mlx_hook(cub->mlx->win,2,0,input_key,cub);
	mlx_loop(cub->mlx->ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:26:03 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/24 11:07:06 by aelidrys         ###   ########.fr       */
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
	//printf("(%d,%d)\n",x,y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_info	*cub = malloc(sizeof(t_info));
	cub->mlx = malloc(sizeof(t_mlx));
	cub->img = malloc(sizeof(t_img) * 5);
	// cub->no = malloc(sizeof(t_pos));
	// cub->so = malloc(sizeof(t_pos));
	// cub->ea = malloc(sizeof(t_pos));
	// cub->we = malloc(sizeof(t_pos));
	cub->map0 = get_map(av[1]);
	check_first_element(cub->map0);
	cub->map = cub->map0+6;
	check_cmp(cub->map);
	cub->x = 750;
	cub->y = 150;
	cub->corner = 0;
	cub->mlx->ptr = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->ptr, 1200, 1000, "CUB");
	cub->mlx->img_b = mlx_xpm_file_to_image(cub->mlx->ptr, "box.xpm", &ac, &ac);
	cub->mlx->img_n = mlx_xpm_file_to_image(cub->mlx->ptr, "bkgrnd.xpm", &ac, &ac);
	cub->img[2].img = mlx_xpm_file_to_image(cub->mlx->ptr, "W1.xpm", &ac, &ac);
	cub->img[3].img = mlx_xpm_file_to_image(cub->mlx->ptr, "W5.xpm", &ac, &ac);
	cub->img[4].img = mlx_xpm_file_to_image(cub->mlx->ptr, "W3.xpm", &ac, &ac);
	if (!cub->mlx->img_b || !cub->mlx->img_n)
		ft_error();
	cub->img[0].img = mlx_new_image(cub->mlx->ptr, 1200,1000);
	cub->img[1].img = mlx_new_image(cub->mlx->ptr, 1200,1000);
	cub->img[2].addr =  mlx_get_img_addr(cub->img[2].img, &cub->img[2].bits_per_pixel,
		&cub->img[2].line_length, &cub->img[2].endian);
	cub->img[3].addr =  mlx_get_img_addr(cub->img[3].img, &cub->img[3].bits_per_pixel,
		&cub->img[3].line_length, &cub->img[3].endian);
	cub->img[4].addr =  mlx_get_img_addr(cub->img[4].img, &cub->img[4].bits_per_pixel,
		&cub->img[4].line_length, &cub->img[4].endian);
	cub->img[0].addr = mlx_get_img_addr(cub->img[0].img, &cub->img[0].bits_per_pixel,&cub->img[0].line_length, &cub->img[0].endian);
	cub->img[1].addr = mlx_get_img_addr(cub->img[1].img, &cub->img[1].bits_per_pixel,&cub->img[1].line_length, &cub->img[1].endian);
	draw_simple_map(cub);
	mlx_hook(cub->mlx->win, 17, 0, ft_exit, NULL);
	mlx_hook(cub->mlx->win,2,0,a_event,cub);
	// mlx_hook(cub->mlx->win,2,0,input_key,cub);
	mlx_loop(cub->mlx->ptr);
}
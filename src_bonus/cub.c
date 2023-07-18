/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:22:27 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/18 15:01:58 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_var(t_info *cub)
{
	cub->corner = 0;
	cub->m_r = 0;
	cub->m_l = 0;
	cub->m_d = 0;
	cub->m_u = 0;
	cub->l_cor = 0;
	cub->r_cor = 0;
	cub->open_d = 0;
	cub->size = 100;
	cub->check_o_d = 0;
	cub->x = get_position(cub->map).x * 100 + 50;
	cub->y = get_position(cub->map).y * 100 + 50;
	cub->img_d = malloc(7 * sizeof(t_img *));
	cub->img_d[0] = new_img(cub, "door/d1.xpm", 'D');
	cub->img_d[1] = new_img(cub, "door/d2.xpm", 'D');
	cub->img_d[2] = new_img(cub, "door/d3.xpm", 'D');
	cub->img_d[3] = new_img(cub, "door/d4.xpm", 'D');
	cub->img_d[4] = new_img(cub, "door/d5.xpm", 'D');
	cub->img_d[5] = new_img(cub, "door/d6.xpm", 'D');
	cub->img_d[6] = new_img(cub, "door/d7.xpm", 'D');
}

int	get_color(t_img *img, int x, int y)
{
	char	*dst;
	int		color;

	if (x < 0 || x >= img->width || y < 0 || y >= img->heigth)
		return (0);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(int *)dst;
	return (color);
}

int	is_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
		if (c == str[i++])
			return (1);
	return (0);
}

int	prm_moves1(char **map, char *str, int x, int y)
{
	if (is_in_str(str, map[y][x]))
		return (1);
	return (0);
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
	cub->map = cub->map0 + 6;
	cheak_map(cub->map);
	check_cmp(cub->map);
	check_cmp_valid(cub->map);
	cub->mlx->ptr = mlx_init();
	cub->mlx->win = mlx_new_window(cub->mlx->ptr, 1200, 1000, "CUB");
	ft_init_var(cub);
	store_info(cub->map0, cub);
	cub->mini_img->ptr = mlx_new_image(cub->mlx->ptr, 350, 210);
	cub->mini_img->addr = mlx_get_data_addr(cub->mini_img->ptr,
			&cub->mini_img->bits_per_pixel,
			&cub->mini_img->line_length, &cub->mini_img->endian);
	cub->big_img->ptr = mlx_new_image(cub->mlx->ptr, 1200, 1000);
	cub->big_img->addr = mlx_get_data_addr(cub->big_img->ptr,
			&cub->big_img->bits_per_pixel,
			&cub->big_img->line_length, &cub->big_img->endian);
}

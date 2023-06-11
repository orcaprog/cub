/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:54:43 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/11 11:09:41 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
int	input_key(int key, t_info *data)
{

	if (key == 124)
	{
		move_right(data);
	}
	if (key == 123)
	{
		move_left(data);
	}
	if (key == 125)
	{
		move_down(data);
	}
	if (key == 126)
	{
		move_up(data);
	}
	
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}
int main(int ac , char **av)
{
	(void)ac;
	char **map;
	t_info *cub;
	cub = malloc(sizeof(t_info));
	cub->mlx = malloc(sizeof(t_mlx));
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
	draw_simple_map(cub);
	put_pix(cub,14753280);
	mlx_hook(cub->mlx->win, 2, 0, input_key, cub);
	mlx_loop(cub->mlx->ptr);
}
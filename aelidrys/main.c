/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:26:03 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/12 06:59:31 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_exit(void)
{
	write(1,"YOU ARE EXIT FROM CUB\n",22);
	exit(0);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_info	*cub = malloc(sizeof(t_info));
	cub->mlx = malloc(sizeof(t_mlx));
	cub->no = "box.xpm";
	cub->map = get_map(av[1]);
	// check_first_element(cub->map);
	check_cmp(cub->map);
	cub->x = 450;
	cub->y = 250;
	draw_simple_map(cub);
	mlx_hook(cub->mlx->win, 17, 0, ft_exit, NULL);
	mlx_hook(cub->mlx->win,2,0,a_event,cub);
	// mlx_hook(cub->mlx->win,2,0,input_key,cub);
	mlx_loop(cub->mlx->ptr);
}
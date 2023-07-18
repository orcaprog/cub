/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:26:03 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/18 16:35:34 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_exit(void)
{
	write(1, "YOU ARE EXIT FROM CUB\n", 22);
	exit (0);
}

int	draw_game(t_info *cub)
{
	motion(cub);
	draw_cub3d(cub);
	open_door(cub);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	*cub;

	(void)ac;
	cub = malloc(sizeof(t_info));
	start_cub(cub, av);
	cub->check_shot = 0;
	cub->numb_shot = 0;
	cub->change_wap = 0;
	get_xpm_file(cub);
	draw_cub3d(cub);
	mlx_hook(cub->mlx->win, 17, 0, ft_exit, NULL);
	mlx_hook(cub->mlx->win, 2, 0, a_event, cub);
	mlx_hook(cub->mlx->win, 3, 0, input_key_relese, cub);
	mlx_hook(cub->mlx->win, 6, 0, mouse_view, cub);
	mlx_loop_hook(cub->mlx->ptr, draw_game, cub);
	mlx_loop(cub->mlx->ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:54:43 by abouassi          #+#    #+#             */
/*   Updated: 2023/07/13 19:33:36 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_info	*cub;

	(void)ac;
	cub = malloc(sizeof(t_info));
	start_cub(cub, av);
	point_of_view(cub);
	draw_mini_map(cub);
	mlx_hook(cub->mlx->win, 2, 0, a_event1, cub);
	mlx_loop(cub->mlx->ptr);
}

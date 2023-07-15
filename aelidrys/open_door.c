/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:26:51 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/15 16:28:19 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_open_door(t_info *cub, int key)
{
	float	cor_rad;
	t_point	px;
	t_point	py;
	int		d;

	d = 0;
	cor_rad = (M_PI * cub->corner) / 180.0;
	det_direction(cub, cor_rad);
	px = det_coord_x(cub, cor_rad, 0, cub->size);
	py = det_coord_y(cub, cor_rad, 0, cub->size);
	if (px.r < py.r)
		d = 1;
	if (px.r > py.r)
		px = py;
	if (px.r > 150 || key != 49)
		return ;
	if (prm_denied())
	cub->check_o_d = 1;
}

int	open_door(t_info *cub)
{
	float cor_rad;
	t_point	px;
	t_point	py;
	int		d;

	d = 0;
	cor_rad = (M_PI * cub->corner) / 180.0;
	det_direction(cub, cor_rad);
	px = det_coord_x(cub, cor_rad, 0, cub->size);
	py = det_coord_y(cub, cor_rad, 0, cub->size);
	if (px.r < py.r)
		d = 1;
	if (px.r > py.r)
		px = py;
	if (cub->check_o_d == 1)
		cub->open_d++;
	printf("%d\n",cub->open_d);
	if (d == 1 && sin(cor_rad) < 0 && cub->check_o_d == 1)//S
		if (cub->map[(int)(px.y / 100)][(int)(px.x / 100)] == 'D'){
			if (cub->open_d % 10 == 0){
				cub->img_d = cub->img_d->next;
				printf("enter\n");
			}
			// if (cub->open_d == 4000)
			// 	cub->map[(int)(px.y / 100)][(int)(px.x / 100)] = '0';
	}
	if (d == 1 && sin(cor_rad) > 0 && cub->check_o_d == 1)//N
		if (cub->map[(int)(px.y / 100) - 1][(int)(px.x / 100)] == 'D'){
			cub->map[(int)(px.y / 100) - 1][(int)(px.x / 100)] = '0';
	}
	if (d == 0 && cos(cor_rad) < 0 && cub->check_o_d == 1)//W
		if (cub->map[(int)(px.y / 100)][(int)(px.x / 100) - 1] == 'D'){
			cub->map[(int)(px.y / 100)][(int)(px.x / 100) - 1] = '0';
	}
	if (d == 0 && cos(cor_rad) > 0 && cub->check_o_d == 1)//E
		if (cub->map[(int)(px.y / 100)][(int)(px.x / 100)] == 'D'){
			cub->map[(int)(px.y / 100)][(int)(px.x / 100)] = '0';
	}
	if (cub->open_d == 30)
	{
		cub->open_d = 0;
		cub->check_o_d = 0;
	}
	return (0);
}

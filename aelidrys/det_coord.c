/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 08:58:20 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/13 19:50:32 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		*det_coord_y(t_info *cub, double cor_rd)
{
	int coord[2];
	double x_i;
	double y_i;
	double y;
	(void)coord;
	if (cub->y_d == 1)
	{
		y = (cub->y / 100) * 100;
		y_i = cub->y - y;
		x_i = y_i / tan(cor_rd);
		printf("y_i = %lf\n", y_i);
		printf("x_i = %lf\n", x_i);
	}
	return (0);
	// if (cub->y_d == -1)
	// {
	// 	;
	// }
}

void	det_direction(t_info *cub, double cor_rd)
{
	if (cos(cor_rd) < 0)
		cub->x_d = -1;
	if (cos(cor_rd) > 0)
		cub->x_d = 1;
	if (sin(cor_rd) > 0)
		cub->y_d = -1;
	if (sin(cor_rd) < 0)
		cub->y_d = 1;
	det_coord_y(cub, cor_rd);
}

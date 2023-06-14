/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 08:58:20 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/14 16:50:14 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_coord_in_map_range(t_info *cub, double x, double y)
{
	if (y < 1 || x < 1)
		return (0);
	if (y >= size_of_arry(cub->map) - 1 || x >= ft_strlen(cub->map[(int)y]) - 1)
		return (0);
	return (1);
}

t_point		*det_coord_y(t_info *cub, double cor_rd)
{
	double coord[2];
	double x_i;
	double y_i;
	double y;
	(void)coord;
	if (cub->y_d == 1)
	{
		y = ((cub->y / 100) * 100) + 100;
		y_i = cub->y - y;
		x_i = y_i / tan(cor_rd);
		coord[0] = cub->x + x_i;
		coord[1] = y;
		printf("1p_x = %lf\n", coord[0]);
		printf("1p_y = %lf\n", coord[1]);
	}
	if (cub->y_d == -1)
	{

		y = (cub->y / 100) * 100;
		y_i = (y - cub->y) * -1;
		x_i = y_i / tan(cor_rd);
		coord[0] = cub->x + x_i;
		coord[1] = y;
		printf("p_x = %lf\n", coord[0]);
		printf("p_y = %lf\n", coord[1]);
	}
	printf("is_in_map_range = %d\n", is_coord_in_map_range(cub, coord[0]/100, coord[1]/100));
	return (0);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 08:58:20 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/16 08:45:22 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_coord_in_map_range(t_info *cub, double x, double y)
{
	double	x1;
	double	y1;

	x1 = floor(x / 100);
	y1 = floor(y / 100);
	if (y1 < 1 || x1 < 1)
		return (0);
	if (y1 >= size_of_arry(cub->map) - 1 || x1 >= ft_strlen(cub->map[(int)y1]) - 1)
		return (0);
	return (1);
}

t_point		det_coord_y(t_info *cub, double cor_rd)
{
	t_point	p;
	double	dx;
	double	dy;
	int ky,kx=0;
	ky = 0;
	p.y = cub->y;
	if (cub->y_d == -1)
		p.y = (floor(cub->y / 100) * 100) + 100;
	while (1){
		ky = 0;kx = 0;
		if (cub->y_d == 1)
		{
			p.y = (floor(p.y / 100) * 100) + 100;
			dy = (p.y - cub->y);
			dx = (dy / tan(cor_rd));
			p.x = cub->x - dx;
		}
		if (cub->y_d == -1)
		{
			ky = 1;
			p.y -= 100;
			dy = (cub->y - p.y);
			dx = (dy / tan(cor_rd));
			p.x = cub->x + dx;
			// printf("y_d = -1 => dy = %lf & dx = %lf\n", dy, dx);
		}
		// printf("p_x = %lf\n", p.x);
		// printf("p_y = %lf\n", p.y);
		if ((int)(p.x) % 100 == 0 && (int)(p.y) % 100 == 0)
			kx = 1;
		// printf("is_in_map_range = %d\n\n", is_coord_in_map_range(cub, p.x, p.y));
		if (!is_coord_in_map_range(cub, p.x, p.y) || prm_moves(cub->map,(p.x / 100) - kx,(p.y / 100) - ky))
			break;
	}
	p.r = sqrt(pow(floor(cub->x - p.x),2) + pow(floor(cub->y - p.y),2));
	if (p.r < 0)
		p.r *= -1;
	if (p.r == -2147483648)
		p.r = p.r + 1 * -1;
	// printf("{p1.r = %lf}\n",p.r);
	return (p);
}

void	det_direction(t_info *cub, double cor_rd)
{
	(void)cor_rd;
	if (cos(cor_rd) < 0)
		cub->x_d = -1;
	if (cos(cor_rd) >= 0)
		cub->x_d = 1;
	if (sin(cor_rd) > 0)
		cub->y_d = -1;
	if (sin(cor_rd) < 0)
		cub->y_d = 1;
}

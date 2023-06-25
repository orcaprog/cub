/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 08:58:20 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/25 15:46:54 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_coord_in_map_range(t_info *cub, double x, double y, int size)
{
	double	x1;
	double	y1;

	x1 = floor(x / size);
	y1 = floor(y / size);
	if (y1 <= 0 || x1 <= 0)
		return (0);
	if (y1 >= size_of_arry(cub->map) - 1 || x1 >= ft_strlen(cub->map[(int)y1]) - 1)
		return (0);
	return (1);
}

void	det_distance_r(t_point *p, t_info *cub)
{
	p->r = sqrt(pow((cub->x - p->x),2) + pow((cub->y - p->y),2));
	if (p->r == -2147483648)
		p->r = p->r + 1 * -1;
}

void	init_x_y(t_info *cub, t_point *p, int s, int size)
{
	if (s == 0)
	{
		p->x = cub->x;
		if (cub->x_d == -1)
			p->x = (floor(cub->x / size) * size) + size;
	}
	if (s == 1)
	{
		p->y = cub->y;
		if (cub->y_d == -1)
			p->y = (floor(cub->y / size) * size) + size;
	}
}

// int	is_in_wall(t_info *cub, t_point p, int *k, int d1)
// {
// 	if ((int)(p.x) % 100 == 0 && (int)(p.y) % 100 == 0 && d1 == -1)
// 	{
// 		if ((is_coord_in_map_range(cub, p.x - 100, p.y - 100, size) && prm_moves(cub->map, p.x / 100 - 1, p.y / 100 - 1))
// 			|| (is_coord_in_map_range(cub, p.x - 100, p.y, size) && prm_moves(cub->map, p.x / 100 - 1, p.y / 100)))
// 			return (0);
// 		k[0] = 0;
// 	}
// 	if ((int)(p.x) % 100 == 0 && (int)(p.y) % 100 == 0 && d1 == 1)
// 	{
// 		if ((is_coord_in_map_range(cub, p.x, p.y - 100, size) && prm_moves(cub->map,p.x / 100,(p.y / 100) - 1))
// 				|| (is_coord_in_map_range(cub, p.x, p.y, size) && prm_moves(cub->map,p.x / 100, p.y / 100)))
// 			return (0);
// 	}
// 	return (1);
// }

t_point	det_coord_y(t_info *cub, double cor_rad, int k, int size)
{
	t_point	p;

	init_x_y(cub, &p, 0, size);
	while (1)
	{
		k = 0;
		if (cub->x_d == 1)
		{
			p.x = (floor(p.x / size) * size) + size;
			p.y = cub->y - ((p.x - cub->x) * tan(cor_rad));
		}
		if (cub->x_d == -1)
		{
			k = 1;
			p.x -=  size;
			p.y = cub->y + ((cub->x - p.x) * tan(cor_rad));
		}
		if (!is_coord_in_map_range(cub,p.x - (size * k) ,p.y, size)
				|| prm_moves(cub->map,floor(p.x / size) - k,floor(p.y / size)))
			break;
	}
	det_distance_r(&p,cub);
	return (p);
}

t_point		det_coord_x(t_info *cub, double cor_rd, int k, int size)
{
	t_point	p;

	init_x_y(cub, &p, 1, size);
	while (1)
	{
		k = 0;
		if (cub->y_d == 1)
		{
			p.y = (floor(p.y / size) * size) + size;
			p.x = cub->x - ((p.y - cub->y) / tan(cor_rd));
		}
		if (cub->y_d == -1)
		{
			k = 1;
			p.y -= size;
			p.x = cub->x + ((cub->y - p.y) / tan(cor_rd));
		}
		if (!is_coord_in_map_range(cub,p.x , p.y - (size * k), size)
				|| prm_moves(cub->map,(p.x / size),(p.y / size) - k))
			break;
	}
	det_distance_r(&p,cub);
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

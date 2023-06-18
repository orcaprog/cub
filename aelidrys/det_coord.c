/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 08:58:20 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/18 11:28:03 by aelidrys         ###   ########.fr       */
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

void	det_distance_r(t_point *p, t_info *cub)
{
	p->r = sqrt(pow(floor(cub->x - p->x),2) + pow(floor(cub->y - p->y),2));
	if (p->r < 0)
		p->r *= -1;
	if (p->r == -2147483648)
		p->r = p->r + 1 * -1;
}

t_point	det_coord_x(t_info *cub, double cor_rad, int kx, int ky)
{
	t_point	p;

	p.x = cub->x;
	if (cub->x_d == -1)
		p.x = (floor(cub->x / 100) * 100) + 100;
	while (1)
	{
		kx = 0;
		ky = 0;
		//printf("%d------>\n",is_coord_in_map_range(cub,cub->x / 100,cub-y / 100));
		if (cub->x_d == 1)
		{
			p.x = (floor(p.x / 100) * 100) + 100;
			p.y = cub->y - ((p.x - cub->x) * tan(cor_rad));
		}
		if (cub->x_d == -1)
		{
			kx = 1;
			p.x -=  100;
			p.y = cub->y + ((cub->x - p.x) * tan(cor_rad));
		}
		if ((int)(p.x) % 100 == 0 && (int)(p.y) % 100 == 0 && cub->y_d == -1)
		 	ky = 1;
		// printf("Px    ->   [%lf]-%d\nPy    ->   [%lf]-%d\ncorner    ->   [%f]\n",p.x,kx,p.y,ky,cub->corner);
		if (!is_coord_in_map_range(cub,p.x ,p.y) || prm_moves(cub->map,floor(p.x / 100.0) - kx,floor(p.y / 100.0) - ky))
			break;
	}
	det_distance_r(&p,cub);
	return (p);
	//p.x_y(cub,point_x ,point_y);
}

int	is_in_wall(t_info *cub, t_point p, int *kx)
{
	if ((int)(p.x) % 100 == 0 && (int)(p.y) % 100 == 0 && cub->x_d == -1){
		if (is_coord_in_map_range(cub, p.x, p.y) && (prm_moves(cub->map,(p.x / 100) - 1,(p.y / 100) - 1)
				|| prm_moves(cub->map,(p.x / 100) - 1,(p.y / 100))))
			return (0);
		*kx = 1;
	}
	if ((int)(p.x) % 100 == 0 && (int)(p.y) % 100 == 0 && cub->x_d == 1){
		if (is_coord_in_map_range(cub, p.x, p.y) && (prm_moves(cub->map,(p.x / 100),(p.y / 100) - 1)
				|| prm_moves(cub->map,(p.x / 100), (p.y / 100))))
			return (0);
	}
	return (1);
}

t_point		det_coord_y(t_info *cub, double cor_rd, int kx, int ky)
{
	t_point	p;

	p.y = cub->y;
	if (cub->y_d == -1)
		p.y = (floor(cub->y / 100) * 100) + 100;
	// printf("++++++++++++++\n");
	while (1)
	{
		ky = 0;
		kx = 0;
		if (cub->y_d == 1)
		{
			p.y = (floor(p.y / 100) * 100) + 100;
			p.x = cub->x - ((p.y - cub->y) / tan(cor_rd));
			if ((int)p.x % 100 >= 98)
				p.x = (floor(p.x / 100) + 1) * 100;
		}
		if (cub->y_d == -1)
		{
			ky = 1;
			p.y -= 100;
			p.x = cub->x + ((cub->y - p.y) / tan(cor_rd));
			// printf("y_d = -1 => dy = %lf & dx = %lf\n", dy, dx);
		}
		// printf("p_x = %lf - %d\n", p.x,kx);
		// printf("p_y = %lf - %d\n", p.y,ky);
		// printf("is_in_map_range = %d\n\n", is_coord_in_map_range(cub, p.x, p.y));
		if (!is_in_wall(cub, p, &kx) || !is_coord_in_map_range(cub, p.x, p.y) || prm_moves(cub->map,(p.x / 100) - kx,(p.y / 100) - ky))
			break;
	}
	det_distance_r(&p,cub);
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

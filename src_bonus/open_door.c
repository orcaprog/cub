/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:26:51 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/20 11:16:36 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_door_moves(t_info *cub, t_point *p)
{
	if (p->dir == 'N' && is_in_str("DEFG",
			cub->map[(int)(p->y / 100) - 1][(int)(p->x / 100)]))
		return (0);
	if (p->dir == 'W' && is_in_str("DEFG",
			cub->map[(int)(p->y / 100)][(int)(p->x / 100) - 1]))
		return (0);
	if ((p->dir == 'E' || p->dir == 'S') && is_in_str("DEFG",
			cub->map[(int)(p->y / 100)][(int)(p->x / 100)]))
		return (0);
	return (1);
}

int	prm_denied(t_info *cub, t_point p)
{
	if (p.dir == 'S')
		if (is_in_str("ABCDEFG", cub->map[(int)(p.y / 100)][(int)(p.x / 100)]))
			return (1);
	if (p.dir == 'N')
		if (is_in_str("ABCDEFG", cub->map[(int)(p.y / 100) - 1][(int)(p.x
			/ 100)]))
			return (1);
	if (p.dir == 'W')
		if (is_in_str("ABCDEFG", cub->map[(int)(p.y / 100)][(int)(p.x
			/ 100) - 1]))
			return (1);
	if (p.dir == 'E')
		if (is_in_str("ABCDEFG", cub->map[(int)(p.y / 100)][(int)(p.x / 100)]))
			return (1);
	return (0);
}

void	check_open_door(t_info *cub, int key)
{
	float	cor_rad;
	t_point	px;
	t_point	py;

	(void)key;
	if (cub->check_o_d)
		return ;
	cor_rad = (M_PI * cub->corner) / 180.0;
	det_direction(cub, cor_rad);
	px = det_coord_x(cub, cor_rad, "1ABCDEFGHIJKLMNOPQRS", cub->size);
	py = det_coord_y(cub, cor_rad, "1ABCDEFGHIJKLMNOPQRS", cub->size);
	if (px.r > py.r)
		px = py;
	if (px.r > 200)
		return ;
	if (!prm_denied(cub, px))
		return ;
	cub->p = px;
	cub->check_o_d = 1;
}

void	draw_door(t_info *cub, int x, int y)
{
	if (cub->open_d == 2 || cub->open_d == 68)
		cub->map[y][x] = 'B';
	if (cub->open_d == 4 || cub->open_d == 66)
		cub->map[y][x] = 'C';
	if (cub->open_d == 6 || cub->open_d == 64)
		cub->map[y][x] = 'D';
	if (cub->open_d == 8 || cub->open_d == 62)
		cub->map[y][x] = 'E';
	if (cub->open_d == 10 || cub->open_d == 60)
		cub->map[y][x] = 'F';
	if (cub->open_d == 12)
		cub->map[y][x] = 'G';
	if (cub->open_d == 70)
		cub->map[y][x] = 'A';
}

int	open_door(t_info *cub)
{
	if (cub->check_o_d != 1 || cub->p.r > 200)
		return (0);
	if (cub->open_d > 60 && is_in_str("DEFG", cub->map[(int)(cub->y
				/ 100)][(int)(cub->x / 100)]))
		cub->open_d = 60;
	cub->open_d++;
	if (cub->p.dir == 'S')
		draw_door(cub, (int)(cub->p.x / 100), (int)(cub->p.y / 100));
	else if (cub->p.dir == 'N')
		draw_door(cub, (int)(cub->p.x / 100), (int)(cub->p.y / 100 - 1));
	else if (cub->p.dir == 'W')
		draw_door(cub, (int)(cub->p.x / 100 - 1), (int)(cub->p.y / 100));
	else if (cub->p.dir == 'E')
		draw_door(cub, (int)(cub->p.x / 100), (int)(cub->p.y / 100));
	if (cub->open_d == 71)
	{
		cub->open_d = 0;
		cub->check_o_d = 0;
	}
	return (0);
}

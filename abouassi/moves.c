/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:42:41 by abouassi          #+#    #+#             */
/*   Updated: 2023/07/13 20:33:23 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	prm_moves(char **map, int x, int y)
{
	if (map[y][x] == '1')
	{
		return (1);
	}
	return (0);
}

void	move_right(t_info *data, int size)
{
	t_var	var;
	t_point	p1;
	t_point	p2;
	double	r;
	int		grid;

	grid = MOVE_SPEED;
	var.check = 1;
	var.cor_rd = ((3.14159265359 * (data->corner + 90)) / 180.0000);
	det_direction(data, var.cor_rd);
	p1 = det_coord_x(data, var.cor_rd, 0, size);
	p2 = det_coord_y(data, var.cor_rd, 0, size);
	r = p1.r;
	if ((p2.r) < (p1.r))
		r = p2.r;
	if (r <= 20)
		var.check = 0;
	else if (20 > r - MOVE_SPEED)
		grid = r - 20;
	if (var.check)
	{
		data->x = data->x + cos(var.cor_rd) * grid;
		data->y = data->y - sin(var.cor_rd) * grid;
	}
}

void	move_left(t_info *data, int size)
{
	t_var	var;
	t_point	p1;
	t_point	p2;
	double	r;
	int		grid;

	grid = MOVE_SPEED;
	var.check = 1;
	var.cor_rd = ((3.14159265359 * (data->corner - 90)) / 180.0000);
	det_direction(data, var.cor_rd);
	p1 = det_coord_x(data, var.cor_rd, 0, size);
	p2 = det_coord_y(data, var.cor_rd, 0, size);
	r = p1.r;
	if ((p2.r) < (p1.r))
		r = p2.r;
	if (r <= 20)
		var.check = 0;
	else if (20 > r - MOVE_SPEED)
		grid = r - 20;
	if (var.check)
	{
		data->x = data->x + cos(var.cor_rd) * grid;
		data->y = data->y - sin(var.cor_rd) * grid;
	}
}

void	move_down(t_info *data, int size)
{
	t_var	var;
	t_point	p1;
	t_point	p2;
	double	r;
	int		grid;

	grid = MOVE_SPEED;
	var.cor_rd = ((M_PI * (data->corner - 180)) / 180.0000);
	var.check = 1;
	det_direction(data, var.cor_rd);
	p1 = det_coord_x(data, var.cor_rd, 0, size);
	p2 = det_coord_y(data, var.cor_rd, 0, size);
	r = p1.r;
	if ((p2.r) < (p1.r))
		r = p2.r;
	if (r <= 20)
		var.check = 0;
	else if (20 > r - MOVE_SPEED)
		grid = r - 20;
	if (var.check)
	{
		data->y = data->y - sin(var.cor_rd) * grid;
		data->x = data->x + cos(var.cor_rd) * grid;
	}
}

void	move_up(t_info *data, int size)
{
	t_var	var;
	t_point	p1;
	t_point	p2;
	double	r;
	int		grid;

	grid = MOVE_SPEED;
	var.cor_rd = (3.14159265359 * data->corner) / 180.0000;
	var.check = 1;
	det_direction(data, var.cor_rd);
	p1 = det_coord_x(data, var.cor_rd, 0, size);
	p2 = det_coord_y(data, var.cor_rd, 0, size);
	r = p1.r;
	if ((p2.r) < (p1.r))
		r = p2.r;
	if (r <= 20)
		var.check = 0;
	else if (20 > r - MOVE_SPEED)
		grid = r - 20;
	if (var.check)
	{
		data->y = data->y - sin(var.cor_rd) * grid;
		data->x = data->x + cos(var.cor_rd) * grid;
	}
}

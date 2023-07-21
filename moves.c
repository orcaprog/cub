/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 08:54:09 by abouassi          #+#    #+#             */
/*   Updated: 2023/07/21 08:54:48 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_coll(t_point p,t_info *data, float cor_rad,int grid)
{
	if((p.dir == 'S' ||p.dir == 'N') && is_coord_in_map_range(data,data->x + cos(cor_rad) * grid,data->y,100))// S && W
	{
		if(!prm_moves1(data->map,"12",(data->x + cos(cor_rad) * grid)/ 100,data->y / 100 ))
				data->x = data->x + cos(cor_rad) * grid;
	}
	if((p.dir == 'W' ||  p.dir == 'E') && is_coord_in_map_range(data,data->x,data->y - sin(cor_rad) * grid,100))// W && N
	{
		if(!prm_moves1(data->map,"12",data->x / 100,(data->y - sin(cor_rad) * grid) / 100 ))
			data->y = data->y - sin(cor_rad) * grid;
	
	}
}
void	move_right(t_info *data, int size)
{
	t_var	var;
	t_point	px;
	t_point	py;
	int		grid;

	if (data->m_r == 0)
		return ;
	grid = MOVE_SPEED;
	var.check = 1;
	var.cor_rd = ((3.14159265359 * (data->corner + 90)) / 180.0000);
	det_direction(data, var.cor_rd);
	px = det_coord_x(data, var.cor_rd, "1ABCDEFGHIJKLMOPQR", size);
	py = det_coord_y(data, var.cor_rd, "1ABCDEFGHIJKLMOPQR", size);
	if ((py.r) < (px.r))
		px = py;
	if (px.r <= 20)
		var.check = 0;
	else if (20 > px.r - MOVE_SPEED)
		grid = px.r - 20;
	if (var.check)
	{
		data->x = data->x + cos(var.cor_rd) * grid;
		data->y = data->y - sin(var.cor_rd) * grid;
	}
}

void	move_left(t_info *data, int size)
{
	t_var	var;
	t_point	px;
	t_point	py;
	int		grid;

	if (data->m_l == 0)
		return ;
	grid = MOVE_SPEED;
	var.check = 1;
	var.cor_rd = ((3.14159265359 * (data->corner - 90)) / 180.0000);
	det_direction(data, var.cor_rd);
	px = det_coord_x(data, var.cor_rd, "1ABCDEFGHIJKLMOPQR", size);
	py = det_coord_y(data, var.cor_rd, "1ABCDEFGHIJKLMOPQR", size);
	if ((py.r) < (px.r))
		px = py;
	if (px.r <= 20)
		var.check = 0;
	else if (20 > px.r - MOVE_SPEED)
		grid = px.r - 20;
	if (var.check)
	{
		data->x = data->x + cos(var.cor_rd) * grid;
		data->y = data->y - sin(var.cor_rd) * grid;
	}
}

void	move_down(t_info *data, int size)
{
	t_var	var;
	t_point	px;
	t_point	py;
	int		grid;

	if (data->m_d == 0)
		return ;
	grid = MOVE_SPEED;
	var.cor_rd = ((M_PI * (data->corner - 180)) / 180.0000);
	var.check = 1;
	det_direction(data, var.cor_rd);
	px = det_coord_x(data, var.cor_rd, "1ABCDEFGHIJKLMOPQR", size);
	py = det_coord_y(data, var.cor_rd, "1ABCDEFGHIJKLMOPQR", size);
	if ((py.r) < (px.r))
		px = py;
	if (px.r <= 20)
		var.check = 0;
	else if (20 > px.r - MOVE_SPEED)
		grid = px.r - 19;
	if (var.check)
	{
		data->y = data->y - sin(var.cor_rd) * grid;
		data->x = data->x + cos(var.cor_rd) * grid;
	}
	else
		check_coll(px,data,var.cor_rd,grid);
}

void	move_up(t_info *data, int size)
{
	t_var	var;
	t_point	px;
	t_point	py;
	int		grid;

	if (data->m_u == 0)
		return ;
	grid = MOVE_SPEED;
	var.cor_rd = (3.14159265359 * data->corner) / 180.0000;
	var.check = 1;
	det_direction(data, var.cor_rd);
	px = det_coord_x(data, var.cor_rd, "1ABCDEFGHIJKLMOPQR", size);
	py = det_coord_y(data, var.cor_rd, "1ABCDEFGHIJKLMOPQR", size);
	if ((py.r) < (px.r))
		px = py;
	if (px.r <= 20 && check_door_moves(data, &px))
		var.check = 0;
	else if (20 > px.r - MOVE_SPEED && check_door_moves(data, &px))
		grid = px.r - 19;
	if (var.check || data->map[(int)(px.y / 100)][(int)(px.x / 100)] == '8')
	{
		data->y = data->y - sin(var.cor_rd) * grid;
		data->x = data->x + cos(var.cor_rd) * grid;
	}
	else
		check_coll(px,data,var.cor_rd,grid);
}

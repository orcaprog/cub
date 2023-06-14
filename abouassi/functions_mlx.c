/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:45:40 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/14 16:43:41 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



t_point point_x_y(t_info *data)
{
	t_point point;
	double point_x = 0;
	double point_y = 0;
	double old_x = data->x;
	double old_y = data->y;
	int xi = 0;
	double	cor_rad;
	cor_rad = (3.14159265359 * data->corner)/180.0000;

	printf("x_d %d\n",data->x_d);
	while(!prm_moves(data->map,(old_x / 100),(old_y / 100)))
	{
		printf("Px    ->   [%f]\nPy    ->   [%f]\ncorner    ->   [%f]\n",old_x,old_y,data->corner);
		if (data->x_d == 1)
		{
			point_x = (floor(old_x / 100) + 1) * 100;
			xi = point_x - old_x;
			point_y = old_y - (xi * tan(cor_rad));
		}
		if (data->x_d == -1)
		{
			point_x = (floor(old_x / 100)) * 100;
			xi = point_x - old_x;
			point_y = old_y + (xi * tan(cor_rad));
		}
		old_x = point_x;
		old_y = point_y;

	}
	point.x = point_x;
	point.y = point_y;
	return (point);
	//point_x_y(data,point_x ,point_y);
}
void	find_cord_x(t_info *data)
{
	//printf("Px    ->   [%f]\nPy    ->   [%f]\ncorner    ->   [%f]\n",data->x,data->y,data->corner);
	t_point point;
	if (data->corner < 60)
	{
		printf("=============================================\n");
		point = point_x_y(data);
		printf("=============================================\n");
	}
	
	// printf("-------  tan(cor_rad)[%f]\n",tan(cor_rad));
	printf("-------  p_x(%f)\n",point.x);
	printf("-------  p_y(%f)\n",point.y);
	// printf("-------  xi(%d)\n",xi);
	// printf("-------  p_y(%d)\n",point_y);
	
}

int	input_key(int key, t_info *data)
{
	find_cord_x(data);
		
	if (key == 2)
	{
		move_right(data);
	}
	if (key == 0)
	{
		move_left(data);
	}
	if (key == 125 || key == 1)
	{
		move_down(data);
	}
	if (key == 126 || key == 13)
	{
		move_up(data);
	}
	
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:45:40 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/15 15:53:05 by abouassi         ###   ########.fr       */
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
	int kx=0,ky = 0;
	cor_rad = (3.14159265359 * data->corner)/180.0000;

	//printf("x_d %d\n",data->x_d);
	point_x = (floor(old_x / 100) + 1) * 100;
	while(is_coord_in_map_range(data,old_x / 100,old_y / 100) && !prm_moves(data->map,floor(old_x / 100.0) - kx,floor(old_y / 100.0) - ky))
	{
		kx = 0;
		ky = 0;
		if (data->y_d == -1)
			ky = 1;
		if (data->x_d == -1)
			kx = 1;
		//printf("%d------>\n",is_coord_in_map_range(data,old_x / 100,old_y / 100));
		if (data->x_d == 1)
		{
			//printf("---------(1)---------\n");
			point_x = (floor(old_x / 100) + 1) * 100;
			xi = point_x - old_x;
			point_y = old_y - floor(xi * tan(cor_rad)) + 1;
		}
		if (data->x_d == -1)
		{
			//printf("--------(-1)-----------\n");
			point_x -=  100;
			xi = old_x - point_x;
			point_y = old_y + floor(xi * tan(cor_rad)) + 1;
		}
		old_x = point_x;
		old_y = point_y;
		 //printf("Px    ->   [%lf]-%d\nPy    ->   [%lf]-%d\ncorner    ->   [%f]\n",old_x,kx,old_y,ky,data->corner);
		// printf("Px    ->   [%d]-%d\nPy    ->   [%d]-%d\ncorner    ->   [%f]\n",(int)old_x,kx,(int)old_y,ky,data->corner);

	}
	point.x = point_x;
	point.y = point_y;
	return (point);
	//point_x_y(data,point_x ,point_y);
}
t_point	find_cord_x(t_info *data)
{
	//printf("Px    ->   [%f]\nPy    ->   [%f]\ncorner    ->   [%f]\n",data->x,data->y,data->corner);
	t_point point;

		//printf("=============================================\n");
		point = point_x_y(data);
		

		point.r = sqrt(pow(data->x - point.x,2) + pow(data->y  - point.y,2));
		//printf("=============================================\n");

	
	// printf("-------  tan(cor_rad)[%f]\n",tan(cor_rad));
	printf("-------  point x(%f)\n",point.x);
	printf("-------  point y(%f)\n",point.y);
	printf("-------  r           (%f)\n",point.r);
	// printf("-------  xi(%d)\n",xi);
	// printf("-------  p_y(%d)\n",point_y);
	return(point);
}

int	input_key(int key, t_info *data)
{
	//find_cord_x(data);
		
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
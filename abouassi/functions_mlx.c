/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:45:40 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/16 12:02:19 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
// void	draw_ray2(t_info *cub, int o, int color)
// {
// 	double	x;
// 	double	y;
// 	int	rf;
// 	int	ri = 0;
// 	double	cor_rd;
// 	t_point	p;

// 	(void)o;
// 	cor_rd = (3.14159265359 * cub->corner)/180.0000;
// 	if (color){
// 		printf("tan(%lf) = %lf\n",cub->corner,tan(cor_rd));
// 		printf("cos(%lf) = %lf\n", cub->corner,cos(cor_rd));
// 		printf("sin(%lf) = %lf\n----------\n", cub->corner,sin(cor_rd));

// 	}
// 	det_direction(cub, cor_rd);
// 	p = find_cord_x(cub);
// 	if (p.x < 100)
// 		p.x = 100;
// 	//rf = sqrt(pow(floor(cub->x - p.x),2) + pow(floor(cub->y - p.y),2));
// 	rf = p.r;
// 	printf("++++++++++++++\n---- [%lf,%lf] ----\n++++++++++++++\n",p.x,p.y);
// 	if (rf < 0)
// 		rf *= -1;
// 	x = cub->x + 5 * cos(cor_rd);
// 	y = cub->y - 5 * sin(cor_rd);
// 	printf("$$$$RI = %lf && RF = %d$$$$\n",sqrt(pow(floor(cub->x - x),2) + pow(floor(cub->y - y),2)),rf);
// 	while (ri < rf){
// 		mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, x, y, color);
// 		x += cos(cor_rd);
// 		y -= sin(cor_rd);
// 		ri = sqrt(pow(floor(cub->x - x),2) + pow(floor(cub->y - y),2));
// 		if (ri < 0)
// 			ri *=-1;
// 	}
// }

// int	a_event1(int key, t_info *cub)
// {
// 	draw_ray2(cub, 0, 0);
// 	input_key(key, cub);
// 	draw_ray2(cub, 0, 16777215);
// 	if (key == 124)
// 	{
// 		draw_ray2(cub, 0, 0);
// 		cub->corner--;
// 		draw_ray2(cub, 0, 16777215);
// 	}
// 	if (key == 123)
// 	{
// 		draw_ray2(cub, 0, 0);
// 		cub->corner++;
// 		draw_ray2(cub, 1, 16777215);
// 	}
// 	return (0);
// }

t_point	point_x_y(t_info *data)
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
	if (data->x_d == -1)
		point_x = (floor(old_x / 100) + 1) * 100;
	while(is_coord_in_map_range(data,old_x ,old_y) && !prm_moves(data->map,floor(old_x / 100.0) - kx,floor(old_y / 100.0) - ky))
	{
		kx = 0;
		ky = 0;
		if (data->x_d == -1)
			kx = 1;
		//printf("%d------>\n",is_coord_in_map_range(data,old_x / 100,old_y / 100));
		if (data->x_d == 1)
		{
			//printf("---------(1)---------\n");
			point_x = (floor(old_x / 100) + 1) * 100;
			xi = point_x - old_x;
			point_y = old_y - (xi * tan(cor_rad));
		}
		if (data->x_d == -1)
		{
			//printf("--------(-1)-----------\n");
			point_x -=  100;
			xi = old_x - point_x;
			point_y = old_y + (xi * tan(cor_rad))  ;
		}
		old_x = point_x;
		old_y = point_y;
		if ((int)(old_x) % 100 == 0 && (int)(old_y) % 100 == 0)
		 	ky = 1;
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
		

		point.r = sqrt(pow(floor(data->x - point.x),2) + pow(floor(data->y  - point.y),2));
		//printf("=============================================\n");

	
	// printf("-------  tan(cor_rad)[%f]\n",tan(cor_rad));
	// printf("-------  point x(%f)\n",point.x);
	// printf("-------  point y(%f)\n",point.y);
	// printf("-------  r           (%f)\n",point.r);
	// printf("-------  xi(%d)\n",xi);
	// printf("-------  p_y(%d)\n",point_y);
	return(point);
}

int	input_key(int key, t_info *data)
{
	//find_cord_x(data);
	//printf("")
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
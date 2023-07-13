/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:45:40 by abouassi          #+#    #+#             */
/*   Updated: 2023/07/11 11:20:31 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
int	mouse_view(int x, int y, t_info *cub)
{
		if (  x > cub->x_mouse)
		{
			cub->corner+=10;
			draw_simple_map(cub);
		}
		if ( x < cub->x_mouse )
		{
			cub->corner-=10;
			draw_simple_map(cub);
		}
		cub->x_mouse = x;
		cub->y_mouse = y;
	
	return 0;
}

int	input_key(int key, t_info *data)
{
	//find_cord_x(data);
	//printf("")
	
	if (key == 2)
	{
		move_right(data,100);
		//move_right_mini(data);
	}
	if (key == 0)
	{
		move_left(data,100);
		//move_left_mini(data);
	}
	if (key == 125 || key == 1)
	{
		move_down(data,100);
		//move_down_mini(data);
	}
	if (key == 126 || key == 13)
	{
		move_up(data,100);
		//move_up_mini(data);
	}
	
	if (key == 53)
	{
		exit(0);
	}
	// int i = 0;

	// while (data->map[i])
	// {
	// 	printf("%s\n",data->map[i]);
	// 	i++;
	// 	/* code */
	// }
	
	return (0);
}
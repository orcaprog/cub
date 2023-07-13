/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:45:40 by abouassi          #+#    #+#             */
/*   Updated: 2023/07/13 20:38:41 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_img*data, int x, int y, int color)
{
	char	*dst;

	if (x >= 350 || y >= 210)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_pix_mini(t_img*img, double x, double y, int color)
{
	double	i;
	double	j;

	i = y;
	while (i < y + M_G)
	{
		j = x;
		while (j < x + M_G)
		{
			my_mlx_pixel_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

int	mouse_view(int x, int y, t_info *cub)
{
	if (x > cub->x_mouse)
	{
		cub->corner += 10;
		draw_simple_map(cub);
	}
	if (x < cub->x_mouse)
	{
		cub->corner -= 10;
		draw_simple_map(cub);
	}
	cub->x_mouse = x;
	cub->y_mouse = y;
	return (0);
}

int	input_key(int key, t_info *data)
{
	if (key == 2)
		move_right(data, 100);
	if (key == 0)
		move_left(data, 100);
	if (key == 125 || key == 1)
		move_down(data, 100);
	if (key == 126 || key == 13)
		move_up(data, 100);
	if (key == 53)
		exit(0);
	return (0);
}

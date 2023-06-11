/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:45:40 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/11 14:45:58 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
int	input_key(int key, t_info *data)
{

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
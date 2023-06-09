/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tool1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:01:55 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/09 14:59:11 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_to_int(int color1, int color2, int color3)
{
	int	rgbtoint;

	rgbtoint = (color1 * 65536) + (color2 * 256) + color3;
	return (rgbtoint);
}

int	my_color(char *color)
{
	int rgbtoint;
	char **col;
	col = ft_split(color, ',');
	rgbtoint = rgb_to_int(ft_atoi(col[0]), ft_atoi(col[1]), ft_atoi(col[2]));
	ft_free(col);
	return (rgbtoint);
}

void	point_of_view(t_info *data)
{
	int i;
	int j;
	i = 0;

	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if(data->map[i][j] == 'N')
				data->p_v = 1;
			if(data->map[i][j] == 'E')
				data->p_v = 2;
			if(data->map[i][j] == 'S')
				data->p_v = 3;
			if(data->map[i][j] == 'W')
				data->p_v = 4;
			j++;
		}
		i++;
	}
}
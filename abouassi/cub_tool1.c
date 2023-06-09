/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tool1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:01:55 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/09 09:15:22 by abouassi         ###   ########.fr       */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 08:58:20 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/13 12:57:44 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	det_direction(t_info *cub)
{
	if (cos(cub->corner < 0) && sin(cub->corner) < 0)
		cub->dir = 1;
	if (cos(cub->corner < 0) && sin(cub->corner) > 0)
		cub->dir = 2;
	if (cos(cub->corner > 0) && sin(cub->corner) > 0)
		cub->dir = 3;
	if (cos(cub->corner > 0) && sin(cub->corner) < 0)
		cub->dir = 4;
}
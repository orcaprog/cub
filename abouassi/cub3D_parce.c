/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_parce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:27:39 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/09 08:17:52 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_cmp(char **map)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'N' || map[i][j] == 'S')
			{
				if (check)
					ft_puterr("Error");
				check++;
			}
			j++;
		}
		i++;
	}
	if (!check)
		ft_puterr("Error\n<!> no PLAYER <!>");
}

void	check_cmp_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'W'
				&& map[i][j] != 'S' && map[i][j] != 'N' && map[i][j] != 'E'
					&& map[i][j] != ' ')
			{
				ft_puterr("Error");
			}
			j++;
		}
		i++;
	}
}

void	check_mult_new(char *map, int i)
{
	while (map[i] && map[i] == '\n')
	{
		i++;
	}
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			ft_puterr("Error");
		}
		i++;
	}	
}

void	check_nwline(char *map)
{
	int	i;
	int	check;
	int	k;

	k = 0;
	check = 0;
	i = 0;
	while (map[i])
	{
		while (map[i] && map[i] != '\n')
		{
			i++;
			k++;
		}
		if (k != 0)
			check++;
		k = 0;
		if (!map[i] || check == 6)
			break ;
		i++;
	}
	check_mult_new(map, i);
}

void store_info(char **map, t_info *cub)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (ft_strnstr(map[i],"NO",ft_strlen(map[i])))
		{
			cub->no = map[i];
		}
		if (ft_strnstr(map[i],"SO",ft_strlen(map[i])))
		{
			cub->so = map[i];
		}
		if (ft_strnstr(map[i],"WE",ft_strlen(map[i])))
		{
			cub->we = map[i];
		}
		if (ft_strnstr(map[i],"EA",ft_strlen(map[i])))
		{
			cub->ea = map[i];
		}
		i++;
	}
	
}
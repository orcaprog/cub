/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_parce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:27:39 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/23 11:14:22 by abouassi         ###   ########.fr       */
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
		j =  0;
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
	char **line;
	i = 0;
	while (i < 6)
	{
		line = get_element(map[i]);
		if (!ft_strncmp(line[0],"NO",2))
		{
		
			//cub->no->img_xpm =  mlx_xpm_file_to_image(cub->mlx->ptr,line[1],&cub->no->x,&cub->no->y);
		}
		if (!ft_strncmp(line[0],"SO",2))
		{
		
			//cub->so->img_xpm =  mlx_xpm_file_to_image(cub->mlx->ptr,line[1],&cub->so->x,&cub->so->y);
		}
		if (!ft_strncmp(line[0],"WE",2))
		{
	
			//cub->we->img_xpm =  mlx_xpm_file_to_image(cub->mlx->ptr,line[1],&cub->we->x,&cub->we->y);
		}
		if (!ft_strncmp(line[0],"EA",2))
		{

			//cub->ea->img_xpm =  mlx_xpm_file_to_image(cub->mlx->ptr,line[1],&cub->ea->x,&cub->ea->y);
		}
		if (!ft_strncmp(line[0],"F",1))
		{
			cub->f = my_color(line[1]);
		}
		if (!ft_strncmp(line[0],"C",1))
		{
			cub->c = my_color(line[1]);
		}
		ft_free(line);
		i++;
	}
	
}
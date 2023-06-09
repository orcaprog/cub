/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:27:29 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/09 15:00:21 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cheak_wall(char *map)
{
	int	i;
	i  = 0;
	while (map[i])
	{
		if (map[i] == '1' || map[i] == ' ')
			i++;
		else
		{
			ft_puterr("Error");
		}
	}
}

void	check_s(char **map,size_t i, size_t j)
{
	if	(ft_strlen(map[i - 1]) <= j  || ft_strlen(map[i + 1]) <= j || j == 0)
	{
		ft_puterr("Error");
	}
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j - 1] == ' ' || map[i][j + 1] == ' '  || map[i][j + 1] == '\0')
	{
		ft_puterr("Error");
	}
}

void	cheak_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (map[j])
		j++;
	cheak_wall(map[0]);
	cheak_wall(map[j - 1]);
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if(map[i][j] == '0' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'N' || map[i][j] == 'S')
				check_s(map, i, j);
			j++;
		}
		i++;
	}
}

char **get_map(char *file)
{
	int		fd;
	char	**map;
	char	*maping;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_puterr("Error");
	}
	maping = get_next_line(fd);
	check_nwline(maping);
	map = ft_split(maping, '\n');
	return (map);
}

int main(int ac , char **av)
{
	(void)ac;
	char **map;
	t_info cub;
	int i;

	i = 0;
	map = get_map(av[1]);
	check_first_element(map, i);
	cheak_map(&map[6]);
	check_cmp(&map[6]);
	check_cmp_valid(&map[6]);
	cub.map = &map[6];
	store_info(map, &cub);
	point_of_view(&cub);
	// while (map[i])
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }
	printf("%s\n",cub.no);
	printf("%s\n",cub.so);
	printf("%s\n",cub.ea);
	printf("%s\n",cub.we);
	printf("%d\n",cub.f);
	printf("%d\n",cub.c);
	printf("%d\n",cub.p_v);
}

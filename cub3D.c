/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:27:29 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/07 15:58:23 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void cheak_wall(char *map)
{
	int i;
	i  = 0;
	while (map[i])
	{
		if (map[i] == '1' || map[i] == ' ')
			i++;
		else
		{
			ft_putendl_fd("Erorr",2);
			exit(1);
		}
	}
}

void check_s(char **map,size_t i, size_t j)
{
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j - 1] == ' ' || map[i][j + 1] == ' '  || map[i][j + 1] == '\0')
	{
		ft_putendl_fd("Erorr",2);
		exit(1);
	}
	if (ft_strlen(map[i - 1]) <= j  || ft_strlen(map[i + 1]) <= j || j == 0)
	{
		ft_putendl_fd("Erorr",2);
		exit(1);
	}
}
void cheak_map(char **map)
{
	size_t i;
	size_t j;

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
			if(map[i][j] == '0')
			{
				check_s(map,i,j);
			}
			j++;
		}
		i++;
	}
}
char **get_map(char *file)
{
	int fd;
	char **map;

	fd = open(file,O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		exit(1);
	}
	map = ft_split(get_next_line(fd),'\n');
	return(map);
	
}
int main(int ac ,char **av)
{
	(void)ac;
	char **map;
	int i;

	i = 0;
	map = get_map(av[1]);
	cheak_map(map);
	while (map[i])
	{
		printf("%s\n",map[i]);
		i++;
	}
	
	
}

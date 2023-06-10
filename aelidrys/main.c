/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:26:03 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/10 09:33:55 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
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

int	ft_exit(void)
{
	write(1,"YOU ARE EXIT FROM CUB\n",22);
	exit(0);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_info	*cub = malloc(sizeof(t_info));
	void *ptr = mlx_init();
	void *win = mlx_new_window(ptr,1000,700,"CUB");
	cub->map = get_map(av[1]);
	check_first_element(cub->map,0);
	check_cmp(cub->map + 6);
	int a = 0;
	while (a <= 700){
		for (int i = 0; i <= 1000; i++)
			mlx_pixel_put(ptr,win,i,a,16777215);
		a += 100;
	}
	a = 0;
	while (a <= 1000){
		for (int i = 0; i <= 700; i++)
			mlx_pixel_put(ptr,win,a,i,16777215);
		a += 100;
	}
	int b = 0;
	void *img_b = mlx_xpm_file_to_image(ptr,"box.xpm",&a,&b);
	b = 0;
	while (b < 700)
	{
		a = 0;
		while (a < 1000){
			if (b  == 0)
				mlx_put_image_to_window(ptr,win,img_b,a,b);
			else if (b == 300){
				if (a != 400 && a != 500)
					mlx_put_image_to_window(ptr,win,img_b,a,b);
			}
			else if (b == 600)
				mlx_put_image_to_window(ptr,win,img_b,a,b);
			else{
				mlx_put_image_to_window(ptr,win,img_b,0,b);
				mlx_put_image_to_window(ptr,win,img_b,900,b);
				break;
			}
			a += 100;
		}
		b += 100;
	}
	mlx_hook(win, 17, 0, ft_exit, NULL);
	mlx_loop(ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:54:43 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/10 11:55:57 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
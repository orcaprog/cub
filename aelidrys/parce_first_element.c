/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_first_element.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:20:40 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/08 06:05:53 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

void	chek_direction(char *str)
{
	int		i;
	char	**direct;

	i = -1;
	direct = ft_split("NO SO WE EA C F", ' ');
	while (direct && direct[++i])
		if (strcmp(str, direct[i]))
			break ;
	if (!direct || !direct[i])
		ft_error();
}

int	check_first_element(char **arry, int i)
{
	char	**str;

	if (size_of_arry(arry) <= 6)
		ft_error();
	while (arry && arry[++i] && i < 6)
	{
		str = ft_split(arry[i], ' ');
		if (size_of_arry(str) != 2)
			ft_error();
		chek_direction(str[0]);
		ft_free(str);
	}
}

int main()
{
	printf("444\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:30:14 by aelidrys          #+#    #+#             */
/*   Updated: 2023/06/08 06:02:44 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		free(str[i++]);
	free(str);
}

int	str_comp(char *s1, char *s2)
{
	size_t	x;

	x = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[x] && s2[x])
	{
		if (s1[x] != s2[x])
			return (0);
		x++;
	}
	if (s1[x] != s2[x])
		return (0);
	return (1);
}

int	size_of_arry(char **arry)
{
	int	size;

	size = 0;
	while (arry && arry[size])
		size++;
	return (size);
}

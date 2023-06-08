/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_parce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:27:39 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/08 09:53:43 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_cmp(char **map)
{
    int i;
    int j;
    int check;
    check = 0;
    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'N' || map[i][j] == 'S')
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
        ft_puterr("Error");
}
void check_cmp_valid(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'W' && map[i][j] != 'S' && map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != ' ')
            {
                ft_puterr("Error");
            }
            j++;
        }
        i++;
    }
}
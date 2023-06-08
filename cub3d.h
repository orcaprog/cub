/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:27:45 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/08 13:56:52 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

void	check_cmp(char **map);
void	ft_puterr(char *err);
void	check_cmp_valid(char **map);
char	**get_map(char *file);

// aelidrys
void	ft_free(char **str);
int		size_of_arry(char **arry);
int		str_comp(char *s1, char *s2);
int		check_first_element(char **arry, int i);
#endif
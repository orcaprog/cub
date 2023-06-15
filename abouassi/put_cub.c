/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:26:06 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/15 18:09:45 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

  
// typedef struct {
//     int x;
//     int y;
// } Point;

// Point findHorizontalIntersection(int Px, int Py, double ALPHA) {
//     Point A;
//     A.y = floor(Py / 64) * 64 - 1;
//     int grid_y = floor(A.y / 64);
//     int grid_x = floor((Px + (Py - A.y) / tan(ALPHA)) / 64);
//     A.x = grid_x * 64;
//     if (grid_y < 0) {
//         A.y = -1;  // Invalid y-coordinate if A is below the grid
//     }
//     return A;
// }

// int main() {
//     int Px = 96;
//     int Py = 224;
//     double ALPHA = 60.0;

//     Point A = findHorizontalIntersection(Px, Py, ALPHA);
//     printf("A.x: %d, A.y: %d\n", A.x, A.y);

//     return 0;
// }

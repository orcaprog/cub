/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:42:41 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/11 10:04:41 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int prm_moves(char **map,int x ,int y)
{
    printf("<<x = %d y = %d>>\n",x,y);
    if (map[y][x] == '1')
    {
        return (1);
    }
    return (0);
    
}
void    put_pix(t_info *cub,int i, int j,int color)
{
    mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 450 + i , 250 + j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 449 + i, 250+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 451 + i, 250+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 450 + i, 249+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 450 + i, 251+ j, color);
	
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 449 + i, 249+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 449 + i, 251+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 451 + i, 249+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 451 + i, 251+ j, color);

	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 448 + i, 250+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 452 + i, 250+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 450 + i, 248+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 450 + i, 252+ j, color);

	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 448 + i, 249+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 448 + i, 251+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 452 + i, 249+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 452 + i, 251+ j, color);

	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 449 + i, 248+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 451 + i, 248+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 449 + i, 252+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 451 + i, 252+ j, color);

	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 448 + i, 248+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 452 + i, 248+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 448 + i, 252+ j, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, 452 + i, 252+ j, color);
}
void    move_right(t_info *data)
{
    // int x = 0;
    // int y = 0;
    int check;
    check = 1;
    printf("right i = %d j = %d\n",data->i,data->j);
    if ((450 + data->i + 5) % 100 == 0)
    {
        printf("djjdjdj\n");
        if (prm_moves(data->map,((450 + data->i + 5) / 100),((250  + data->j )/ 100)))
        {
            check = 0;        
        }
    }
    if (check)
    {
        data->i += 5;
        put_pix(data,data->i - 5,data->j,0);
        put_pix(data,data->i,data->j,14753280);
    }
    // if ((445 + i) % 100 == 0)
    //     for (int a = (((250 + j) / 100) * 100) + 1; a % 100 != 0;a++)
    //         mlx_pixel_put(data->mlx->ptr,data->mlx->win,445+i,a,16777215);
    
}
void    move_left(t_info *data)
{
    // int x = 0;
    // int y = 0;
    int check;
    check = 1;
    printf("left i = %d j = %d\n",data->i,data->j);
    if ((455 + data->i - 5) % 100 == 0)
    {
        printf("djjdjdj\n");
        if (prm_moves(data->map,((450 + data->i - 5) / 100),((250  + data->j )/ 100)))
        {
            printf("enter\n");
            check = 0;        
        }
    }
    if (check)
    {
        data->i -= 5;
        put_pix(data,data->i + 5,data->j,0);
        put_pix(data,data->i,data->j,14753280);
    }
    
}
void    move_down(t_info *data)
{
    // int x = 0;
    // int y = 0;
    int check;
    check = 1;
    printf("down i = %d j = %d\n",data->i,data->j);
    if ((245 + data->j + 5) % 100 == 0)
    {
        printf("djjdjdj\n");
        if (prm_moves(data->map,((450 + data->i) / 100),((250  + data->j + 5)/ 100)))
        {
            printf("enter\n");
            check = 0;        
        }
    }
    if (check)
    {
        data->j += 5;
        put_pix(data,data->i ,data->j - 5,0);
        put_pix(data,data->i,data->j,14753280);
    }	
 
    
}
void    move_up(t_info *data)
{
    // int x = 0;
    // int y = 0;
    int check;
    check = 1;
    printf("up  i = %d j = %d\n",data->i,data->j);
    if ((255 + data->j - 5) % 100 == 0)
    {
        printf("djjdjdj\n");
        if (prm_moves(data->map,((450 + data->i) / 100),((250  + data->j -5 )/ 100)))
        {
            printf("enter\n");
            check = 0;        
        }
    }
    if (check)
    {
        data->j -= 5;
        put_pix(data,data->i,data->j + 5,0);
        put_pix(data,data->i,data->j,14753280);
    }   
}
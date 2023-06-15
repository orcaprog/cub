/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:42:41 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/15 18:09:41 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int prm_moves(char **map,int x ,int y)
{
     printf("|x = %d y = %d |\n",x ,y);
    
    if (map[y][x] == '1')
    {
        return (1);
    }
    return (0);
    
}

void    put_pix(t_info *cub, int color)
{
    mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  , cub->y, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  - 1, cub->y, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  + 1, cub->y, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x , cub->y - 1, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x , cub->y + 1, color);
	
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  - 1, cub->y - 1, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  - 1, cub->y + 1, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  + 1, cub->y - 1, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  + 1, cub->y + 1, color);
 
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  - 2, cub->y, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  + 2, cub->y, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x , cub->y - 2, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x , cub->y + 2, color);

	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  - 2, cub->y - 1, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  - 2, cub->y + 1, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  + 2, cub->y - 1, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  + 2, cub->y + 1, color);

	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  - 1, cub->y - 2, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  + 1, cub->y - 2, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  - 1, cub->y + 2, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  + 1, cub->y + 2, color);

	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  - 2, cub->y - 2, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  + 2, cub->y - 2, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  - 2, cub->y + 2, color);
	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, cub->x  + 2, cub->y + 2, color);
}
void    move_right(t_info *data)
{
    int check;
    check = 1;
     printf("<<x = %f y = %f>>\n",data->x + 5,data->y);
    if (((int)data->x  + 5) % 100 == 0)
    {
        if ((int)data->y % 100 == 0)
        {
            if (prm_moves(data->map,((data->x + 5) / 100),((data->y )/ 100)) || prm_moves(data->map,((data->x + 5) / 100),((data->y )/ 100) - 1))
                check = 0;
        }
        else if (prm_moves(data->map,((data->x + 5) / 100),((data->y )/ 100)))
        {
            check = 0;        
        }
    }
    if (check)
    {
        put_pix(data,0);
        data->x += 5;
        put_pix(data,14753280);
    }   
}
void    move_left(t_info *data)
{
    int check;
    check = 1;
     printf("<<x = %f y = %f>>\n",data->x - 5,data->y);

    if (((int)data->x - 5) % 100 == 0)
    {
        if ((int)data->y % 100 == 0){
            if (prm_moves(data->map,((data->x  - 5 - 1)  / 100),((data->y)/ 100))
                    || prm_moves(data->map,((data->x  - 5 - 1)  / 100),((data->y)/ 100) - 1))
                check = 0;
        }
        else if (prm_moves(data->map,((data->x  - 5 - 1)  / 100),((data->y)/ 100)))
            check = 0;        
    }
    if (check)
    {
        put_pix(data,0);
        data->x -= 5;
        put_pix(data,14753280);
    }
    
}
void    move_down(t_info *data)
{
    int check;
    check = 1;
     printf("<<x = %f y = %f>>\n",data->x ,data->y + 5);
    if (((int)data->y  + 5) % 100 == 0)
    {
        if ((int)data->x % 100 == 0)
        {
            if (prm_moves(data->map,((data->x ) / 100),((data->y  + 5)/ 100)) || prm_moves(data->map,((data->x ) / 100) - 1,((data->y  + 5)/ 100)))
                check = 0;
        }
        else if (prm_moves(data->map,((data->x ) / 100),((data->y  + 5)/ 100)))
        {
            check = 0;        
        }
    }
    if (check)
    {
        put_pix(data,0);
        data->y += 5;
        put_pix(data,14753280);
    }	
 
    
}
void    move_up(t_info *data)
{
    int check;
    check = 1;
     printf("<<x = %f y = %f>>\n",data->x ,data->y  - 5);

    if (((int)data->y  - 5) % 100 == 0)
    {
        if ((int)data->x % 100 == 0)
        {
            if (prm_moves(data->map,((data->x ) / 100),((data->y  - 5 - 1)/ 100)) || prm_moves(data->map,((data->x ) / 100) - 1,((data->y  - 5 - 1)/ 100)))
                check = 0;
        }
        else if (prm_moves(data->map,((data->x ) / 100),((data->y  - 5 - 1)/ 100)))
        {
            check = 0;        
        }
    }
    if (check)
    {
        put_pix(data,0);
        data->y -= 5;
        put_pix(data,14753280);
    }   
}
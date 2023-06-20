/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:42:41 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/20 15:50:11 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int prm_moves(char **map,int x ,int y)
{
    // printf("|x = %d y = %d |\n",x ,y);
    
    if (map[y][x] == '1')
    {
        return (1);
    }
    return (0);
    
}

void    put_pix(t_info *cub, int color)
{
      my_mlx_pixel_put(&cub->img[1], cub->x  , cub->y, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  - 1, cub->y, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  + 1, cub->y, color);
	my_mlx_pixel_put(&cub->img[1], cub->x , cub->y - 1, color);
	my_mlx_pixel_put(&cub->img[1], cub->x , cub->y + 1, color);
	
	my_mlx_pixel_put(&cub->img[1], cub->x  - 1, cub->y - 1, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  - 1, cub->y + 1, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  + 1, cub->y - 1, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  + 1, cub->y + 1, color);
 
	my_mlx_pixel_put(&cub->img[1], cub->x  - 2, cub->y, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  + 2, cub->y, color);
	my_mlx_pixel_put(&cub->img[1], cub->x , cub->y - 2, color);
	my_mlx_pixel_put(&cub->img[1], cub->x , cub->y + 2, color);

	my_mlx_pixel_put(&cub->img[1], cub->x  - 2, cub->y - 1, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  - 2, cub->y + 1, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  + 2, cub->y - 1, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  + 2, cub->y + 1, color);

	my_mlx_pixel_put(&cub->img[1], cub->x  - 1, cub->y - 2, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  + 1, cub->y - 2, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  - 1, cub->y + 2, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  + 1, cub->y + 2, color);

	my_mlx_pixel_put(&cub->img[1], cub->x  - 2, cub->y - 2, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  + 2, cub->y - 2, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  - 2, cub->y + 2, color);
	my_mlx_pixel_put(&cub->img[1], cub->x  + 2, cub->y + 2, color);
}
void    move_right(t_info *data)
{
    int check;
    check = 1;
    double	cor_rd;
   // cor_rd = (3.14159265359 * 90)/180.0000;
    cor_rd = ((3.14159265359 * (data->corner - 90))/180.0000);
     printf(" move right<<x = %f y = %f>>\n",data->x + cos(cor_rd) * 4,data->y - sin(cor_rd) * 4);
    // if ((int)(data->x + cos(cor_rd) * 4) % 100 == 0 || (int)(data->y - sin(cor_rd) * 4) % 100 == 0)
    // {
    //     if ((int)data->y % 100 == 0)
    //     {
    //         if (prm_moves(data->map,((data->x + 5) / 100),((data->y )/ 100)) || prm_moves(data->map,((data->x + 5) / 100),((data->y )/ 100) - 1))
    //             check = 0;
    //     }
    if (prm_moves(data->map,((data->x ) / 100),((data->y - sin(cor_rd) * 4)/ 100)))
    {
        check = 0;        
    }
    if (prm_moves(data->map,((data->x + cos(cor_rd) * 4) / 100),((data->y )/ 100)))
    {
        check = 0;        
    }
    // }
    if (check)
    {
        put_pix(data,0);
        data->x = data->x + cos(cor_rd) * 4;
       data->y = data->y - sin(cor_rd) * 4;
        put_pix(data,14753280);
    }   
}
void    move_left(t_info *data)
{
    int check;
    check = 1;
    double cor_rd;
    cor_rd = ((3.14159265359 * (data->corner + 90))/180.0000) ;
     printf(" move left <<x = %f y = %f>>\n",data->x + cos(cor_rd) * 4,data->y - sin(cor_rd) * 4);

    // if ((int)(data->x + cos(cor_rd) * 4) % 100 == 0 || (int)(data->y - sin(cor_rd) * 4) % 100 == 0)
    // {
    //     if ((int)data->y % 100 == 0){
    //         if (prm_moves(data->map,((data->x  - 5 - 1)  / 100),((data->y)/ 100))
    //                 || prm_moves(data->map,((data->x  - 5 - 1)  / 100),((data->y)/ 100) - 1))
    //             check = 0;
    //     }
    if (prm_moves(data->map,((data->x)  / 100),((data->y - sin(cor_rd) * 4)/ 100)))
        check = 0;    
    if (prm_moves(data->map,((data->x + cos(cor_rd) * 4)  / 100),((data->y )/ 100)))
        check = 0;        
    // }
    if (check)
    {
        put_pix(data,0);
        data->x = data->x + cos(cor_rd) * 4;
        data->y = data->y - sin(cor_rd) * 4;
        put_pix(data,14753280);
    }
    
}
void    move_down(t_info *data)
{
    int check;
    check = 1;
    double cor_rd;
    cor_rd = ((M_PI * data->corner)/180.0000);
     printf(" move down <<x = %f y = %f>>\n",data->x - cos(cor_rd) * 4 ,(data->y + sin(cor_rd) * 4));
    // if ((int)(data->y + sin(cor_rd) * 4) % 100 == 0 || (int)(data->x - cos(cor_rd) * 4) % 100 == 0)
    // {
    //     if ((int)data->x % 100 == 0)
    //     {
    //         if (prm_moves(data->map,((data->x ) / 100),((data->y  + 5)/ 100)) || prm_moves(data->map,((data->x ) / 100) - 1,((data->y  + 5)/ 100)))
    //             check = 0;
    //     }
        if (prm_moves(data->map,((data->x ) / 100),((data->y + sin(cor_rd) * 4)/ 100)))
        {
            check = 0;        
        }
        if (prm_moves(data->map,((data->x - cos(cor_rd) * 4) / 100),((data->y )/ 100)))
        {
            check = 0;        
        }
    if (check)
    {
        put_pix(data,0);
        data->y = data->y + sin(cor_rd) * 4;
        data->x = data->x - cos(cor_rd) * 4;
        put_pix(data,14753280);
    }	
 
    
}
void    move_up(t_info *data)
{
    int check;
    check = 1;
    double	cor_rd;
    cor_rd = (3.14159265359 * data->corner)/180.0000;
     printf("move up <<x = %f y = %f>>\n",data->x + cos(cor_rd) * 4 ,data->y - sin(cor_rd) * 4  );
     printf("mod  %d\n",(int)(data->y - sin(cor_rd) * 4) % 100);
    // if ((int)(data->y - sin(cor_rd) * 4) % 100 == 0  || (int)(data->x + cos(cor_rd) * 4) % 100 == 0)
    // {
    //     printf("enter here \n");
        // if ((int)data->x % 100 == 0)
        // {
        //     if (prm_moves(data->map,((data->x ) / 100),((data->y - sin(cor_rd) * 4 -1)/ 100) ) || prm_moves(data->map,((data->x ) / 100) - 1,((data->y  - 5 - 1)/ 100)))
        //         check = 0;
        // }
        if (prm_moves(data->map,((data->x) / 100),((data->y - sin(cor_rd) * 4)/ 100)))
        {
            check = 0;        
        }
       if (prm_moves(data->map,((data->x + cos(cor_rd) * 4) / 100),((data->y )/ 100)))
        {
            check = 0;        
        }
   // }
    if (check)
    {
        put_pix(data,0);
        data->y = data->y - sin(cor_rd) * 4;
        data->x = data->x + cos(cor_rd) * 4;
        put_pix(data,14753280);
    }   
}
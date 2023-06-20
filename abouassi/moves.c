/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:42:41 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/20 16:16:08 by abouassi         ###   ########.fr       */
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

void    put_pix(t_info *cub,t_data *img, int color)
{
    my_mlx_pixel_put(img, cub->x  , cub->y, color);
	my_mlx_pixel_put(img, cub->x  - 1, cub->y, color);
	my_mlx_pixel_put(img, cub->x  + 1, cub->y, color);
	my_mlx_pixel_put(img, cub->x , cub->y - 1, color);
	my_mlx_pixel_put(img, cub->x , cub->y + 1, color);
	
	my_mlx_pixel_put(img, cub->x  - 1, cub->y - 1, color);
	my_mlx_pixel_put(img, cub->x  - 1, cub->y + 1, color);
	my_mlx_pixel_put(img, cub->x  + 1, cub->y - 1, color);
	my_mlx_pixel_put(img, cub->x  + 1, cub->y + 1, color);
 
	my_mlx_pixel_put(img, cub->x  - 2, cub->y, color);
	my_mlx_pixel_put(img, cub->x  + 2, cub->y, color);
	my_mlx_pixel_put(img, cub->x , cub->y - 2, color);
	my_mlx_pixel_put(img, cub->x , cub->y + 2, color);

	my_mlx_pixel_put(img, cub->x  - 2, cub->y - 1, color);
	my_mlx_pixel_put(img, cub->x  - 2, cub->y + 1, color);
	my_mlx_pixel_put(img, cub->x  + 2, cub->y - 1, color);
	my_mlx_pixel_put(img, cub->x  + 2, cub->y + 1, color);

	my_mlx_pixel_put(img, cub->x  - 1, cub->y - 2, color);
	my_mlx_pixel_put(img, cub->x  + 1, cub->y - 2, color);
	my_mlx_pixel_put(img, cub->x  - 1, cub->y + 2, color);
	my_mlx_pixel_put(img, cub->x  + 1, cub->y + 2, color);

	my_mlx_pixel_put(img, cub->x  - 2, cub->y - 2, color);
	my_mlx_pixel_put(img, cub->x  + 2, cub->y - 2, color);
	my_mlx_pixel_put(img, cub->x  - 2, cub->y + 2, color);
	my_mlx_pixel_put(img, cub->x  + 2, cub->y + 2, color);
   //mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img->img, 0,0);
}
void    move_right(t_info *data)
{
    int check;
    check = 1;
    double	cor_rd;
   // cor_rd = (3.14159265359 * 90)/180.0000;
    cor_rd = ((3.14159265359 * (data->corner - 90))/180.0000);
     printf(" move right<<x = %f y = %f>>\n",data->x + cos(cor_rd) * 8,data->y - sin(cor_rd) * 8);
    // if ((int)(data->x + cos(cor_rd) * 8) % 100 == 0 || (int)(data->y - sin(cor_rd) * 8) % 100 == 0)
    // {
    //     if ((int)data->y % 100 == 0)
    //     {
    //         if (prm_moves(data->map,((data->x + 5) / 100),((data->y )/ 100)) || prm_moves(data->map,((data->x + 5) / 100),((data->y )/ 100) - 1))
    //             check = 0;
    //     }
    if (prm_moves(data->map,((data->x ) / 100),((data->y - sin(cor_rd) * 8)/ 100)))
    {
        check = 0;        
    }
    if (prm_moves(data->map,((data->x + cos(cor_rd) * 8) / 100),((data->y )/ 100)))
    {
        check = 0;        
    }
    // }
    if (check)
    {
        put_pix(data,&data->img[1],0x001637FF);
        data->x = data->x + cos(cor_rd) * 8;
       data->y = data->y - sin(cor_rd) * 8;
        put_pix(data,&data->img[1],14753280);
    }   
}
void    move_left(t_info *data)
{
    int check;
    check = 1;
    double cor_rd;
    cor_rd = ((3.14159265359 * (data->corner + 90))/180.0000) ;
     printf(" move left <<x = %f y = %f>>\n",data->x + cos(cor_rd) * 8,data->y - sin(cor_rd) * 8);

    // if ((int)(data->x + cos(cor_rd) * 8) % 100 == 0 || (int)(data->y - sin(cor_rd) * 8) % 100 == 0)
    // {
    //     if ((int)data->y % 100 == 0){
    //         if (prm_moves(data->map,((data->x  - 5 - 1)  / 100),((data->y)/ 100))
    //                 || prm_moves(data->map,((data->x  - 5 - 1)  / 100),((data->y)/ 100) - 1))
    //             check = 0;
    //     }
    if (prm_moves(data->map,((data->x)  / 100),((data->y - sin(cor_rd) * 8)/ 100)))
        check = 0;    
    if (prm_moves(data->map,((data->x + cos(cor_rd) * 8)  / 100),((data->y )/ 100)))
        check = 0;        
    // }
    if (check)
    {
        put_pix(data,&data->img[1],0x001637FF);
        data->x = data->x + cos(cor_rd) * 8;
        data->y = data->y - sin(cor_rd) * 8;
        put_pix(data,&data->img[1],14753280);
    }
    
}
void    move_down(t_info *data)
{
    int check;
    check = 1;
    double cor_rd;
    cor_rd = ((M_PI * data->corner)/180.0000);
     printf(" move down <<x = %f y = %f>>\n",data->x - cos(cor_rd) * 8 ,(data->y + sin(cor_rd) * 8));
    // if ((int)(data->y + sin(cor_rd) * 8) % 100 == 0 || (int)(data->x - cos(cor_rd) * 8) % 100 == 0)
    // {
    //     if ((int)data->x % 100 == 0)
    //     {
    //         if (prm_moves(data->map,((data->x ) / 100),((data->y  + 5)/ 100)) || prm_moves(data->map,((data->x ) / 100) - 1,((data->y  + 5)/ 100)))
    //             check = 0;
    //     }
        if (prm_moves(data->map,((data->x ) / 100),((data->y + sin(cor_rd) * 8)/ 100)))
        {
            check = 0;        
        }
        if (prm_moves(data->map,((data->x - cos(cor_rd) * 8) / 100),((data->y )/ 100)))
        {
            check = 0;        
        }
    if (check)
    {
        put_pix(data,&data->img[1],0x001637FF);
        data->y = data->y + sin(cor_rd) * 8;
        data->x = data->x - cos(cor_rd) * 8;
        put_pix(data,&data->img[1],14753280);
    }	
 
    
}
void    move_up(t_info *data)
{
    int check;
    check = 1;
    double	cor_rd;
    cor_rd = (3.14159265359 * data->corner)/180.0000;
     printf("move up <<x = %f y = %f>>\n",data->x + cos(cor_rd) * 8 ,data->y - sin(cor_rd) * 8  );
     printf("mod  %d\n",(int)(data->y - sin(cor_rd) * 8) % 100);
    // if ((int)(data->y - sin(cor_rd) * 8) % 100 == 0  || (int)(data->x + cos(cor_rd) * 8) % 100 == 0)
    // {
    //     printf("enter here \n");
        // if ((int)data->x % 100 == 0)
        // {
        //     if (prm_moves(data->map,((data->x ) / 100),((data->y - sin(cor_rd) * 8 -1)/ 100) ) || prm_moves(data->map,((data->x ) / 100) - 1,((data->y  - 5 - 1)/ 100)))
        //         check = 0;
        // }
        if (prm_moves(data->map,((data->x) / 100),((data->y - sin(cor_rd) * 8)/ 100)))
        {
            check = 0;        
        }
       if (prm_moves(data->map,((data->x + cos(cor_rd) * 8) / 100),((data->y )/ 100)))
        {
            check = 0;        
        }
   // }
    if (check)
    {
        put_pix(data,&data->img[1],0x001637FF);
        data->y = data->y - sin(cor_rd) * 8;
        data->x = data->x + cos(cor_rd) * 8;
        put_pix(data,&data->img[1],14753280);
    }   
}
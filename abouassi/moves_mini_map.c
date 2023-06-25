/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_mini_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:09:42 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/25 16:24:23 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"
void    move_right_mini(t_info *data)
{
    int check;
    check = 1;
    double	cor_rd;
   // cor_rd = (3.14159265359 * 90)/180.0000;
    cor_rd = ((3.14159265359 * (data->corner + 90))/180.0000);
    t_point	p1;
	t_point	p2;
	int k[2];
    double r;
    int grid = MOVE_SPEED;
    det_direction(data, cor_rd);
	p1 = det_coord_x(data, cor_rd,k);
	p2 = det_coord_y(data, cor_rd,k);
    r = p1.r;
	if ((p2.r) < (p1.r))
    {
        r = p2.r;
    }
    printf("r -------> %f\n",r);
    if (r <= 20)
    {
        check = 0;        
    }
    else if (20 > r - MOVE_SPEED)
        grid = r - 20;
     printf(" move right<<x = %f y = %f>>\n",data->x + cos(cor_rd) * MOVE_SPEED,data->y - sin(cor_rd) * MOVE_SPEED);
    // if ((int)(data->x + cos(cor_rd) * MOVE_SPEED) % 100 == 0 || (int)(data->y - sin(cor_rd) * MOVE_SPEED) % 100 == 0)
    // {
    //     if ((int)data->y % 100 == 0)
    //     {
    //         if (prm_moves(data->map,((data->x + 5) / 100),((data->y )/ 100)) || prm_moves(data->map,((data->x + 5) / 100),((data->y )/ 100) - 1))
    //             check = 0;
    //     }
    // if (prm_moves(data->map,((data->x ) / 100),((data->y - sin(cor_rd) * MOVE_SPEED)/ 100)))
    // {
    //     check = 0;        
    // }
    // if (prm_moves(data->map,((data->x + cos(cor_rd) * MOVE_SPEED) / 100),((data->y )/ 100)))
    // {
    //     check = 0;        
    // }
    // }
    if (check)
    {
    
        data->x = data->x + cos(cor_rd) * grid;
       data->y = data->y - sin(cor_rd) * grid;
        put_pix(data,data->big_img,14753280);
    }   
}
void     move_left_mini(t_info *data)
{
    int check;
    check = 1;
    double cor_rd;
    cor_rd = ((3.14159265359 * (data->corner - 90))/180.0000) ;
    t_point	p1;
	t_point	p2;
	int k[2];
    double r;
    int grid = MOVE_SPEED;
    det_direction(data, cor_rd);
	p1 = det_coord_x(data, cor_rd,k);
	p2 = det_coord_y(data, cor_rd,k);
    r = p1.r;
	if ((p2.r) < (p1.r))
    {
        r = p2.r;
    }
    printf("r -------> %f\n",r);
    if (r <= 20)
    {
        check = 0;        
    }
    else if (20 > r - MOVE_SPEED)
        grid = r - 20;
     printf(" move left <<x = %f y = %f>>\n",data->x + cos(cor_rd) * MOVE_SPEED,data->y - sin(cor_rd) * MOVE_SPEED);

    // if ((int)(data->x + cos(cor_rd) * MOVE_SPEED) % 100 == 0 || (int)(data->y - sin(cor_rd) * MOVE_SPEED) % 100 == 0)
    // {
    //     if ((int)data->y % 100 == 0){
    //         if (prm_moves(data->map,((data->x  - 5 - 1)  / 100),((data->y)/ 100))
    //                 || prm_moves(data->map,((data->x  - 5 - 1)  / 100),((data->y)/ 100) - 1))
    //             check = 0;
    //     }
    // if (prm_moves(data->map,((data->x)  / 100),((data->y - sin(cor_rd) * MOVE_SPEED)/ 100)))
    //     check = 0;    
    // if (prm_moves(data->map,((data->x + cos(cor_rd) * MOVE_SPEED)  / 100),((data->y )/ 100)))
    //     check = 0;        
    // }
    if (check)
    {

        data->x = data->x + cos(cor_rd) * grid;
        data->y = data->y - sin(cor_rd) * grid;
        put_pix(data,data->big_img,14753280);
    }
    
}
void    move_down_mini(t_info *data)
{
    int check;
    check = 1;
    double cor_rd;
    cor_rd = ((M_PI * (data->corner - 180))/180.0000);
    t_point	p1;
	t_point	p2;
	int k[2];
    double r;
    int grid = MOVE_SPEED;
    det_direction(data, cor_rd);
	p1 = det_coord_x(data, cor_rd,k);
	p2 = det_coord_y(data, cor_rd,k);
    r = p1.r;
	if ((p2.r) < (p1.r))
    {
        r = p2.r;
    }
    printf("r -------> %f\n",r);
    if (r <= 20)
        check = 0; 
    else if (20 > r - MOVE_SPEED)
        grid = r - 20;
    printf(" move down <<x = %f y = %f>>\n",data->x + cos(cor_rd) * grid ,(data->y - sin(cor_rd) * grid));
    // if ((int)(data->y + sin(cor_rd) * MOVE_SPEED) % 100 == 0 || (int)(data->x - cos(cor_rd) * MOVE_SPEED) % 100 == 0)
    // {
    //     if ((int)data->x % 100 == 0)
    //     {
    //         if (prm_moves(data->map,((data->x ) / 100),((data->y  + 5)/ 100)) || prm_moves(data->map,((data->x ) / 100) - 1,((data->y  + 5)/ 100)))
    //             check = 0;
    //     }
        // if (prm_moves(data->map,((data->x ) / 100),((data->y + sin(cor_rd) * MOVE_SPEED)/ 100)))
        // {
        //     check = 0;        
        // }
        // if (prm_moves(data->map,((data->x - cos(cor_rd) * MOVE_SPEED) / 100),((data->y )/ 100)))
        // {
        //     check = 0;        
        // }
    if (check)
    {
  
        data->y = data->y - sin(cor_rd) * grid;
        data->x = data->x + cos(cor_rd) * grid;
        put_pix(data,data->big_img,14753280);
    }	
 
    
}
void    move_up_mini(t_info *data)
{
    int check;
    check = 1;
    double	cor_rd;
    cor_rd = (3.14159265359 * data->corner)/180.0000;
     printf("move up <<x = %f y = %f>>\n",data->x + cos(cor_rd) * MOVE_SPEED ,data->y - sin(cor_rd) * MOVE_SPEED  );
    t_point	p1;
	t_point	p2;
	int k[2];
    double r;
    int grid = MOVE_SPEED;
    det_direction(data, cor_rd);
	p1 = det_coord_x(data, cor_rd,k);
	p2 = det_coord_y(data, cor_rd,k);
    r = p1.r;
	if ((p2.r) < (p1.r))
    {
        r = p2.r;
    }
    printf("r -------> %f\n",r);
    if (r <= 20)
    {
        check = 0;        
    }
    else if (20 > r - MOVE_SPEED)
        grid = r - 20;
    // if ((int)(data->y - sin(cor_rd) * MOVE_SPEED) % 100 == 0  || (int)(data->x + cos(cor_rd) * MOVE_SPEED) % 100 == 0)
    // {
    //     printf("enter here \n");
        // if ((int)data->x % 100 == 0)
        // {
        //     if (prm_moves(data->map,((data->x ) / 100),((data->y - sin(cor_rd) * MOVE_SPEED -1)/ 100) ) || prm_moves(data->map,((data->x ) / 100) - 1,((data->y  - 5 - 1)/ 100)))
        //         check = 0;
        // }
    //     if (prm_moves(data->map,((data->x) / 100),((data->y - sin(cor_rd) * MOVE_SPEED)/ 100)))
    //     {
    //         check = 0;        
    //     }
    //    if (prm_moves(data->map,((data->x + cos(cor_rd) * MOVE_SPEED) / 100),((data->y )/ 100)))
    //     {
    //         check = 0;        
    //     }
   // }
    if (check)
    {
      
        data->y = data->y - sin(cor_rd) * grid;
        data->x = data->x + cos(cor_rd) * grid;
        put_pix(data,data->big_img,14753280);
    }   
}
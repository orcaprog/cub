/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:42:41 by abouassi          #+#    #+#             */
/*   Updated: 2023/07/13 11:35:22 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	det_distance_r_m(t_point *p, t_info *cub)
// {
// 	p->r = sqrt(pow((cub->x - p->x),2) + pow((cub->y - p->y),2));
// 	if (p->r == -2147483648)
// 		p->r = p->r + 1 * -1;
// }

// t_point		wall_x(t_info *cub, double cor_rd)
// {
// 	t_point	p;

// 		if (cub->y_d == 1)
// 		{
// 			p.y = (floor(p.y / 100) * 100) + 100;
// 			p.x = cub->x - ((p.y - cub->y) / tan(cor_rd));
// 			// if ((int)p.x % 100 >= 98)
// 			// 	p.x = (floor(p.x / 100) * 100) + 100;
// 		}
// 		if (cub->y_d == -1)
// 		{

// 			p.y -= 100;
// 			p.x = cub->x + ((cub->y - p.y) / tan(cor_rd));
// 		}
//         det_distance_r_m(&p,cub);
// 	return (p);
// }
int prm_moves(char **map,int x ,int y)
{
    // printf("|x = %d y = %d |\n",x ,y);
    
    if (map[y][x] == '1')
    {
        return (1);
    }
    return (0);
    
}

// void    put_pix(t_info *cub,t_img*img, int color)
// {
//     my_mlx_pixel_put(img, cub->mini_x  , cub->mini_y, color);
// 	my_mlx_pixel_put(img, cub->mini_x  - 1, cub->mini_y, color);
// 	my_mlx_pixel_put(img, cub->mini_x  + 1, cub->mini_y, color);
// 	my_mlx_pixel_put(img, cub->mini_x , cub->mini_y - 1, color);
// 	my_mlx_pixel_put(img, cub->mini_x , cub->mini_y + 1, color);
	
// 	my_mlx_pixel_put(img, cub->mini_x  - 1, cub->mini_y - 1, color);
// 	my_mlx_pixel_put(img, cub->mini_x  - 1, cub->mini_y + 1, color);
// 	my_mlx_pixel_put(img, cub->mini_x  + 1, cub->mini_y - 1, color);
// 	my_mlx_pixel_put(img, cub->mini_x  + 1, cub->mini_y + 1, color);
 
// 	my_mlx_pixel_put(img, cub->mini_x  - 2, cub->mini_y, color);
// 	my_mlx_pixel_put(img, cub->mini_x  + 2, cub->mini_y, color);
// 	my_mlx_pixel_put(img, cub->mini_x , cub->mini_y - 2, color);
// 	my_mlx_pixel_put(img, cub->mini_x , cub->mini_y + 2, color);

// 	my_mlx_pixel_put(img, cub->mini_x  - 2, cub->mini_y - 1, color);
// 	my_mlx_pixel_put(img, cub->mini_x  - 2, cub->mini_y + 1, color);
// 	my_mlx_pixel_put(img, cub->mini_x  + 2, cub->mini_y - 1, color);
// 	my_mlx_pixel_put(img, cub->mini_x  + 2, cub->mini_y + 1, color);

// 	my_mlx_pixel_put(img, cub->mini_x  - 1, cub->mini_y - 2, color);
// 	my_mlx_pixel_put(img, cub->mini_x  + 1, cub->mini_y - 2, color);
// 	my_mlx_pixel_put(img, cub->mini_x  - 1, cub->mini_y + 2, color);
// 	my_mlx_pixel_put(img, cub->mini_x  + 1, cub->mini_y + 2, color);

// 	my_mlx_pixel_put(img, cub->mini_x  - 2, cub->mini_y - 2, color);
// 	my_mlx_pixel_put(img, cub->mini_x  + 2, cub->mini_y - 2, color);
// 	my_mlx_pixel_put(img, cub->mini_x  - 2, cub->mini_y + 2, color);
// 	my_mlx_pixel_put(img, cub->mini_x  + 2, cub->mini_y + 2, color);
//    //mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img->img, 0,0);
// }
void    move_right(t_info *data,int size)
{
    int check;
    check = 1;
    double	cor_rd;
   // cor_rd = (3.14159265359 * 90)/180.0000;
    cor_rd = ((3.14159265359 * (data->corner + 90))/180.0000);
    t_point	p1;
	t_point	p2;
    double r;
    int grid = MOVE_SPEED;
    det_direction(data, cor_rd);
	p1 = det_coord_x(data, cor_rd,0,size);
	p2 = det_coord_y(data, cor_rd,0,size);
    r = p1.r;
	if ((p2.r) < (p1.r))
    {
        r = p2.r;
    }
    printf("r --> %f     cor ---> %lf\n",r,data->corner);
    if (r <= 20)
    {
        check = 0;        
    }
    else if (20 > r - MOVE_SPEED)
        grid = r - 20;
     printf(" move right<<x = %f y = %f>>\n",data->x + cos(cor_rd) * MOVE_SPEED,data->y - sin(cor_rd) * MOVE_SPEED);
    if (check)
    {
    
        
        data->x = data->x + cos(cor_rd) * grid;
        data->y = data->y - sin(cor_rd) * grid;
        
       // put_pix(data,data->big_img,14753280);
     //mini_move_right(data,grid ,check,cor_rd);
    } 
}
void    move_left(t_info *data,int size)
{
    int check;
    check = 1;
    double cor_rd;
    cor_rd = ((3.14159265359 * (data->corner - 90))/180.0000) ;
    t_point	p1;
	t_point	p2;
    double r;
    int grid = MOVE_SPEED;
    det_direction(data, cor_rd);
	p1 = det_coord_x(data, cor_rd,0,size);
	p2 = det_coord_y(data, cor_rd,0,size);
    r = p1.r;
	if ((p2.r) < (p1.r))
    {
        r = p2.r;
    }
    printf("r --> %f     cor ---> %lf\n",r,data->corner);
    if (r <= 20)
    {
        check = 0;        
    }
    else if (20 > r - MOVE_SPEED)
        grid = r - 20;
     printf(" move left <<x = %f y = %f>>\n",data->x + cos(cor_rd) * MOVE_SPEED,data->y - sin(cor_rd) * MOVE_SPEED);

    if (check)
    {
        
        data->x = data->x + cos(cor_rd) * grid;
        data->y = data->y - sin(cor_rd) * grid;
        
       // put_pix(data,data->big_img,14753280);
    //mini_move_left(data,grid,check,cor_rd);
    }
    
}
void    move_down(t_info *data,int size)
{
    int check;
    check = 1;
    double cor_rd;
    cor_rd = ((M_PI * (data->corner - 180))/180.0000);
    t_point	p1;
	t_point	p2;
    double r;
    int grid = MOVE_SPEED;
    det_direction(data, cor_rd);
	p1 = det_coord_x(data, cor_rd,0,size);
	p2 = det_coord_y(data, cor_rd,0,size);
    r = p1.r;
	if ((p2.r) < (p1.r))
    {
        r = p2.r;
    }
   printf("r --> %f     cor ---> %lf\n",r,data->corner);
    if (r <= 20)
        check = 0; 
    else if (20 > r - MOVE_SPEED)
        grid = r - 20;

    if (check)
    {
        
        data->y = data->y - sin(cor_rd) * grid;
        data->x = data->x + cos(cor_rd) * grid;
        data->map[(int)(data->y/100)][(int)(data->x / 100)] = 'N';

       // put_pix(data,data->big_img,14753280);
    //mini_move_down(data,grid ,check,cor_rd);
    }
    
}
void    move_up(t_info *data,int size)
{
    int check;
    check = 1;
    double	cor_rd;
    cor_rd = (3.14159265359 * data->corner)/180.0000;
    // printf("move up <<x = %f y = %f>>\n",data->x + cos(cor_rd) * MOVE_SPEED ,data->y - sin(cor_rd) * MOVE_SPEED  );
    t_point	p1;
	t_point	p2;
    double r;
    int grid = MOVE_SPEED;
    det_direction(data, cor_rd);
	p1 = det_coord_x(data, cor_rd,0,size);
	p2 = det_coord_y(data, cor_rd,0,size);
    r = p1.r;
	if ((p2.r) < (p1.r))
    {
        r = p2.r;
    }
   printf("r --> %f     cor ---> %lf\n",r,data->corner);
    if (r <= 20)
    {
        check = 0;        
    }
    else if (20 > r - MOVE_SPEED)
        grid = r - 20;

    if (check)
    {
        
        data->y = data->y - sin(cor_rd) * grid;
        data->x = data->x + cos(cor_rd) * grid;
        
       // put_pix(data,data->big_img,14753280);
    //mini_move_up(data,grid ,check,cor_rd);
    }
}
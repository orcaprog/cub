/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 08:13:25 by abouassi          #+#    #+#             */
/*   Updated: 2023/07/13 12:23:54 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    put_pix_mini(t_img*img, double x,double y,int color)
{
	double i, j;
	// printf("x %d\n",x);
	// printf("y %d\n",y);
	i = y;
    while(i < y + MINI_GRID)
	{
		j = x;
		while(j < x + MINI_GRID)
		{
			my_mlx_pixel_put(img,j,i ,color);
			j++;
		}
		i++;
	}
   //mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->img->img, 0,0);
}
int	a_event1(int key, t_info *cub)
{
	input_key(key, cub);
	// mlx_clear_window(cub->mlx->ptr, cub->mlx->win);
	draw_mini_map(cub);
	if ((int)cub->corner == 360)
		cub->corner = 0;
	if (key == 124)
	{
		cub->corner+=10;
		// mlx_clear_window(cub->mlx->ptr, cub->mlx->win);
		draw_mini_map(cub);
	}
	if (key == 123)
	{
		cub->corner-=10;
		// mlx_clear_window(cub->mlx->ptr, cub->mlx->win);
		draw_mini_map(cub);
	}
	return (0);
}
void draw_myray(t_info *cub,double corner)
{
	int r;
	double cor_rd;
	double x;
	double y;
	cor_rd = ((M_PI * corner)/180.0000);
	x = (175 );
	y = (105);
	r = 0;
	// printf("x /30 %f\n",x / 14);
	// printf("y /30 %f\n",y / 14);
	while (r <= 20 )
	{
		my_mlx_pixel_put(cub->mini_img,  x, y, 0x00FDFD96);
		x = x + cos(cor_rd) ;
		y = y  - sin(cor_rd) ;
		r++;
	}
	
}
void draw_mini_ray(t_info  *cub)
{
	double cor_l;
	double cor_r;

	cor_l = cub->corner - 30;
	cor_r = cub->corner + 30;
	while (cor_l <= cor_r)
	{

		draw_myray(cub,cor_l);
		cor_l++;
	}
	
	
}
void	my_mlx_pixel_put(t_img*data, int x, int y, int color)
{
	char	*dst;
	if (x >= 350 || y >= 210)
		return ;
	//printf("(%d,%d)\n",x,y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void print_image_square( t_info *data,int x, int y,int color)
{
    int i, j;
	// printf("x %d\n",x);
	// printf("y %d\n",y);
	i = y;
    while(i < y + MINI_GRID )
	{
		j = x;
		while(j < x + MINI_GRID)
		{
			my_mlx_pixel_put(data->mini_img,j,i ,color);
			j++;
		}
		i++;
	}
}

void	draw_mini_map(t_info *cub)
{
	int x = 0;
	int y = 0;
	int  start_x;
	int 	end_x;
	int  start_y;
	int end_y;
	int org_x = cub->x/ 100;
	int org_y = cub->y/ 100;
	printf("%d				-> original x----->%f\n",org_x,cub->x/ 100);
	printf("%d				-> original y----->%f\n",org_y,cub->y/ 100);
	start_x = org_x - 12;
	start_y = org_y - 7;
	end_x = org_x + 12;
	end_y = org_y + 7;

	printf("%d				-> start_x\n",start_x);
	printf("%d				-> start_y\n",start_y);
	printf("%d				-> end_x\n",end_x);
	printf("%d				-> end_y\n",end_y);
	y = start_y;

	while(y <= end_y )
	{
		
		x = start_x;
		while(x <= end_x )
		{
			if((y >= 0 &&  y < size_of_arry(cub->map) && x <= ft_strlen(cub->map[y]) && x >= 0))
			{
				if ( cub->map[y][x] == '1'  )
					print_image_square(cub,(x - start_x)* MINI_GRID,(y - start_y) * MINI_GRID,0x00F5F5DC);
				else if ( (cub->map[y][x] == '0' || cub->map[y][x] == 'N'|| cub->map[y][x] == 'W'|| cub->map[y][x] == 'S'|| cub->map[y][x] == 'E') )
					print_image_square(cub,(x - start_x)* MINI_GRID,(y - start_y) * MINI_GRID,0x00708090);
				else if (cub->map[y][x] == 'D')
					print_image_square(cub,(x - start_x)* MINI_GRID,(y - start_y) * MINI_GRID,0x000000CD);
				else
					print_image_square(cub,(x - start_x)* MINI_GRID,(y - start_y) * MINI_GRID,0x00FF000080);	
			}
			else
				print_image_square(cub,(x - start_x)* MINI_GRID,(y - start_y) * MINI_GRID,0x00FF000080);
			x++;
		}
		(y++);
	}

	draw_mini_ray(cub);

	put_pix_mini(cub->mini_img,175 - MINI_GRID / 2,105 -MINI_GRID / 2,0x00FF7F50);


	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, cub->mini_img->ptr, 0,0);

	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:55:47 by abouassi          #+#    #+#             */
/*   Updated: 2023/06/20 20:57:53 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
|
|
|
|
>   ban lia ba9aw ghir chi chwia mo9ranatan m3a l9dim 
hada wzdt varible d fi struct


*/





void	draw_ray(t_info *cub, int ri, int rf, int color)
{
	double	x;
	double	y;
	double	cor_rd;
	t_point	p1;
	t_point	p2;
	int k[2];

	ri = 0;
	(void)color;
	cor_rd = (M_PI * cub->r_corner)/180.0000;
	det_direction(cub, cor_rd);
	p1 = det_coord_x(cub, cor_rd,k);
	p2 = det_coord_y(cub, cor_rd,k);
	// printf("r1 = %lf  r2 = %lf\n",p1.r,p2.r);
	if (p1.r > p2.r){
		cub->d = 1;
		p1.r = p2.r;
	}
	else if (p1.r < p2.r){
		cub->d = 0;
	}
	else 
	{
		p1.r = cub->last_r;
		
	}
	cub->last_r = p1.r;
	rf = p1.r;
	x = cub->x + 5 * cos(cor_rd);
	y = cub->y - 5 * sin(cor_rd);
	// printf("----p1(%lf,%lf]) ----\n",p1.x,p1.y);
	// printf("\n----p2(%lf,%lf]) ----\n",p2.x,p2.y);
	// printf("$$$$p.r = %lf && RF = %d$$$$\n++++++++++++++\n",p1.r,rf);
	// while (ri < rf)
	// {
	// 	mlx_pixel_put(cub->mlx->ptr, cub->mlx->win, x, y, color);
	// 	x += cos(cor_rd);
	// 	y -= sin(cor_rd);
	// 	ri = sqrt(pow(floor(cub->x - x),2) + pow(floor(cub->y - y),2));
	// }
	//2463422 blue
	//8403230 maron
	//14605267 gree
	y=250;
	printf("%d\n",cub->d);
	double a = (500/(p1.r*fabs(cos(((cub->r_corner-cub->corner)*M_PI)/180))))*50;
	if (a > 250)
		a = 250;
	for (int i = 0;i<y-a;i++){
		my_mlx_pixel_put(&cub->img[0], cub->width, y-a-i, 2463422);
		my_mlx_pixel_put(&cub->img[0], cub->width, y+a+i, 8011295);
	}
	if (sin(cor_rd)>0 && cub->d == 0){
		for (int i = 0;i<a;i++){
			my_mlx_pixel_put(&cub->img[0], cub->width, y+i, 14605267);
			my_mlx_pixel_put(&cub->img[0], cub->width, y-i, 14605267);
		}
	}
	else if (sin(cor_rd)<0 && cub->d == 0){
		for (int i = 0;i<a;i++){
			my_mlx_pixel_put(&cub->img[0], cub->width, y+i, 14605267);
			my_mlx_pixel_put(&cub->img[0], cub->width, y-i, 14605267);
		}
	}
	else if (cos(cor_rd)>0 && cub->d == 1){
		for (int i = 0;i<a;i++){
			my_mlx_pixel_put(&cub->img[0], cub->width, y+i, 10723998);
			my_mlx_pixel_put(&cub->img[0], cub->width, y-i, 10723998);
		}
	}
	else{
		for (int i = 0;i<a;i++){
			my_mlx_pixel_put(&cub->img[0], cub->width, y+i, 10723998);
			my_mlx_pixel_put(&cub->img[0], cub->width, y-i, 10723998);
		}
	}
}
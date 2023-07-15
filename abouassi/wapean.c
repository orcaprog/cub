/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wapean.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:21:39 by abouassi          #+#    #+#             */
/*   Updated: 2023/07/15 16:21:31 by abouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int	draw_wapeans(t_info *cub)
{
	if (!cub->check_shot && cub->change_wap == 0)
		draw_wap(cub,cub->mlx->i_w0,400,600);
	else if (!cub->check_shot && cub->change_wap == 1)
		draw_wap(cub,cub->mlx->k_0,400,600);
	if (cub->check_shot)
	{
		cub->numb_shot++;
		if (cub->change_wap == 0)
			put_pistol(cub);
		else if (cub->change_wap == 1)
			put_knife(cub);
		if (cub->numb_shot == 3000)
		{
			cub->numb_shot = 0;
			cub->check_shot = 0;
		}
	}
	return (0);
}

void	get_xpm_file(t_info *cub)
{
	int	h;
	int	w;

	cub->mlx->i_w0 = mlx_xpm_file_to_image(cub->mlx->ptr, "w/p_0.xpm", &w, &h);
	cub->mlx->i_w1 = mlx_xpm_file_to_image(cub->mlx->ptr, "w/p_1.xpm", &w, &h);
	cub->mlx->i_w2 = mlx_xpm_file_to_image(cub->mlx->ptr, "w/p_2.xpm", &w, &h);
	cub->mlx->i_w3 = mlx_xpm_file_to_image(cub->mlx->ptr, "w/p_3.xpm", &w, &h);
	cub->mlx->i_c = mlx_xpm_file_to_image(cub->mlx->ptr, "w/icn.xpm", &w, &h);
	cub->mlx->i_c1 = mlx_xpm_file_to_image(cub->mlx->ptr, "w/icn1.xpm", &w, &h);
	cub->mlx->k_0 = mlx_xpm_file_to_image(cub->mlx->ptr, "w/k_0.xpm", &w, &h);
	cub->mlx->k_1 = mlx_xpm_file_to_image(cub->mlx->ptr, "w/k_1.xpm", &w, &h);
	cub->mlx->k_2 = mlx_xpm_file_to_image(cub->mlx->ptr, "w/k_2.xpm", &w, &h);
	cub->mlx->k_3 = mlx_xpm_file_to_image(cub->mlx->ptr, "w/k_3.xpm", &w, &h);
	cub->mlx->p_s = mlx_xpm_file_to_image(cub->mlx->ptr, "w/p_s.xpm", &w, &h);
}

void	change_wap(t_info *cub)
{
	if (cub->change_wap == 0)
	{
		mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win,
			cub->mlx->i_c, 1000, 0);
	}
	if (cub->change_wap == 1)
	{
		mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win,
			cub->mlx->i_c1, 1000, 0);
	}
}

void	draw_wap(t_info *cub, void *img, int x, int y)
{
	draw_simple_map(cub);
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->win, img, x, y);
}

void	put_pistol(t_info *cub)
{
	if (cub->numb_shot == 1)
		draw_wap(cub, cub->mlx->i_w1, 400, 600);
	if (cub->numb_shot == 500)
		draw_wap(cub, cub->mlx->i_w2, 400, 600);
	if (cub->numb_shot == 1000)
		draw_wap(cub, cub->mlx->i_w3, 400, 600);
	if (cub->numb_shot == 1500)
		draw_wap(cub, cub->mlx->i_w3, 400, 600);
	if (cub->numb_shot == 2500)
		draw_wap(cub, cub->mlx->i_w1, 400, 600);
	if (cub->numb_shot == 3000)
		draw_wap(cub, cub->mlx->i_w0, 400, 600);
}

void	put_knife(t_info *cub)
{
	if (cub->numb_shot == 1)
		draw_wap(cub, cub->mlx->k_1, 400, 600);
	if (cub->numb_shot == 500)
		draw_wap(cub, cub->mlx->k_2, 400, 600);
	if (cub->numb_shot == 1000)
		draw_wap(cub, cub->mlx->k_3, 400, 600);
	if (cub->numb_shot == 1500)
		draw_wap(cub, cub->mlx->k_3, 400, 600);
	if (cub->numb_shot == 2500)
		draw_wap(cub, cub->mlx->k_1, 400, 600);
	if (cub->numb_shot == 3000)
		draw_wap(cub, cub->mlx->k_0, 400, 600);
}

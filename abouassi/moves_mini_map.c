// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   moves_mini_map.c                                   :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: abouassi <abouassi@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/06/25 10:09:42 by abouassi          #+#    #+#             */
// /*   Updated: 2023/07/12 19:11:37 by abouassi         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */


// #include "../cub3d.h"
// void    mini_move_right(t_info *data,int m_grid ,int check,double cor_rd)
// {
//     // int check;
//     // check = 1;
//     // double	cor_rd;
// //    // cor_rd = (3.14159265359 * 90)/180.0000;
// //     cor_rd = ((3.14159265359 * (data->corner + 90))/180.0000);
// //     t_point	p1;
// // 	t_point	p2;
// //     double r;
// //     // grid ----> 100
// //     // m_grid --> MINI_GRID
//       printf("grid        ->%d\ncheck       ->%d\n",m_grid,check);// m_grid = MINI_GRID * grid / 100
//     m_grid = (m_grid * MINI_GRID / data->size) ;
//     // det_direction(data, cor_rd);
// 	// p1 = det_coord_x(data, cor_rd,0,size);
// 	// p2 = det_coord_y(data, cor_rd,0,size);
//     // r = p1.r;
// 	// if ((p2.r) < (p1.r))
//     // {
//     //     r = p2.r;
//     // }
//     // printf("r -------> %f\n",r);
//     // if (r <= 20)
//     // {
//     //     check = 0;        
//     // }
//     // else if (20 > r - (MOVE_SPEED * size / data->size))
//     //     grid = (r - MOVE_SPEED) * size / data->size;
//     //  printf(" move right<<x = %f y = %f>>\n",data->mini_x + cos(cor_rd) * (MOVE_SPEED * size / data->size),data->mini_y - sin(cor_rd) * (MOVE_SPEED * size / data->size));
//     // if ((int)(data->mini_x + cos(cor_rd) * (MOVE_SPEED * size / data->size)) % 100 == 0 || (int)(data->mini_y - sin(cor_rd) * (MOVE_SPEED * size / data->size)) % 100 == 0)
//     // {
//     //     if ((int)data->mini_y % 100 == 0)
//     //     {
//     //         if (prm_moves(data->map,((data->mini_x + 5) / 100),((data->mini_y )/ 100)) || prm_moves(data->map,((data->mini_x + 5) / 100),((data->mini_y )/ 100) - 1))
//     //             check = 0;
//     //     }
//     // if (prm_moves(data->map,((data->mini_x ) / 100),((data->mini_y - sin(cor_rd) * (MOVE_SPEED * size / data->size))/ 100)))
//     // {
//     //     check = 0;        
//     // }
//     // if (prm_moves(data->map,((data->mini_x + cos(cor_rd) * (MOVE_SPEED * size / data->size)) / 100),((data->mini_y )/ 100)))
//     // {
//     //     check = 0;        
//     // }
//     // }
//     printf("m_grid        ->%d\n",m_grid);
//     if (check)
//     {
    
//         data->mini_x = data->mini_x + cos(cor_rd) * m_grid;
//        data->mini_y = data->mini_y - sin(cor_rd) * m_grid;
//        //put_pix(data,data->big_img,14753280);
//     }   
// }
// void    mini_move_left(t_info *data,int m_grid ,int check,double cor_rd)
// {
//     // int check;
//     // check = 1;
//     // double cor_rd;
//     // cor_rd = ((3.14159265359 * (data->corner - 90))/180.0000) ;
//     // t_point	p1;
// 	// t_point	p2;
//     // double r;
//     // int grid = (MOVE_SPEED * size / data->size);
//     // det_direction(data, cor_rd);
// 	// p1 = det_coord_x(data, cor_rd,0,size);
// 	// p2 = det_coord_y(data, cor_rd,0,size);
//     // r = p1.r;
// 	// if ((p2.r) < (p1.r))
//     // {
//     //     r = p2.r;
//     // }
//     // printf("r -------> %f\n",r);
//     // if (r <= 20)
//     // {
//     //     check = 0;        
//     // }
//     // else if (20 > r - (MOVE_SPEED * size / data->size))
//     //     grid = r - 20;
//     //  //printf(" move left <<x = %f y = %f>>\n",data->mini_x + cos(cor_rd) * (MOVE_SPEED * size / data->size),data->mini_y - sin(cor_rd) * (MOVE_SPEED * size / data->size));

//     // // if ((int)(data->mini_x + cos(cor_rd) * (MOVE_SPEED * size / data->size)) % 100 == 0 || (int)(data->mini_y - sin(cor_rd) * (MOVE_SPEED * size / data->size)) % 100 == 0)
//     // // {
//     // //     if ((int)data->mini_y % 100 == 0){
//     // //         if (prm_moves(data->map,((data->mini_x  - 5 - 1)  / 100),((data->mini_y)/ 100))
//     // //                 || prm_moves(data->map,((data->mini_x  - 5 - 1)  / 100),((data->mini_y)/ 100) - 1))
//     // //             check = 0;
//     // //     }
//     // // if (prm_moves(data->map,((data->mini_x)  / 100),((data->mini_y - sin(cor_rd) * (MOVE_SPEED * size / data->size))/ 100)))
//     // //     check = 0;    
//     // // if (prm_moves(data->map,((data->mini_x + cos(cor_rd) * (MOVE_SPEED * size / data->size))  / 100),((data->mini_y )/ 100)))
//     printf("grid        ->%d\ncheck       ->%d\n",m_grid,check);// //     check = 0;        
//     m_grid = (m_grid * MINI_GRID / data->size) ;
//     // }
//     printf("m_grid        ->%d\n",m_grid);

//     if (check)
//     {

//         data->mini_x = data->mini_x + cos(cor_rd) * m_grid;
//         data->mini_y = data->mini_y - sin(cor_rd) * m_grid;
//     //    put_pix(data,data->big_img,14753280);
//     }
    
// }
// void    mini_move_down(t_info *data,int m_grid ,int check,double cor_rd)
// {
// //     int check;
// //     check = 1;
// //     double cor_rd;
// //     cor_rd = ((M_PI * (data->corner - 180))/180.0000);
// //     t_point	p1;
// // 	t_point	p2;
// //     double r;
// //     int grid = (MOVE_SPEED * size / data->size);
// //     det_direction(data, cor_rd);
// // 	p1 = det_coord_x(data, cor_rd,0,size);
// // 	p2 = det_coord_y(data, cor_rd,0,size);
// //     r = p1.r;
// // 	if ((p2.r) < (p1.r))
// //     {
// //         r = p2.r;
// //     }
// //    // printf("r -------> %f\n",r);
// //     if (r <= 20)
// //         check = 0; 
// //     else if (20 > r - (MOVE_SPEED * size / data->size))
// //         grid = r - 20;
//     //printf(" move down <<x = %f y = %f>>\n",data->mini_x + cos(cor_rd) * grid ,(data->mini_y - sin(cor_rd) * grid));
//     // if ((int)(data->mini_y + sin(cor_rd) * (MOVE_SPEED * size / data->size)) % 100 == 0 || (int)(data->mini_x - cos(cor_rd) * (MOVE_SPEED * size / data->size)) % 100 == 0)
//     // {
//     //     if ((int)data->mini_x % 100 == 0)
//     //     {
//     //         if (prm_moves(data->map,((data->mini_x ) / 100),((data->mini_y  + 5)/ 100)) || prm_moves(data->map,((data->mini_x ) / 100) - 1,((data->mini_y  + 5)/ 100)))
//     //             check = 0;
//     //     }
//         // if (prm_moves(data->map,((data->mini_x ) / 100),((data->mini_y + sin(cor_rd) * (MOVE_SPEED * size / data->size))/ 100)))
//         // {
//         //     check = 0;        
//         // }
//         // if (prm_moves(data->map,((data->mini_x - cos(cor_rd) * (MOVE_SPEED * size / data->size)) / 100),((data->mini_y )/ 100)))
//         // {
//         //     check = 0;        
//       printf("grid        ->%d\ncheck       ->%d\n",m_grid,check);    // }
//     m_grid = (m_grid * MINI_GRID / data->size) ;
//     printf("m_grid        ->%d\n",m_grid);


//     if (check)
//     {
  
//         data->mini_y = data->mini_y - sin(cor_rd) * m_grid;
//         data->mini_x = data->mini_x + cos(cor_rd) * m_grid;
//     //    put_pix(data,data->big_img,14753280);
//     }	
 
    
// }
// void    mini_move_up(t_info *data,int m_grid ,int check,double cor_rd)
// {
// //     int check;
// //     check = 1;
// //     double	cor_rd;
// //     cor_rd = (3.14159265359 * data->corner)/180.0000;
// //     // printf("move up <<x = %f y = %f>>\n",data->mini_x + cos(cor_rd) * (MOVE_SPEED * size / data->size) ,data->mini_y - sin(cor_rd) * (MOVE_SPEED * size / data->size)  );
// //     t_point	p1;
// // 	t_point	p2;
// //     double r;
// //     int grid = (MOVE_SPEED * size / data->size);
// //     det_direction(data, cor_rd);
// // 	p1 = det_coord_x(data, cor_rd,0,size);
// // 	p2 = det_coord_y(data, cor_rd,0,size);
// //     r = p1.r;
// // 	if ((p2.r) < (p1.r))
// //     {
// //         r = p2.r;
// //     }
// //    // printf("r -------> %f\n",r);
// //     if (r <= 20)
// //     {
// //         check = 0;        
// //     }
// //     else if (20 > r - (MOVE_SPEED * size / data->size))
// //         grid = r - 20;
//     // if ((int)(data->mini_y - sin(cor_rd) * (MOVE_SPEED * size / data->size)) % 100 == 0  || (int)(data->mini_x + cos(cor_rd) * MOVE_SPEED) % 100 == 0)
//     // {
//     //     printf("enter here \n");
//         // if ((int)data->mini_x % 100 == 0)
//         // {
//         //     if (prm_moves(data->map,((data->mini_x ) / 100),((data->mini_y - sin(cor_rd) * MOVE_SPEED -1)/ 100) ) || prm_moves(data->map,((data->mini_x ) / 100) - 1,((data->mini_y  - 5 - 1)/ 100)))
//         //         check = 0;
//         // }
//     //     if (prm_moves(data->map,((data->mini_x) / 100),((data->mini_y - sin(cor_rd) * MOVE_SPEED)/ 100)))
//     //     {
//     //         check = 0;        
//     //     }
//     //    if (prm_moves(data->map,((data->mini_x + cos(cor_rd) * MOVE_SPEED) / 100),((data->mini_y )/ 100)))
//     //     {
//     //         check = 0;        
//     //     }
//    // }
//     printf("grid        ->%d\ncheck       ->%d\n",m_grid,check);
     
//     m_grid = (m_grid * MINI_GRID / data->size);
    
//     printf("m_grid        ->%d\ncheck       ->%d\n",m_grid,check);

//     if (check)
//     {
      
//         data->mini_y = data->mini_y - sin(cor_rd) * m_grid;
//         data->mini_x = data->mini_x + cos(cor_rd) * m_grid;
//     //    put_pix(data,data->big_img,14753280);
//     }   
// }

// // 26 -> 6
// // 6 -> 100
// // x ->  MINI_GRID
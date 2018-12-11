/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:12:54 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/12/10 10:12:55 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int			key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(1);
    if (keycode == 123)
    {
      if(worldMap[(int)(mlx->pos_x + mlx->dir_x * mlx->moveSpeed)][(int)(mlx->pos_y)] == 0) mlx->pos_x += mlx->dir_x * mlx->moveSpeed;
      if(worldMap[(int)(mlx->pos_x)][(int)(mlx->pos_y + mlx->dir_y * mlx->moveSpeed)] == 0) mlx->pos_y += mlx->dir_y * mlx->moveSpeed;
    }
    //move backwards if no wall behind you
    if (keycode == 124)
    {
      if(worldMap[(int)(mlx->pos_x - mlx->dir_x * mlx->moveSpeed)][(int)(mlx->pos_y)] == 0) mlx->pos_x -= mlx->dir_x * mlx->moveSpeed;
      if(worldMap[(int)(mlx->pos_x)][(int)(mlx->pos_y - mlx->dir_y * mlx->moveSpeed)] == 0) mlx->pos_y -= mlx->dir_y * mlx->moveSpeed;
    }
    //rotate to the right
    if (keycode == 125)
    {
      //both camera direction and camera plane must be rotated
      double olddir_x = mlx->dir_x;
      mlx->dir_x = mlx->dir_x * cos(-mlx->rotSpeed) - mlx->dir_y * sin(-mlx->rotSpeed);
      mlx->dir_y = olddir_x * sin(-mlx->rotSpeed) + mlx->dir_y * cos(-mlx->rotSpeed);
      double oldplain_x = mlx->plain_x;
      mlx->plain_x = mlx->plain_x * cos(-mlx->rotSpeed) - mlx->plain_y * sin(-mlx->rotSpeed);
      mlx->plain_y = oldplain_x * sin(-mlx->rotSpeed) + mlx->plain_y * cos(-mlx->rotSpeed);
    }
    //rotate to the left
    if (keycode == 125)
    {
      //both camera direction and camera plane must be rotated
      double olddir_x = mlx->dir_x;
      mlx->dir_x = mlx->dir_x * cos(mlx->rotSpeed) - mlx->dir_y * sin(mlx->rotSpeed);
      mlx->dir_y = olddir_x * sin(mlx->rotSpeed) + mlx->dir_y * cos(mlx->rotSpeed);
      double oldplain_x = mlx->plain_x;
      mlx->plain_x = mlx->plain_x * cos(mlx->rotSpeed) - mlx->plain_y * sin(mlx->rotSpeed);
      mlx->plain_y = oldplain_x * sin(mlx->rotSpeed) + mlx->plain_y * cos(mlx->rotSpeed);
    }
	return (0);
}

void		mlx_struct_init(t_mlx *mlx, char *name)
{
	mlx->name = name;
	
	mlx->iter = 100;
	mlx->color_1 = BLUE;
	mlx->color_2 = WHITE;
	mlx->inf_zoom = 0;
    mlx->pos_x = 22;
    mlx->pos_y = 12; 
    mlx->dir_x = -1;
    mlx->dir_y = 0; 
    mlx->plain_x = 0;
    mlx->plain_y = 0.66;
    mlx->time = 0; 
    mlx->oldtime = 0; 
}

/*int do_all_stuff(t_mlx *mlx)
{

}*/

int main(int argv, char **argc)
{
    t_mlx	mlx;

	if (argv == 2)
	{
		mlx_struct_init(&mlx, argc[1]);
		mlx.mlx_ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Wolf3d");
		mlx.image_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
		mlx.data = (int*)mlx_get_data_addr(mlx.image_ptr, &(mlx.bpp),\
		&(mlx.size_line), &(mlx.end));
        //do_all_stuff(&mlx);
		//mlx_hook(mlx.win_ptr, 4, 0, zoom, mlx);
	    //mlx_hook(mlx.win_ptr, 6, 0, mouse, mlx);
	    mlx_key_hook(mlx.win_ptr, key_hook, &mlx);
	    mlx_loop(mlx.mlx_ptr);
	}
	else
		write(1, ERROR_MSG, ft_strlen(ERROR_MSG));
	return (0);
}

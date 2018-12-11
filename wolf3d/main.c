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

int do_all_stuff(t_mlx *mlx)
{
  for(int x = 0; x < WIDTH; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space
      double rayDirX = mlx->dir_x + mlx->plain_x * cameraX;
      double rayDirY = mlx->dir_y + mlx->plain_y * cameraX;
      //which box of the map we're in
      int mapX = (int)mlx->pos_x;
      int mapY = (int)mlx->pos_y;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = abs(1 / rayDirX);
      double deltaDistY = abs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (mlx->pos_x - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - mlx->pos_x) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (mlx->pos_y - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - mlx->pos_y) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0) hit = 1;
      }
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if (side == 0) perpWallDist = (mapX - mlx->pos_x + (1 - stepX) / 2) / rayDirX;
      else           perpWallDist = (mapY - mlx->pos_x + (1 - stepY) / 2) / rayDirY;

      //Calculate height of line to draw on screen
      int lineHeight = (int)(HEIGHT / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + HEIGHT / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + HEIGHT / 2;
      if(drawEnd >= HEIGHT)drawEnd = HEIGHT - 1;

      //choose wall color
      int color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = 0x4286f4;  break; //red
        case 2:  color = 0x41f447;  break; //green
        case 3:  color = 0x40bced;   break; //blue
        case 4:  color = 0xf7f9f9;  break; //white
        default: color = 0xf2f91b; break; //yellow
      }

      //give x and y sides different brightness
      if (side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      verLine(x, drawStart, drawEnd, color);
    }
    //timing for input and FPS counter
    /*oldTime = time;
    mlx->time = getTicks();
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    print(1.0 / frameTime); //FPS counter
    redraw();
    cls();

    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
    readKeys();*/
}

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
        do_all_stuff(&mlx);
		//mlx_hook(mlx.win_ptr, 4, 0, zoom, mlx);
	    //mlx_hook(mlx.win_ptr, 6, 0, mouse, mlx);
	    mlx_key_hook(mlx.win_ptr, key_hook, &mlx);
	    mlx_loop(mlx.mlx_ptr);
	}
	else
		write(1, ERROR_MSG, ft_strlen(ERROR_MSG));
	return (0);
}

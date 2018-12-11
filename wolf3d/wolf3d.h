/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wold3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:13:06 by yyatsenk          #+#    #+#             */
/*   Updated: 2018/12/10 10:13:07 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define BLUE 0x375587
# define WHITE 0xe3e9f4
# define ERROR_MSG "Usage:./fractol [mandelbrot, julia, burningship]\n"
# define HEIGHT 384
# define WIDTH 512

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image_ptr;
	unsigned	color;
	unsigned	color_1;
	unsigned	color_2;
	int			*data;
	int			bpp;
	int			size_line;
	int			end;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plain_x;
	double		plain_y;
	double		time;
	double		oldtime;
	double		camera_x;
	int 		map_x;
    int 		map_y;
	double moveSpeed;
    double rotSpeed;
	double frameTime;
	int			**map;
	char		*name;
	int			iter;
	int			inf_zoom;
}				t_mlx;

#endif
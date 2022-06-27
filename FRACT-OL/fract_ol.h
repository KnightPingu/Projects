/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:52:59 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/11/10 11:53:01 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <math.h>
# include <stdio.h>
# include "LIBFT/libft.h"
# include <mlx.h>

# define RED 0x00FF0000
# define ORANGE 0x00FF7F00
# define YELLOW 0x00FFFF00
# define LIME 0x007FFF00
# define GREEN 0x0000FF00
# define TEAL 0x0000FF7F
# define CYAN 0x0000FFFF
# define AZURE 0x00007FFF
# define BLUE 0x000000FF
# define PURPLE 0x007F00FF
# define MAGENTA 0x00FF00FF
# define PINK 0x00FF007F
# define BLACK 0x00000000

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		linel;
	int		endian;
}				t_image;

typedef struct s_window
{
	int		x;
	int		y;

	double	r;
	double	i;

	int		f;
	double	zoom;

	void	*mlx;
	void	*wind;
	int		index;

	t_image	img;
	t_image	img2;

	double	jr;
	double	ji;
}				t_window;

int			display_w(t_window *sc);
void		my_mlx_pixel_put(t_image *img, int x, int y, int colour);
double		ft_atof(char *str);
int			keypress(int keycode, t_window *sc);
int			mouseclick(int keycode, int x, int y, t_window *sc);
int			iterate_m(double r, double i, int c);
int			iterate_j(double r, double i, int c, t_window *sc);
int			iterate_b(double r, double i, int c);
void		set_image(t_window *sc, t_image img);
t_window	*param_error(t_window *sc);
int			check_mandel(char *str);
int			check_julia(char *str);
int			check_burning(char *str);

#endif

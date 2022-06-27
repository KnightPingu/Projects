/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:26:39 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/11/17 13:26:41 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	get_ind_colour(int c)
{
	if (c == 22 || c == 23)
		return (PINK);
	else if (c == 20 || c == 21)
		return (MAGENTA);
	else if (c == 18 || c == 19)
		return (PURPLE);
	else if (c == 16 || c == 17)
		return (BLUE);
	else if (c == 14 || c == 15)
		return (AZURE);
	else if (c == 12 || c == 13)
		return (CYAN);
	else if (c == 10 || c == 11)
		return (TEAL);
	else if (c == 8 || c == 9)
		return (GREEN);
	else if (c == 6 || c == 7)
		return (LIME);
	else if (c == 4 || c == 5)
		return (YELLOW);
	else if (c == 2 || c == 3)
		return (ORANGE);
	else
		return (RED);
}

int	get_pixel_colour(t_window *sc, int y, int x)
{
	int		c;
	double	real;
	double	imaginary;

	real = sc->r + (((double)x - (sc->x / 2)) * (0.002 / sc->zoom));
	imaginary = sc->i + (((double)y - (sc->y / 2)) * (0.002 / sc->zoom));
	if (sc->f == 0)
		c = iterate_m(real, imaginary, fmax(12.5 * sc->zoom / 2, 50));
	else if (sc->f == 1)
		c = iterate_j(real, imaginary, fmax(25 * sc->zoom / 2, 75), sc);
	else
		c = iterate_b(real, imaginary, fmax(12.5 * sc->zoom / 2, 50));
	if (c == -1)
		return (BLACK);
	return (get_ind_colour(c % 24));
}

void	set_image(t_window *sc, t_image img)
{
	int	i;
	int	j;

	i = 0;
	while (i < sc->y)
	{
		j = 0;
		while (j < sc->x)
		{
			my_mlx_pixel_put(&img, j, i, get_pixel_colour(sc, i, j));
			j++;
		}
		i++;
	}
}

int	display_w(t_window *sc)
{
	sc->index = 0;
	set_image(sc, sc->img);
	mlx_put_image_to_window(sc->mlx, sc->wind, sc->img.img, 0, 0);
	mlx_key_hook(sc->wind, keypress, sc);
	mlx_mouse_hook(sc->wind, mouseclick, sc);
	mlx_loop(sc->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:27:04 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/11/23 12:27:05 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_exit(t_window *sc)
{
	free(sc);
	return (0);
}

void	render(t_window *sc)
{
	if (sc->index)
	{
		set_image(sc, sc->img);
		mlx_put_image_to_window(sc->mlx, sc->wind, sc->img.img, 0, 0);
	}
	else
	{
		set_image(sc, sc->img2);
		mlx_put_image_to_window(sc->mlx, sc->wind, sc->img2.img, 0, 0);
	}
	sc->index = !sc->index;
}

int	keypress(int keycode, t_window *sc)
{
	if (keycode == 13)
	{
		sc->i = sc->i - (25 * (0.002 / sc->zoom));
		render(sc);
	}
	else if (keycode == 1)
	{
		sc->i = sc->i + (25 * (0.002 / sc->zoom));
		render(sc);
	}
	else if (keycode == 0)
	{
		sc->r = sc->r - (25 * (0.002 / sc->zoom));
		render(sc);
	}
	else if (keycode == 2)
	{
		sc->r = sc->r + (25 * (0.002 / sc->zoom));
		render(sc);
	}
	else if (keycode == 53)
		exit(ft_exit(sc));
	return (0);
}

int	mouseclick(int keycode, int x, int y, t_window *sc)
{
	(void)y;
	(void)x;
	if (keycode == 5)
	{
		sc->zoom = sc->zoom * 1.1;
		render(sc);
	}
	else if (keycode == 4)
	{
		sc->zoom = sc->zoom / 1.1;
		render(sc);
	}
	return (0);
}

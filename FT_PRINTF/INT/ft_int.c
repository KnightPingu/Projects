/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:00:16 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/02 18:30:39 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_presign(char *str, int min, int nb)
{
	if (ft_contains(str, '0') && min > 0 && !ft_contains(str, '.') && nb < 0)
		write(1, "-", 1);
	if (ft_contains(str, '0') && min > 0
		&& !ft_contains(str, '.') && nb >= 0 && ft_contains(str, '+'))
		write(1, "+", 1);
	else if (ft_contains(str, '0') && min > 0
		&& !ft_contains(str, '.') && nb >= 0 && ft_contains(str, ' '))
		write(1, " ", 1);
}

void	ft_postsign(char *str, int min, int nb)
{
	if (nb >= 0 && ft_contains(str, '+')
		&& (!ft_contains(str, '0') || min < 0 || ft_contains(str, '.')))
		write(1, "+", 1);
	else if (nb >= 0 && ft_contains(str, ' ')
		&& (!ft_contains(str, '0') || min < 0 || ft_contains(str, '.')))
		write(1, " ", 1);
	if (nb < 0 && (!ft_contains(str, '0') || min < 0 || ft_contains(str, '.')))
		write(1, "-", 1);
}

void	ft_writeint(int nb, char *str, int max, int size)
{
	if (nb == 0 && max == 0 && ft_contains(str, '.'))
		return ;
	if (max > size)
		ft_writexchar((max - size), '0');
	ft_putint(nb);
}

int	ft_intwritten(int tern, int min, char *flags)
{
	if (min < 0)
		min = -min;
	if (tern > min)
		min = tern;
	free(flags);
	return (min);
}

int	ft_int(int nb, char *str, int min, int max)
{
	int		size;
	int		tern;

	size = ft_intlen(nb, max, str);
	tern = size;
	if (max > size)
		tern = max;
	if ((nb >= 0 && (ft_contains(str, '+') || ft_contains(str, ' '))) || nb < 0)
		tern++;
	ft_presign(str, min, nb);
	if (ft_contains(str, '0') && min > tern && !ft_contains(str, '.'))
		ft_writexchar(min - tern, '0');
	else if (min > tern)
		ft_writexchar(min - tern, ' ');
	ft_postsign(str, min, nb);
	ft_writeint(nb, str, max, size);
	if (min < 0)
		ft_writexchar((min * -1) - tern, ' ');
	return (ft_intwritten(tern, min, str));
}

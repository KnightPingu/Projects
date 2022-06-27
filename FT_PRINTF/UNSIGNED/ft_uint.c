/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:25:37 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/03 18:25:38 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_unsignedintlenbase(unsigned int nb, int base, int m, char *s)
{
	if (base < 2)
		return (0);
	if (nb == 0 && m == 0 && ft_contains(s, '.'))
		return (0);
	if (nb >= (unsigned int)base)
		return (1 + ft_unsignedintlenbase(nb / base, base, m, s));
	else
		return (1);
}

void	ft_unsignedbase(unsigned int nb, char *base, int size)
{
	if (nb >= (unsigned int)size)
	{
		ft_unsignedbase(nb / size, base, size);
		ft_unsignedbase(nb % size, base, size);
	}
	else
		ft_putchar(base[nb]);
}

int	ft_uint(unsigned int nb, char *str, int min, int max)
{
	int	size;
	int	tern;

	size = ft_unsignedintlenbase(nb, 10, max, str);
	tern = size;
	if (max > size)
		tern = max;
	if (ft_contains(str, '0') && min > 0 && !ft_contains(str, '.'))
		ft_writexchar(min - tern, '0');
	else if (min > 0)
		ft_writexchar(min - tern, ' ');
	if (max > size)
		ft_writexchar((max - size), '0');
	if (nb != 0 || max != 0 || !ft_contains(str, '.'))
		ft_unsignedbase(nb, "0123456789", 10);
	if (min < 0)
		ft_writexchar(-min - tern, ' ');
	free(str);
	if (min >= tern && min > 0)
		return (min);
	else if (min < 0 && (0 - min) >= tern)
		return (-min);
	return (tern);
}

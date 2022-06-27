/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:22:31 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/04 11:22:32 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_writtenhex(int min, int tern, char *str)
{
	if (min < 0)
		min = -min;
	if (ft_contains(str, '#'))
		min = min + 2;
	free(str);
	if (min >= tern)
		return (min);
	return (tern);
}

int	ft_hexupper(unsigned int nb, char *str, int min, int max)
{
	int	size;
	int	tern;

	size = ft_unsignedintlenbase(nb, 16, max, str);
	if (ft_contains(str, '#'))
		min = min - 2;
	tern = size;
	if (max > size)
		tern = max;
	if (ft_contains(str, '0') && min > 0 && !ft_contains(str, '.'))
		ft_writexchar(min - tern, '0');
	else if (min > 0)
		ft_writexchar(min - tern, ' ');
	if (ft_contains(str, '#'))
		write(1, "0X", 2);
	if (max > size)
		ft_writexchar((max - size), '0');
	if (nb != 0 || max != 0 || !ft_contains(str, '.'))
		ft_unsignedbase(nb, "0123456789ABCDEF", 16);
	if (min < 0)
		ft_writexchar(-min - tern, ' ');
	return (ft_writtenhex(min, tern, str));
}

int	ft_hexlower(unsigned int nb, char *str, int min, int max)
{
	int	size;
	int	tern;

	size = ft_unsignedintlenbase(nb, 16, max, str);
	if (ft_contains(str, '#'))
		min = min - 2;
	tern = size;
	if (max > size)
		tern = max;
	if (ft_contains(str, '0') && min > 0 && !ft_contains(str, '.'))
		ft_writexchar(min - tern, '0');
	else if (min > 0)
		ft_writexchar(min - tern, ' ');
	if (ft_contains(str, '#'))
		write(1, "0x", 2);
	if (max > size)
		ft_writexchar((max - size), '0');
	if (nb != 0 || max != 0 || !ft_contains(str, '.'))
		ft_unsignedbase(nb, "0123456789abcdef", 16);
	if (min < 0)
		ft_writexchar(-min - tern, ' ');
	return (ft_writtenhex(min, tern, str));
}

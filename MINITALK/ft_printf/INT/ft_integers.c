/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:32:51 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/02 16:32:53 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putint(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (nb < 0)
		nb = nb * -1;
	if (nb >= 10)
	{
		ft_putint(nb / 10);
		ft_putint(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int	ft_intlen(int nb, int max, char *str)
{
	if (nb == 0 && max == 0 && ft_contains(str, '.'))
		return (0);
	if (nb == -2147483648)
		nb++;
	if (nb < 0)
		return (ft_intlen(-nb, max, str));
	else if (nb >= 10)
		return (1 + ft_intlen(nb / 10, max, str));
	else
		return (1);
}

void	ft_setminmaxint(int *min, int *max, char *flags)
{
	int	i;

	i = 0;
	if (!(*min))
	{
		while (!ft_isdigit0(flags[i]) && flags[i] != '.' && flags[i] != 0)
			i++;
		if (flags[i] != '.' && flags[i] != 0)
			*min = ft_atoi(&flags[i]);
	}
	while (flags[i] != '.' && flags[i] != 0)
		i++;
	if (!(*max) && flags[i] == '.' && flags[i + 1] != '*')
		*max = ft_atoi(&flags[i + 1]);
	if (ft_contains(flags, '-') && *min > 0)
		*min = *min * -1;
}

void	ft_va_argint(int *m, int *a, va_list *ap, char *f)
{
	int	i;

	i = 0;
	while (f[i] && f[i] != '.' && f[i] != '*')
		i++;
	if (f[i] == '*')
		*m = va_arg(*ap, int);
	while (f[i] != '.' && f[i])
		i++;
	if (f[i] == '.')
	{
		i++;
		if (f[i] == '*')
			*a = va_arg(*ap, int);
	}
}

int	ft_integers(int n, char *str, va_list *ap)
{
	int		i;
	char	*flags;
	int		min;
	int		max;

	i = 0;
	min = 0;
	max = 0;
	str = find_start_conversion(str, &i);
	flags = ft_substr(str, 1, i);
	if (!flags)
		return (-1);
	ft_va_argint(&min, &max, ap, flags);
	n = va_arg(*ap, int);
	ft_setminmaxint(&min, &max, flags);
	ft_removefield(flags);
	return (ft_int(n, flags, min, max));
}

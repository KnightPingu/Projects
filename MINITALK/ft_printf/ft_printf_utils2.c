/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:05:19 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/06/21 12:45:10 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static int	ft_check_overflow(unsigned long result, int mcount)
{
	if (result > 9223372036854775807 && mcount == 1)
		return (-1);
	else if (result - 1 > 9223372036854775807 && mcount == -1)
		return (0);
	return ((int)result * mcount);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	result;
	int				mcount;

	if (str == 0)
		return (0);
	i = 0;
	result = 0;
	mcount = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mcount = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (ft_check_overflow(result, mcount));
}

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}

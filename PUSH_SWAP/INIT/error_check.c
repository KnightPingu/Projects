/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:14:45 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/05 13:14:47 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	ft_check_limit_char2(int i, int l)
{
	if ((i == 6 || i == 10) && l == 11)
		return ('8');
	if (i == 7 && l == 11)
		return ('3');
	if (i == 8 && l == 11)
		return ('6');
	return (0);
}

char	ft_check_limit_char(int i, int l)
{
	if (i == 0)
		return ('2');
	if (i == 1 && l == 10)
		return ('1');
	if ((i == 2 || i == 4 || i == 8) && l == 10)
		return ('4');
	if ((i == 3 || i == 9) && l == 10)
		return ('7');
	if (i == 5 && l == 10)
		return ('8');
	if (i == 6 && l == 10)
		return ('3');
	if (i == 7 && l == 10)
		return ('6');
	if (i == 1 && l == 11)
		return ('2');
	if (i == 2 && l == 11)
		return ('1');
	if ((i == 3 || i == 5 || i == 9) && l == 11)
		return ('4');
	if (i == 4 && l == 11)
		return ('7');
	return (ft_check_limit_char2(i, l));
}

int	ft_check_limit(char *str, int l)
{
	int		i;
	int		c;
	char	temp;

	if (str[0] == '-' && l == 10)
		return (0);
	else if (str[0] != '-' && l == 11)
		return (-1);
	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		temp = ft_check_limit_char(i, l);
		c = ft_strncmp(&temp, &str[i], 1);
		if (c < 0)
			return (-1);
		if (c > 0)
			return (0);
		i++;
	}
	return (0);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	error_check(int nb, char **list)
{
	int	i;
	int	l;

	i = 0;
	while (i < nb)
	{
		if (ft_check_digit(list[i]))
			return (-1);
		l = ft_strlen(list[i]);
		if (l > 11)
			return (-1);
		if (l == 11 || l == 10)
		{
			if (ft_check_limit(list[i], l))
				return (-1);
		}
		i++;
	}
	return (0);
}

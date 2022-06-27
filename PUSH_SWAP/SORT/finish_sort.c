/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:03:58 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/28 11:04:00 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_divide(t_psort *data)
{
	int	i;
	int	j;
	int	temp;
	int	cutoff;

	i = 1;
	while (i < data->chunk)
	{
		j = 0;
		cutoff = (data->s[((data->sizes * i) / data->chunk) - 1]);
		temp = data->sizea;
		while (j < temp)
		{
			if (data->a[0] <= cutoff)
				ft_pb(data);
			else
				ft_ra(data);
			j++;
		}
		i++;
	}
}

int	ft_check_sort(t_psort *data)
{
	int	i;

	i = 1;
	while (i < data->sizea)
	{
		if (data->a[i - 1] > data->a[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_offsetb(t_psort *data, int biggest)
{
	int	i;
	int	negative;

	i = 0;
	while (i < data->sizeb && data->b[i] != biggest)
		i++;
	negative = i - data->sizeb;
	if (negative * -1 < i)
		return (negative);
	return (i);
}

int	ft_find_big_v(t_psort *data)
{
	int	i;
	int	big;

	i = 1;
	big = data->b[0];
	while (i < data->sizeb)
	{
		if (big < data->b[i])
			big = data->b[i];
		i++;
	}
	return (big);
}

void	ft_and_conquer(t_psort *data)
{
	int	biggest;
	int	offset;

	while (data->sizeb > 0)
	{
		biggest = ft_find_big_v(data);
		offset = ft_find_offsetb(data, biggest);
		while (data->b[0] != biggest)
		{
			if (offset > 0)
				ft_rb(data);
			else
				ft_rrb(data);
		}
		ft_pa(data);
	}
}

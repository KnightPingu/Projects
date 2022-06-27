/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:41:35 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/25 11:41:38 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_small_v(t_psort *data)
{
	int	i;
	int	small;

	i = 1;
	small = data->a[0];
	while (i < data->sizea)
	{
		if (small > data->a[i])
			small = data->a[i];
		i++;
	}
	return (small);
}

int	ft_find_offseta(t_psort *data, int smallest)
{
	int	i;
	int	negative;

	i = 0;
	while (i < data->sizea && data->a[i] != smallest)
		i++;
	negative = i - data->sizea;
	if (negative * -1 < i)
		return (negative);
	return (i);
}

void	ft_norm_pain(t_psort *data, int smallest, int offset)
{
	while (1)
	{
		if (data->sizea > 1 && data->a[1] == smallest)
			ft_sa(data);
		if (ft_check_sort(data))
			break ;
		if (data->a[0] == smallest)
		{
			ft_pb(data);
			break ;
		}
		if (ft_check_sort(data))
			break ;
		if (offset > 0)
			ft_ra(data);
		else
			ft_rra(data);
		if (ft_check_sort(data))
			break ;
	}
}

void	ft_sort_first(t_psort *data)
{
	int	holdsize;
	int	smallest;
	int	offset;

	if (data->chunksize == 3)
	{
		ft_sort_small(data);
		return ;
	}
	holdsize = data->sizea;
	while (!ft_check_sort(data))
	{
		smallest = ft_find_small_v(data);
		offset = ft_find_offseta(data, smallest);
		ft_norm_pain(data, smallest, offset);
	}
	while (data->sizea < holdsize)
		ft_pa(data);
}

void	ft_sort(t_psort *data)
{
	if (ft_check_sort(data))
		return ;
	if (data->sizea % 25)
	{
		data->chunk = (data->sizea / 25) + 1;
		if (data->sizea % data->chunk)
			data->chunksize = data->sizea / data->chunk + 1;
		else
			data->chunksize = data->sizea / data->chunk;
	}
	else
	{
		data->chunk = (data->sizea / 25);
		data->chunksize = 25;
	}
	ft_divide(data);
	ft_sort_first(data);
	ft_and_conquer(data);
	if (!ft_check_sort(data))
		write(1, "ERROR\n", 6);
	free(data->a);
	free(data->b);
	free(data->s);
	free(data);
}

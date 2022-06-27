/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:27:49 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/22 11:27:51 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_psort *data)
{
	int	temp;
	int	i;

	if (data->sizea <= 1)
		return ;
	i = data->sizea - 1;
	temp = data->a[i];
	while (i > 0)
	{
		data->a[i] = data->a[i - 1];
		i--;
	}
	data->a[0] = temp;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_psort *data)
{
	int	temp;
	int	i;

	if (data->sizeb <= 1)
		return ;
	i = data->sizeb - 1;
	temp = data->b[i];
	while (i > 0)
	{
		data->b[i] = data->b[i - 1];
		i--;
	}
	data->b[0] = temp;
	write(1, "rrb\n", 4);
}

void	ft_rrr2(t_psort *data, int i, int temp)
{
	if (!(data->sizeb <= 1))
	{
		i = data->sizeb - 1;
		temp = data->b[i];
		while (i > 0)
		{
			data->b[i] = data->b[i - 1];
			i--;
		}
		data->b[0] = temp;
	}
}

void	ft_rrr(t_psort *data)
{
	int	temp;
	int	i;

	i = -1;
	temp = 0;
	if (!(data->sizea <= 1))
	{
		i = data->sizea - 1;
		temp = data->a[i];
		while (i > 0)
		{
			data->a[i] = data->a[i - 1];
			i--;
		}
		data->a[0] = temp;
	}
	ft_rrr2(data, i, temp);
	write(1, "rrr\n", 4);
}

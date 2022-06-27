/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:12:29 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/22 11:12:32 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_psort *data)
{
	int	transfer;
	int	i;

	if (data->sizeb == 0)
		return ;
	transfer = data->b[0];
	i = 0;
	while (i < data->sizeb - 1)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
	data->sizeb--;
	i = data->sizea;
	while (i > 0)
	{
		data->a[i] = data->a[i - 1];
		i--;
	}
	data->a[0] = transfer;
	data->sizea++;
	write(1, "pa\n", 3);
}

void	ft_pb(t_psort *data)
{
	int	transfer;
	int	i;

	if (data->sizea == 0)
		return ;
	transfer = data->a[0];
	i = 0;
	while (i < data->sizea - 1)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	data->sizea--;
	i = data->sizeb;
	while (i > 0)
	{
		data->b[i] = data->b[i - 1];
		i--;
	}
	data->b[0] = transfer;
	data->sizeb++;
	write(1, "pb\n", 3);
}

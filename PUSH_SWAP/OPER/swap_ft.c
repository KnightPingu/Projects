/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:41:06 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/20 14:41:09 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_psort *data)
{
	int	temp;

	if (data->sizea <= 1)
		return ;
	temp = data->a[0];
	data->a[0] = data->a[1];
	data->a[1] = temp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_psort *data)
{
	int	temp;

	if (data->sizeb <= 1)
		return ;
	temp = data->b[0];
	data->b[0] = data->b[1];
	data->b[1] = temp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_psort *data)
{
	int	temp;

	if (!(data->sizea <= 1))
	{
		temp = data->a[0];
		data->a[0] = data->a[1];
		data->a[1] = temp;
	}
	if (!(data->sizeb <= 1))
	{
		temp = data->b[0];
		data->b[0] = data->b[1];
		data->b[1] = temp;
	}
	write(1, "ss\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:16:30 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/22 11:16:32 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_psort *data)
{
	int	temp;
	int	i;

	if (data->sizea <= 1)
		return ;
	temp = data->a[0];
	i = 0;
	while (i < data->sizea - 1)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	data->a[i] = temp;
	write(1, "ra\n", 3);
}

void	ft_rb(t_psort *data)
{
	int	temp;
	int	i;

	if (data->sizeb <= 1)
		return ;
	temp = data->b[0];
	i = 0;
	while (i < data->sizeb - 1)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
	data->b[i] = temp;
	write(1, "rb\n", 3);
}

void	ft_rr2(t_psort *data, int i, int temp)
{
	if (!(data->sizeb <= 1))
	{
		temp = data->b[0];
		i = 0;
		while (i < data->sizeb - 1)
		{
			data->b[i] = data->b[i + 1];
			i++;
		}
		data->b[i] = temp;
	}
}

void	ft_rr(t_psort *data)
{
	int	temp;
	int	i;

	i = -1;
	temp = 0;
	if (!(data->sizea <= 1))
	{
		temp = data->a[0];
		i = 0;
		while (i < data->sizea - 1)
		{
			data->a[i] = data->a[i + 1];
			i++;
		}
		data->a[i] = temp;
	}
	ft_rr2(data, i, temp);
	write(1, "rr\n", 3);
}

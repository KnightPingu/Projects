/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:53:54 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/11/06 13:53:55 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_small(t_psort *data)
{
	int	i;

	if (data->a[0] > data->a[1] && data->a[0] > data->a[2])
		i = 0;
	else if (data->a[1] > data->a[0] && data->a[1] > data->a[2])
		i = 1;
	else
		i = 2;
	if (i == 0)
		ft_ra(data);
	else if (i == 1)
		ft_rra(data);
	if (data->a[0] > data->a[1])
		ft_sa(data);
}

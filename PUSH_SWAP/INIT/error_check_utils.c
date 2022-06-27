/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check2_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:46:24 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/13 13:46:29 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_error(int *a, int *b, char **list, int size)
{
	free(a);
	free(b);
	if (size)
		ft_free_list(list, size);
	write(1, "ERROR\n", 6);
	return (-1);
}

int	ft_check_dupes(int *a, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb)
	{
		j = i + 1;
		while (j < nb)
		{
			if (a[j] == a[i])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

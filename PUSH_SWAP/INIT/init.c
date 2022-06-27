/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:47:13 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/05 12:47:18 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	ft_init(int *a, int *b, int *solved, int size)
{
	t_psort	*data;

	data = malloc(sizeof(t_psort));
	if (!data)
		return (ft_error(a, b, (char **)&solved, 1));
	data->a = a;
	data->b = b;
	data->s = solved;
	data->sizea = size;
	data->sizeb = 0;
	data->sizes = size;
	ft_sort(data);
	return (0);
}

int	*ft_man_solve(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < size)
	{
		temp = tab[i];
		j = i;
		k = i;
		while (j < size)
		{
			if (temp > tab[j])
			{
				temp = tab[j];
				k = j;
			}
			j++;
		}
		tab[k] = tab[i];
		tab[i] = temp;
		i++;
	}
	return (tab);
}

int	*ft_init_a(int nb, char **input)
{
	int	i;
	int	*a;

	i = 0;
	a = malloc(sizeof(int) * (nb));
	if (!a)
		return (0);
	while (i < nb)
	{
		a[i] = ft_atoi(input[i]);
		i++;
	}
	if (ft_check_dupes(a, i))
	{
		free(a);
		return (0);
	}
	return (a);
}

char	**ft_init_arg(char **argv, int argc, int *size)
{
	if (argc == 1)
		exit(0);
	return (ft_parse_sep(argv, argc, size));
}

int	main(int argc, char **argv)
{
	int		size;
	int		*a;
	int		*b;
	int		*solved;
	char	**arguments;

	size = 0;
	arguments = ft_init_arg(argv, argc, &size);
	if (!arguments)
		return (-1);
	if (error_check(size, arguments))
		return (ft_error(0, 0, arguments, size));
	a = ft_init_a(size, arguments);
	if (!a)
		return (ft_error(0, 0, arguments, size));
	solved = ft_man_solve(a, size);
	a = ft_init_a(size, arguments);
	if (!a)
		return (ft_error(0, solved, arguments, size));
	ft_free_list(arguments, size);
	b = malloc(sizeof(int) * size);
	if (!b)
		return (ft_error(a, solved, 0, 0));
	return (ft_init(a, b, solved, size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:45:50 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/14 12:45:55 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**ft_free_list(char **list, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (0);
}

char	**ft_parse_sep(char **argv, int argc, int *size)
{
	char	**list;

	list = malloc(sizeof(void *) * (argc - 1));
	if (!list)
		return (0);
	while (*size < argc - 1)
	{
		list[*size] = ft_strdup(argv[(*size) + 1]);
		if (!list[*size])
			return (ft_free_list(list, *size));
		*size = (*size) + 1;
	}
	return (list);
}

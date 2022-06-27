/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:41:19 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/12/22 13:41:21 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philo(t_sopher *sopher)
{
	int	i;

	i = 0;
	while (i < sopher->nop)
	{
		sopher->philo[i].id = i;
		sopher->philo[i].nb_eat = 0;
		sopher->philo[i].own_fork = i;
		sopher->philo[i].other_fork = (i + 1) % sopher->nop;
		sopher->philo[i].l_eat = 0;
		sopher->philo[i].sopher = sopher;
		i++;
	}
	return (0);
}

int	init_mutex(t_sopher *sopher)
{
	int	i;

	i = 0;
	while (i < sopher->nop)
	{
		if (pthread_mutex_init(&(sopher->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(sopher->write), NULL))
		return (1);
	if (pthread_mutex_init(&(sopher->meal_check), NULL))
		return (1);
	return (0);
}

int	main_init(t_sopher *sopher, char **argv)
{
	sopher->nop = ft_atoi(argv[1]);
	sopher->ttd = ft_atoi(argv[2]);
	sopher->tte = ft_atoi(argv[3]);
	sopher->tts = ft_atoi(argv[4]);
	sopher->all_ate = 0;
	sopher->end = 0;
	if (sopher->nop < 1 || sopher->ttd < 0 || sopher->tte < 0
		|| sopher->tts < 0 || sopher->nop > 250)
		return (1);
	if (argv[5])
	{
		sopher->noe = ft_atoi(argv[5]);
		if (sopher->noe < 0)
			return (1);
	}
	else
		sopher->noe = -1;
	if (init_mutex(sopher))
		return (2);
	init_philo(sopher);
	return (0);
}

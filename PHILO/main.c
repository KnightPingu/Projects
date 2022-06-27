/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:32:01 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/12/22 13:32:03 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dis_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	error_id(int error)
{
	if (error == 1)
		return (dis_error("Argument"));
	if (error == 2)
		return (dis_error("Mutex"));
	return (1);
}

void	mutex_des(t_sopher *sopher, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < sopher->nop)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < sopher->nop)
	{
		pthread_mutex_destroy(&(sopher->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(sopher->write));
	pthread_mutex_destroy(&(sopher->meal_check));
	if (sopher->all_ate == 1)
		printf("All Philosophers ate %d time(s)\n", sopher->noe);
}

int	main(int argc, char **argv)
{
	t_sopher	sopher;
	int			err;

	if (argc != 5 && argc != 6)
		return (dis_error("Argument"));
	err = main_init(&sopher, argv);
	if (err)
		return (error_id(err));
	if (init_thread(&sopher))
		return (dis_error("Thread"));
	return (0);
}

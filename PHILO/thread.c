/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:40:05 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/12/22 13:40:06 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_philo *philo)
{
	t_sopher	*sopher;

	sopher = philo->sopher;
	pthread_mutex_lock(&(sopher->forks[philo->own_fork]));
	dis_action(sopher, philo->id, "has taken a fork", 0);
	pthread_mutex_lock(&(sopher->forks[philo->other_fork]));
	dis_action(sopher, philo->id, "has taken a fork", 0);
	pthread_mutex_lock(&(sopher->meal_check));
	dis_action(sopher, philo->id, "is eating", 0);
	philo->l_eat = get_time();
	pthread_mutex_unlock(&(sopher->meal_check));
	smart_sleep(sopher->tte, sopher);
	(philo->nb_eat)++;
	pthread_mutex_unlock(&(sopher->forks[philo->own_fork]));
	pthread_mutex_unlock(&(sopher->forks[philo->other_fork]));
}

void	*p_th(void *v_philo)
{
	t_philo		*philo;
	t_sopher	*sopher;

	philo = (t_philo *)v_philo;
	sopher = philo->sopher;
	if (philo->id % 2)
		usleep(15000);
	while (!(sopher->end))
	{
		p_eat(philo);
		if (sopher->all_ate)
			break ;
		dis_action(sopher, philo->id, "is sleeping", 0);
		smart_sleep(sopher->tts, sopher);
		dis_action(sopher, philo->id, "is thinking", 0);
	}
	return (NULL);
}

void	unlock_forks(t_sopher *sopher)
{
	int	i;

	i = 0;
	while (i < sopher->nop)
	{
		pthread_mutex_unlock(&(sopher->forks[i]));
		i++;
	}
}

void	death_check(t_sopher *sopher, t_philo *philo)
{
	int	i;

	while (!(sopher->all_ate))
	{
		i = 0;
		while (i < sopher->nop && !(sopher->end))
		{
			pthread_mutex_lock(&(sopher->meal_check));
			if (time_diff(philo[i].l_eat, get_time()) > sopher->ttd)
				dis_action(sopher, i, "died", 1);
			pthread_mutex_unlock(&(sopher->meal_check));
			usleep(100);
			i++;
		}
		if (sopher->end)
			break ;
		i = 0;
		while ((sopher->noe != -1)
			&& i < sopher->nop && philo[i].nb_eat >= sopher->noe)
			i++;
		if (i == sopher->nop)
			sopher->all_ate = 1;
	}
	unlock_forks(sopher);
}

int	init_thread(t_sopher *sopher)
{
	int		i;

	i = 0;
	sopher->start = get_time();
	while (i < sopher->nop)
	{
		if (pthread_create(&(sopher->philo[i].thread_id),
				NULL, p_th, &(sopher->philo[i])))
			return (1);
		sopher->philo[i].l_eat = get_time();
		i++;
	}
	death_check(sopher, sopher->philo);
	mutex_des(sopher, sopher->philo);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:42:03 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/12/22 13:42:05 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	smart_sleep(long long time, t_sopher *sopher)
{
	long long	i;

	i = get_time();
	while (!(sopher->end))
	{
		if (time_diff(i, get_time()) >= time)
			break ;
		usleep(50);
	}
}

void	dis_action(t_sopher *sopher, int id, char *str, int d)
{
	pthread_mutex_lock(&(sopher->write));
	if (!(sopher->end))
	{
		printf("%lli ", get_time() - sopher->start);
		printf("%i ", id + 1);
		printf("%s\n", str);
		if (d == 1)
			sopher->end = 1;
	}
	pthread_mutex_unlock(&(sopher->write));
	return ;
}

int	ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	result;
	int				mcount;

	if (str == 0)
		return (0);
	i = 0;
	result = 0;
	mcount = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mcount = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return ((int)result * mcount);
}

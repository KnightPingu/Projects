/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:47:20 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/10/12 10:50:38 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_send_char(pid_t pid, char str)
{
	int	c;
	int	i;

	i = 128;
	c = (int)str;
	while (i >= 1)
	{
		if (c / i)
		{
			if (kill(pid, SIGUSR2))
				return (-1);
		}
		else
		{
			if (kill(pid, SIGUSR1))
				return (-1);
		}
		c = c % i;
		i = i / 2;
		usleep(100);
	}
	return (0);
}

int	ft_send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_send_char(pid, str[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_error(int argc, pid_t *pid, char **argv)
{
	if (argc != 3)
	{
		ft_printf("ERROR, WRONG NUMBER OF ARGUMENTS\n");
		return (-1);
	}
	*pid = ft_atoi(argv[1]);
	if (*pid == 0 || *pid == -1)
	{
		ft_printf("ERROR, INVALID PID\n");
		return (-1);
	}
	if (kill(*pid, 0))
	{
		ft_printf("ERROR, INVALID PID\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (ft_error(argc, &pid, argv))
		return (-1);
	if (ft_send_str(pid, argv[2]))
	{
		ft_printf("ERROR DURING MESSAGE COM\n");
		return (-1);
	}
	return (0);
}

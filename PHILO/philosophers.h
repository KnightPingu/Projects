/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:42:51 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/12/22 13:42:52 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

struct	s_rules;

typedef struct s_philo
{
	int					id;
	int					nb_eat;
	int					own_fork;
	int					other_fork;
	long long			l_eat;
	struct s_sopher		*sopher;
	pthread_t			thread_id;
}				t_philo;

typedef struct s_sopher
{
	t_philo				philo[250];
	int					nop;
	int					ttd;
	int					tte;
	int					tts;
	int					noe;
	int					end;
	int					all_ate;
	long long			start;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		write;
}						t_sopher;

int			main_init(t_sopher *sopher, char **argv);
int			ft_atoi(const char *str);
int			init_thread(t_sopher *sopher);
long long	get_time(void);
void		dis_action(t_sopher *sopher, int id, char *str, int d);
long long	time_diff(long long past, long long pres);
void		smart_sleep(long long time, t_sopher *sopher);
void		mutex_des(t_sopher *sopher, t_philo *philo);

#endif

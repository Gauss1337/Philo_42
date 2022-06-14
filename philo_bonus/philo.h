/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:43:56 by ahakam            #+#    #+#             */
/*   Updated: 2022/06/13 05:16:44 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	unsigned long long	last_meal;
	int					id;
	int					lfork;
	int					rfork;
	int					number_of_time_eat;
	int					is_eating;
	struct s_threads	*thread;
	sem_t				*m_eat;
	pid_t				pid;
}	t_philo;

typedef struct s_threads
{
	unsigned long long	time;
	int					philo_num;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					number_of_time_to_eat;
	sem_t				*fork;
	sem_t				*write;
	sem_t				*eat;
	struct s_philo		*philosopher;

}	t_threads;

unsigned long long	ft_get_time(void);
int					ft_atoi(const char *str);
int					str_is_valid(char *c);
int					ft_parse(int argc, char **argv, t_threads *threads);
int					ft_strcmp(char *s1, char *s2);
t_philo				*init_philo(t_threads *threads);
void				ft_mutex_init(t_threads *thread);
void				print(char *message, t_philo *philo);
void				ft_thread(t_threads *philo);
void				*ft_sup(void *threads);
void				ft_eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);
void				mutex_destroy(t_threads *thread, int i);
void				*routine(t_philo *philos);
void				ft_kill(t_threads *thread);
void				*count(void	*thread);
#endif

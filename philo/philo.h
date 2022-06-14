/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:43:56 by ahakam            #+#    #+#             */
/*   Updated: 2022/06/02 21:59:07 by ahakam           ###   ########.fr       */
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

typedef struct s_philo
{
	unsigned long long	last_meal;
	int					id;
	int					lfork;
	int					rfork;
	int					number_of_time_eat;
	int					is_eating;
	pthread_mutex_t		eat;
	struct s_threads	*thread;
}	t_philo;

typedef struct s_threads
{
	unsigned long long	time;
	int					forks;
	int					philo_num;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					number_of_time_to_eat;
	int					eat_counter;
	pthread_mutex_t		*fork;
	pthread_mutex_t		write;
	struct s_philo		*philosopher;

}	t_threads;

unsigned long long	ft_get_time(void);
int					ft_atoi(const char *str);
int					str_is_valid(char *c);
int					ft_parse(int argc, char **argv, t_threads *threads);
int					ft_strcmp(char *s1, char *s2);
t_philo				*init_philo(t_threads *threads);
t_philo				*init_philo(t_threads *threads);
void				ft_mutex_init(t_threads *thread);
void				print(char *message, t_philo *philo);
void				ft_thread(t_threads *philo);
void				ft_sup(t_threads *god);
void				ft_eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);
void				*routine(void *philos);
#endif

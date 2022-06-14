/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:43:29 by ahakam            #+#    #+#             */
/*   Updated: 2022/06/14 11:59:00 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_threads *threads)
{
	int		i;
	t_philo	*philosopher;

	i = 0;
	philosopher = malloc(sizeof(t_philo) * threads->philo_num);
	while (i < threads->philo_num)
	{
		philosopher[i].is_eating = 0;
		philosopher[i].id = i + 1;
		philosopher[i].number_of_time_eat = 0;
		pthread_mutex_init(&philosopher[i].eat, NULL);
		philosopher[i].rfork = (i + 1) % threads->philo_num;
		philosopher[i].lfork = i;
		philosopher[i].thread = threads;
		i++;
	}
	return (philosopher);
}

void	ft_mutex_init(t_threads *thread)
{
	int	i;

	i = 0;
	thread->fork = malloc(sizeof(pthread_mutex_t) * (thread->philo_num));
	pthread_mutex_init(&(thread->write), NULL);
	while (i < thread->philo_num)
		pthread_mutex_init(&thread->fork[i++], NULL);
}

unsigned long long	ft_get_time(void)
{
	struct timeval		current_time;
	unsigned long long	i;

	gettimeofday(&current_time, NULL);
	i = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (i);
}

void	print(char *message, t_philo *philo)
{
	unsigned long long	time;

	time = (ft_get_time() - philo->thread->time);
	pthread_mutex_lock(&(philo->thread->write));
	printf("%lld\t%d\t", time, philo->id);
	printf("%s", message);
	if (ft_strcmp(message, "died\n") > 0)
		pthread_mutex_unlock(&(philo->thread->write));
}

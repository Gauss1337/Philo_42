/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:58:30 by ahakam            #+#    #+#             */
/*   Updated: 2022/06/14 11:25:47 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->thread->fork[philo->lfork]));
	print("taking left fork\n", philo);
	pthread_mutex_lock(&(philo->thread->fork[philo->rfork]));
	print("taking right fork\n", philo);
	pthread_mutex_lock(&(philo->eat));
	print("starting eating\n", philo);
	philo->last_meal = ft_get_time();
	philo->number_of_time_eat++;
	philo->is_eating = 1;
	if (philo->number_of_time_eat == philo->thread->number_of_time_to_eat)
		philo->thread->eat_counter++;
	usleep(philo->thread->time_to_eat * 1000 - 15000);
	while (ft_get_time() - philo->last_meal
		< (unsigned long long) philo->thread->time_to_eat);
	pthread_mutex_unlock(&(philo->eat));
	philo->is_eating = 0;
}

void	ft_sleep(t_philo *philo)
{
	unsigned long long	time;

	time = ft_get_time();
	pthread_mutex_unlock(&(philo->thread->fork[philo->lfork]));
	pthread_mutex_unlock(&(philo->thread->fork[philo->rfork]));
	print("sleeping\n", philo);
	usleep((philo->thread->time_to_sleep * 1000) - 15000);
	while (ft_get_time() - time
		< (unsigned long long) philo->thread->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	print("is thinking\n", philo);
}

void	*routine(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (1)
	{
		ft_think(philo);
		ft_eat(philo);
		ft_sleep(philo);
		usleep(100);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:58:30 by ahakam            #+#    #+#             */
/*   Updated: 2022/06/14 07:40:34 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->thread->fork);
	print("taking lfork", philo);
	sem_wait(philo->thread->fork);
	print("taking rfork", philo);
	sem_wait(philo->thread->eat);
	print("start eating", philo);
	philo->last_meal = ft_get_time();
	philo->is_eating = 1;
	philo->number_of_time_eat++;
	usleep(philo->thread->time_to_eat * 1000 - 14000);
	while (ft_get_time() - philo->last_meal
		< (unsigned long long)philo->thread->time_to_eat);
	sem_post(philo->m_eat);
	sem_post(philo->thread->eat);
	philo->is_eating = 0;
}

void	ft_sleep(t_philo *philo)
{
	unsigned long long	time;

	time = ft_get_time();
	sem_post(philo->thread->fork);
	sem_post(philo->thread->fork);
	print("sleeping", philo);
	usleep(philo->thread->time_to_sleep * 1000 - 14000);
	while (ft_get_time() - time
		< (unsigned long long) philo->thread->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	print("is thinking", philo);
}

void	*routine(t_philo *philo)
{
	philo->last_meal = ft_get_time();
	while (1)
	{
		ft_think(philo);
		ft_eat(philo);
		ft_sleep(philo);
		usleep(100);
	}
	return (NULL);
}

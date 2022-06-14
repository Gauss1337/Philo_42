/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:43:29 by ahakam            #+#    #+#             */
/*   Updated: 2022/06/14 07:34:17 by ahakam           ###   ########.fr       */
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
		philosopher[i].thread = threads;
		sem_unlink("eat");
		philosopher[i].m_eat = sem_open("eat", O_CREAT, 0644, 0);
		i++;
	}
	return (philosopher);
}

unsigned long long	ft_get_time(void)
{
	unsigned long long	i;
	struct timeval		current_time;

	gettimeofday(&current_time, NULL);
	i = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (i);
}

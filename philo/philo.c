/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:43:44 by ahakam            #+#    #+#             */
/*   Updated: 2022/06/14 11:56:11 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_thread(t_threads *philo)
{
	int			i;
	pthread_t	tid;

	i = 0;
	philo->time = ft_get_time();
	while (i < philo->philo_num)
	{
		philo->philosopher[i].last_meal = ft_get_time();
		if (pthread_create(&tid, NULL, &routine, &philo->philosopher[i]) != 0)
		{
			write(2, "thread failed !\n", 17);
			return ;
		}
		usleep(100);
		i++;
	}
}

void	mutex_destroy(t_threads *thread)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(thread->write));
	pthread_mutex_destroy(&(thread->philosopher->eat));
	while (i < thread->philo_num)
	{
		pthread_mutex_destroy(&thread->fork[i]);
		i++;
	}
}

void	ft_sup(t_threads *super)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < super->philo_num)
		{
			if ((ft_get_time() >= ((unsigned long long)super->time_to_die
						+ super->philosopher[i].last_meal))
				&& super->philosopher[i].is_eating == 0)
			{
				pthread_mutex_lock(&(super->philosopher[i].eat));
				print("died\n", &super->philosopher[i]);
				pthread_mutex_unlock(&(super->philosopher[i].eat));
				mutex_destroy(super);
				return ;
			}
			else if (super->philo_num == super->eat_counter)
			{
				mutex_destroy(super);
				return ;
			}
		}
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	t_threads	thread;

	if (ft_parse(argc, argv, &thread))
	{
		write(1, "argument not valid!\n", 21);
		return (0);
	}
	if (thread.philo_num == 0)
		return (1);
	ft_mutex_init(&thread);
	ft_thread(&thread);
	ft_sup(&thread);
	return (0);
}

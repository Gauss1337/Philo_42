/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:43:44 by ahakam            #+#    #+#             */
/*   Updated: 2022/06/14 07:42:36 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*ft_sup(void *threads)
{
	int		i;
	t_philo	*super;

	super = (t_philo *) threads;
	while (1)
	{
		if ((ft_get_time() >= ((unsigned long long)super->thread->time_to_die
					+ super->last_meal)) && super->is_eating == 0)
		{
			print("died", super->thread->philosopher);
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	*count(void	*thread)
{
	int			i;
	int			step;
	t_threads	*counter;

	counter = (t_threads *)thread;
	step = 0;
	while (step < counter->number_of_time_to_eat)
	{
		i = 0;
		while (i < counter->philo_num)
			sem_wait(counter->philosopher[i++].m_eat);
		step++;
	}
	sem_wait(counter->write);
	i = 0;
	while (i < counter->philo_num)
		kill(counter->philosopher[i++].pid, SIGKILL);
	return (NULL);
}

void	ft_kill(t_threads *thread)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (i < thread->philo_num)
	{
		waitpid(-1, &x, 0);
		if (WIFEXITED(x) && WEXITSTATUS(x) == 1)
		{
			j = 0;
			while (j < thread->philo_num)
				kill(thread->philosopher[j++].pid, SIGKILL);
		}
		i++;
	}
	exit(0);
}

void	ft_thread(t_threads *threads)
{
	int			i;
	pthread_t	p_t;

	i = -1;
	if (threads->number_of_time_to_eat > 0)
		pthread_create(&p_t, NULL, &count, (void *)threads);
	threads->time = ft_get_time();
	while (++i < threads->philo_num)
	{
		threads->philosopher[i].pid = fork();
		if (threads->philosopher[i].pid < 0)
		{
			write(1, "fork failed!", 12);
			exit(1);
		}
		else if (threads->philosopher[i].pid == 0)
		{
			pthread_create(&p_t, NULL, &ft_sup, &threads->philosopher[i]);
			routine(&threads->philosopher[i]);
			exit(1);
		}
		usleep(100);
	}
	ft_kill(threads);
}

int	main(int argc, char **argv)
{
	t_threads	thread;

	if (ft_parse(argc, argv, &thread))
	{
		write(1, "argument not valid!\n", 21);
		return (0);
	}
	sem_unlink("fork");
	thread.fork = sem_open("fork", O_CREAT, 0644, thread.philo_num);
	sem_unlink("write");
	thread.write = sem_open("write", O_CREAT, 0644, 1);
	sem_unlink("eat");
	thread.eat = sem_open("eat", O_CREAT, 0644, (thread.philo_num) / 2);
	ft_thread(&thread);
	return (0);
}

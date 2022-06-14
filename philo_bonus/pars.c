/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:45:33 by ahakam            #+#    #+#             */
/*   Updated: 2022/06/13 04:58:25 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	str_is_valid(char *c)
{
	int	i;

	i = 0;
	if (c[0] == '+')
		i = 1;
	while (c[i])
	{
		if (c[i] < 48 || c[i] > 57)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_parse(int argc, char **argv, t_threads *threads)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (str_is_valid(argv[i++]) < 0)
			return (1);
	}
	if (argc == 5 || argc == 6)
	{
		if (argv[5])
			threads->number_of_time_to_eat = ft_atoi(argv[5]);
		else
			threads->number_of_time_to_eat = 0;
		threads->philo_num = ft_atoi(argv[1]);
		threads->time_to_die = ft_atoi(argv[2]);
		threads->time_to_sleep = ft_atoi(argv[4]);
		threads->time_to_eat = ft_atoi(argv[3]);
		if (threads->philo_num <= 0)
			return (3);
	}
	else
		return (2);
	threads->philosopher = init_philo(threads);
	return (0);
}

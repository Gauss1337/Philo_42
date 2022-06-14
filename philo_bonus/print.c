/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 04:46:13 by ahakam            #+#    #+#             */
/*   Updated: 2022/06/14 02:54:05 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_print_number(int nb, int fd)
{
	int	num;
	int	length;

	length = 1;
	num = nb / 10;
	while (num > 0)
	{
		length *= 10;
		num /= 10;
	}
	num = nb;
	while (length)
	{
		ft_putchar_fd((char)((nb / length)) + '0', fd);
		nb %= length;
		length /= 10;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	if (nb >= 0)
	{
		ft_print_number(nb, fd);
	}
	else if (nb < 0 && nb != -2147483648)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
		ft_print_number(nb, fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, &*s, 1);
			s++;
		}
	}
}

void	print(char *msg, t_philo *philo)
{
	unsigned long long	time;

	sem_wait(philo->thread->write);
	time = ft_get_time() - philo->thread->time;
	ft_putnbr_fd(time, 1);
	write(1, "\t", 1);
	ft_putnbr_fd(philo->id, 1);
	write (1, "\t", 1);
	ft_putstr_fd(msg, 1);
	write (1, "\n", 1);
	if (ft_strcmp(msg, "died"))
		sem_post(philo->thread->write);
}

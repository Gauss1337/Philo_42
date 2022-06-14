/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:23:42 by ahakam            #+#    #+#             */
/*   Updated: 2022/06/14 07:03:04 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check(unsigned long pt, int s)
{
	if (pt > 9223372036854775807 && s == -1)
		return (0);
	else if (pt > 9223372036854775807)
		return (-1);
	return (pt * s);
}

int	ft_atoi(const char *str)
{
	int				signe;
	unsigned int	res;
	int				i;

	signe = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res += str[i] - 48;
		i++;
	}
	return (ft_check(res, signe));
}

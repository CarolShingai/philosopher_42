/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:22:32 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/03 18:28:34 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_time(void)
{
	long			time;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000LL) + (current_time.tv_usec / 1000LL);
	return (time);
}

void	ft_usleep(long time)
{
	usleep(time * 1000);
}

long	elapsed_time(t_table *table)
{
	long	time;

	time = get_time() - table->start_time;
	return (time);
}

long	ft_atol(const char *str)
{
	long		index;
	long		number;
	int			sign;

	index = 0;
	number = 0;
	sign = 1;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] && (str[index] >= '0' && str[index] <= '9'))
	{
		number = (number * 10) + (str[index] - '0');
		index++;
	}
	return (number * sign);
}

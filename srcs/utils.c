/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:09:11 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/27 17:52:49 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// Remove time
void	print_mutex(t_philo *philo, t_life status)
{
	struct timeval	now;
	// struct timeval	start;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(philo->print);
	if (status == TAKE_FORK)
		printf("time:%ld philosopher:%d has taken a fork\n", elapsed_time(philo->table), philo->id);
	else if (status == EATING)
		printf("time:%ld philosopher %d is eating\n", elapsed_time(philo->table), philo->id);
	else if (status == SLEEPING)
		printf("time:%ld philosopher %d is sleeping\n", elapsed_time(philo->table), philo->id);
	else if (status == THINKING)
		printf("time:%ld philosopher %d is thinking\n", elapsed_time(philo->table), philo->id);
	pthread_mutex_unlock(philo->print);
}

int	ft_isdigit(int c)
{
	if (48 <= c && c < 58)
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

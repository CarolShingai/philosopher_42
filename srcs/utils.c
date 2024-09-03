/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:09:11 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/02 21:16:27 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_mutex(t_philo *philo, t_life status)
{
	pthread_mutex_lock(&philo->table->print);
	if (status == TAKE_FORK)
		printf("time:%ld philosopher:%d has taken a fork\n", elapsed_time(philo->table), philo->id);
	else if (status == EATING)
		printf("time:%ld philosopher %d is eating\n", elapsed_time(philo->table), philo->id);
	else if (status == SLEEPING)
		printf("time:%ld philosopher %d is sleeping\n", elapsed_time(philo->table), philo->id);
	else if (status == THINKING)
		printf("time:%ld philosopher %d is thinking\n", elapsed_time(philo->table), philo->id);
	else
		printf("time:%ld philosopher %d is dead\n", elapsed_time(philo->table), philo->id);
	pthread_mutex_unlock(&philo->table->print);
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

// void	ft_free(t_table table)

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:09:11 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/09 21:17:03 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_mutex(t_philo *philo, t_life status)
{
	int		status_death;
	long	time_now;

	time_now = elapsed_time(philo->table);
	if (status != DIED)
		pthread_mutex_lock(&philo->table->mutex_monitor);
	status_death = philo->table->simulation == TRUE;
	if (status != DIED)
		pthread_mutex_unlock(&philo->table->mutex_monitor);
	pthread_mutex_lock(&philo->table->print);
	if (status == DIED)
		printf("%ld %d is dead 🪦\n", time_now, philo->id);
	else if (status_death)
	{
		if (status == TAKE_FORK)
			printf(GREEN"%ld %d has taken a fork\n"RESET,
				time_now, philo->id);
		else if (status == EATING)
			printf(ORANGE"%ld %d is eating 🍕\n"RESET,
				time_now, philo->id);
		else if (status == SLEEPING)
			printf(PURPLE"%ld %d is sleeping 😴\n"RESET,
				time_now, philo->id);
		else if (status == THINKING)
			printf(BLUE"%ld %d is thinking 💭\n"RESET,
				time_now, philo->id);
	}
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
	while (str[i])
		i++;
	return (i);
}

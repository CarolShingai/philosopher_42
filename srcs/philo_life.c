/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:29:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/09 20:37:16 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_life(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->table->mutex_monitor);
	i = philo->table->simulation == TRUE;
	pthread_mutex_unlock(&philo->table->mutex_monitor);
	return (i);
}

void	*philo_life(void *arg)
{
	static void	(*f[4])(t_philo *) = {take_fork, eating, sleeping, thinking};
	t_philo		*philo;
	int			i;
	int			meals_count;

	philo = (t_philo *) arg;
	i = 0;
	while (check_life(philo))
	{
		f[i](philo);
		i++;
		if (i == 4)
			i = 0;
		pthread_mutex_lock(&philo->table->mutex_monitor);
		meals_count = philo->meals_count;
		pthread_mutex_unlock(&philo->table->mutex_monitor);
		if (philo->table->max_meals != -1
			&& meals_count >= philo->table->max_meals)
			break ;
	}

	if (i == 1)
	{
		pthread_mutex_unlock(&philo->right_fork->fork);
		pthread_mutex_unlock(&philo->left_fork->fork);
	}

	return (NULL);
}

void	*life_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_mutex(philo, TAKE_FORK);
	return (NULL);
}

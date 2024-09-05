/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:43:54 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/05 18:44:27 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	eating(t_philo *philo)
{
	print_mutex(philo, EATING);
	pthread_mutex_lock(&philo->table->mutex_monitor);
	philo->meals_count++;
	pthread_mutex_unlock(&philo->table->mutex_monitor);
	pthread_mutex_lock(&philo->table->mutex_all);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->table->mutex_all);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
}

void	thinking(t_philo *philo)
{
	print_mutex(philo, THINKING);
	// ft_usleep(10);
}

void	sleeping(t_philo *philo)
{
	print_mutex(philo, SLEEPING);
	ft_usleep(philo->table->time_to_eat);
}

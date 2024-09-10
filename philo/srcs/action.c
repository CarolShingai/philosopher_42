/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:43:54 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/10 16:48:53 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	eating(t_philo *philo)
{
	print_mutex(philo, EATING);
	pthread_mutex_lock(&philo->table->mutex_monitor);
	philo->meals_count++;
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->table->mutex_monitor);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
}

void	thinking(t_philo *philo)
{
	print_mutex(philo, THINKING);
}

void	sleeping(t_philo *philo)
{
	print_mutex(philo, SLEEPING);
	ft_usleep(philo->table->time_to_eat);
}

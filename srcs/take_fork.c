/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:25:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/03 18:11:42 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_fork(t_philo *philo)
{
	if (philo->preference == RIGHT)
		right_hand(philo);
	else
		left_hand(philo);
}

void	right_hand(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->fork);
	pthread_mutex_lock(&philo->left_fork->fork);
	pthread_mutex_lock(&philo->table->mutex_all_2);
	if (philo->table->rip_philo == FALSE)
	{
		print_mutex(philo, TAKE_FORK);
		print_mutex(philo, TAKE_FORK);
	}
	pthread_mutex_unlock(&philo->table->mutex_all_2);
}

void	left_hand(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork);
	pthread_mutex_lock(&philo->right_fork->fork);
	pthread_mutex_lock(&philo->table->mutex_all_2);
	if (philo->table->rip_philo == FALSE)
	{
		print_mutex(philo, TAKE_FORK);
		print_mutex(philo, TAKE_FORK);
	}
	pthread_mutex_unlock(&philo->table->mutex_all_2);
}

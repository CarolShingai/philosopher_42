/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:25:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/02 20:26:43 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_fork(t_philo *philo)
{
	if (philo->preference == RIGHT)
	{
		right_hand(philo);
		left_hand(philo);
	}
	else
	{
		left_hand(philo);
		right_hand(philo);
	}
	// pthread_mutex_lock(&philo->table->mutex_all_2);
	// philo->life_status = EATING;
	// pthread_mutex_unlock(&philo->table->mutex_all_2);
}

void	right_hand(t_philo *philo)
{
	int	lock;

	lock = pthread_mutex_lock(&philo->right_fork->fork);
	if (lock != 0)
		printf("Error in lock function\n");
	print_mutex(philo, TAKE_FORK);
}

void	left_hand(t_philo *philo)
{
	int	lock;

	lock = pthread_mutex_lock(&philo->left_fork->fork);
	if (lock != 0)
		printf("Error in lock function\n");
	print_mutex(philo, TAKE_FORK);
}

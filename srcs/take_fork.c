/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:25:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/09 20:10:09 by cshingai         ###   ########.fr       */
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
	print_mutex(philo, TAKE_FORK);
	pthread_mutex_lock(&philo->left_fork->fork);
	print_mutex(philo, TAKE_FORK);
}

void	left_hand(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork);
	print_mutex(philo, TAKE_FORK);
	pthread_mutex_lock(&philo->right_fork->fork);
	print_mutex(philo, TAKE_FORK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:25:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/22 20:08:14 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_fork(t_philo *philo)
{
	printf("fork: entrou\n");
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
}

void	right_hand(t_philo *philo)
{
	int	lock;

	lock = pthread_mutex_lock(&philo->right_fork->fork);
	if (lock != 0)
		printf("Error in lock function\n");
	printf("time:%ld philosopher:%d has taken a fork\n", get_time() ,philo->id);
}

void	left_hand(t_philo *philo)
{
	int	lock;

	lock = pthread_mutex_lock(&philo->left_fork->fork);
	if (lock != 0)
		printf("Error in lock function\n");
	printf("time: %ld philosopher:%d has taken a fork\n", get_time(), philo->id);
}

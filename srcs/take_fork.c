/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:25:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/21 17:46:44 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_fork(t_philo *philo)
{
	// printf("fork: entrou\n");
	if (philo->preference == RIGHT)
	{
		right_hand(philo);
		left_hand(philo, philo->id);
	}
	else
	{
		left_hand(philo, philo->id);
		right_hand(philo);
	}

}

void	right_hand(t_philo *philo)
{
	int	lock;
	if (philo->right_fork.fork_status == TRUE)
	{
		lock = pthread_mutex_lock(&*philo->right_fork.fork);
		if (lock != 0)
			printf("Error in lock function\n");
		printf("%d has taken a fork\n", philo->id);
	}
}

void	left_hand(t_philo *philo, int i)
{
	int	lock;
	if (philo[i].left_fork.fork_status == TRUE)
	{
		lock = pthread_mutex_lock(&*philo->left_fork.fork);
		if (lock != 0)
			printf("Error in lock function\n");
		printf("%d has taken a fork\n", philo->id);
	}
}

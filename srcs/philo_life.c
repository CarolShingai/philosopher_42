/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:29:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/21 17:30:54 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo == NULL)
		perror("philo is NULL");
	//deadlock ocorrendo
	printf("philo function: entrou\n");
	while(1)
	{
		take_fork(philo);
		// if (philo->life_status == EATING)
		// {
		// 	eating(philo);
		// 	philo->life_status = THINKING;
		// }
		// else if (philo->life_status == THINKING)
		// {
		// 	printf("entrou");
		// 	thinking(philo);
		// 	philo->life_status = SLEEPING;
		// }
		// else if (philo->life_status == SLEEPING)
		// {
		// 	sleeping(philo);
		// 	philo->life_status = EATING;
		// }
	}
	return(NULL);
}

void	eating(t_philo *philo)
{
	philo->right_fork.fork_status = FALSE;
	philo->left_fork.fork_status = FALSE;
	pthread_mutex_lock(philo->right_fork.fork);
	pthread_mutex_lock(philo->left_fork.fork);
	printf("Philosopher %d is eating\n", philo->id);
	philo->meals_count++;
	pthread_mutex_unlock(philo->right_fork.fork);
	pthread_mutex_unlock(philo->left_fork.fork);
	philo->left_fork.fork_status = TRUE;
	philo->right_fork.fork_status = TRUE;
}

void	thinking(t_philo *philo)
{
	philo->right_fork.fork_status = FALSE;
	philo->left_fork.fork_status = FALSE;
	pthread_mutex_lock(philo->right_fork.fork);
	pthread_mutex_lock(philo->left_fork.fork);
	printf("Philosopher %d is thinking\n", philo->id);
	pthread_mutex_unlock(philo->right_fork.fork);
	pthread_mutex_unlock(philo->left_fork.fork);
	philo->left_fork.fork_status = TRUE;
	philo->right_fork.fork_status = TRUE;
}

void   sleeping(t_philo *philo)
{
	printf("Philosopher %d is sleeping\n", philo->id);
	usleep(1000);
}

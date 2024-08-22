/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:29:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/22 20:06:22 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo == NULL)
		perror("philo is NULL");
	printf("philo function: entrou\n");
	while (1)
	{
		if (philo->life_status == EATING)
			eating(philo);
		else if (philo->life_status == SLEEPING)
			sleeping(philo);
		else if (philo->life_status == THINKING)
			thinking(philo);
	}
	return(NULL);
}

void	eating(t_philo *philo)
{
	take_fork(philo);
	printf("Philosopher %d is eating\n", philo->id);
	philo->meals_count++;
	ft_usleep(philo->table->time_to_eat * 1000);
	// usleep(100000);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
	philo->life_status = SLEEPING;
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->fork);
	pthread_mutex_lock(&philo->left_fork->fork);
	printf("Philosopher %d is thinking\n", philo->id);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
	philo->life_status = EATING;
}

void	sleeping(t_philo *philo)
{
	printf("Philosopher %d is sleeping\n", philo->id);
	ft_usleep(philo->table->time_to_eat * 1000);
	// usleep(philo->table->time_to_sleep);
	// usleep(100000);
	philo->life_status = THINKING;
}

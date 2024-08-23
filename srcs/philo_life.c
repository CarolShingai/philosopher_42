/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:29:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/23 20:44:30 by cshingai         ###   ########.fr       */
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
		if (philo->life_status == TAKE_FORK)
			take_fork(philo);
		if (philo->life_status == EATING)
			eating(philo);
		else if (philo->life_status == SLEEPING)
			sleeping(philo);
		else if (philo->life_status == THINKING)
			thinking(philo);
		if (philo->table->max_meals != -1 && philo->meals_count < philo->table->max_meals)
			break ;
	}
	return(NULL);
}

void	eating(t_philo *philo)
{
	// printf("Philosopher %d is eating\n", philo->id);
	print_mutex(philo, philo->life_status);
	philo->meals_count++;
	ft_usleep(philo->table->time_to_eat);
	// usleep(100000);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
	philo->life_status = SLEEPING;
}

void	thinking(t_philo *philo)
{
	// pthread_mutex_lock(&philo->right_fork->fork);
	// pthread_mutex_lock(&philo->left_fork->fork);
	// printf("Philosopher %d is thinking\n", philo->id);
	print_mutex(philo, philo->life_status);
	// pthread_mutex_unlock(&philo->right_fork->fork);
	// pthread_mutex_unlock(&philo->left_fork->fork);
	philo->life_status = EATING;
}

void	sleeping(t_philo *philo)
{
	// printf("Philosopher %d is sleeping\n", philo->id);
	print_mutex(philo, philo->life_status);
	ft_usleep(philo->table->time_to_eat);
	// usleep(philo->table->time_to_sleep);
	// usleep(100000);
	philo->life_status = THINKING;
}

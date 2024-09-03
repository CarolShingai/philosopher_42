/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:29:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/02 21:16:18 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_life(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->table->mutex_all_2);
	if (philo->table->rip_philo == TRUE)
		i = 0;
	else
		i = 1;
	pthread_mutex_unlock(&philo->table->mutex_all_2);
	return (i);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	static void (*f[4])(t_philo *) = {take_fork, eating, sleeping, thinking};
	int	i;

	philo = (t_philo *) arg;
	i = 0;
	if (philo == NULL)
		perror("philo is NULL");
	while (check_life(philo) == 1)
	{
		f[i](philo);
		i++;
		if (i == 4)
			i = 0;
		if (philo->table->max_meals != -1
			&& philo->meals_count >= philo->table->max_meals)
			break ;
	}
	return(NULL);
}

void	eating(t_philo *philo)
{
	// printf("Philosopher %d is eating\n", philo->id);
	print_mutex(philo, EATING);
	pthread_mutex_lock(&philo->table->mutex_all);
	philo->meals_count++;
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->table->mutex_all);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
}

void	thinking(t_philo *philo)
{
	print_mutex(philo, THINKING);
	// pthread_mutex_lock(&philo->table->mutex_all_2);
	// philo->life_status = EATING;
	// pthread_mutex_unlock(&philo->table->mutex_all_2);
}

void	sleeping(t_philo *philo)
{
	print_mutex(philo, SLEEPING);
	ft_usleep(philo->table->time_to_eat);
	// pthread_mutex_lock(&philo->table->mutex_all_2);
	// philo->life_status = THINKING;
	// pthread_mutex_unlock(&philo->table->mutex_all_2);
}

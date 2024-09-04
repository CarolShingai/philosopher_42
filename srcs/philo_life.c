/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:29:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/03 20:49:30 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_life(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->table->mutex_all_2);
	i = philo->table->rip_philo != TRUE;
	pthread_mutex_unlock(&philo->table->mutex_all_2);
	return (i);
}

void	*philo_life(void *arg)
{
	static void	(*f[4])(t_philo *) = {take_fork, eating, sleeping, thinking};
	t_philo		*philo;
	int			i;

	philo = (t_philo *) arg;
	i = 0;
	if (philo == NULL)
		write(2, "philo is NULL", 14);
	while (check_life(philo))
	{
		f[i](philo);
		i++;
		if (i == 4)
			i = 0;
		if (philo->table->max_meals != -1
			&& philo->meals_count >= philo->table->max_meals)
			break ;
	}
	if (i == 1)
	{
		pthread_mutex_unlock(&philo->right_fork->fork);
		pthread_mutex_unlock(&philo->left_fork->fork);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
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
}

void	sleeping(t_philo *philo)
{
	print_mutex(philo, SLEEPING);
	ft_usleep(philo->table->time_to_eat);
}

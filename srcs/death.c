/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:08:27 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/03 18:21:41 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_bool	is_philo_dead(t_philo *philo)
{
	long		last_meal;
	long		since_last_meal;

	pthread_mutex_lock(&philo->table->mutex_all);
	last_meal = philo->last_meal_time;
	pthread_mutex_unlock(&philo->table->mutex_all);
	since_last_meal = get_time() - last_meal;
	if (since_last_meal > philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->table->mutex_all_2);
		philo->life_status = DIED;
		philo->table->rip_philo = TRUE;
		pthread_mutex_unlock(&philo->table->mutex_all_2);
		print_mutex(philo->table->philo, DIED);
		return (TRUE);
	}
	else
		return (FALSE);
}

void	*monitoring(void *arg)
{
	int		i;
	t_table	*table;

	i = 0;
	table = (t_table *) arg;
	while (1)
	{
		ft_usleep(100);
		pthread_mutex_lock(&table->death_checker);
		if (i == table->nbr_philo)
			i = 0;
		if (is_philo_dead(table->philo) == TRUE)
		{
			pthread_mutex_unlock(&table->death_checker);
			break ;
		}
		i++;
		pthread_mutex_unlock(&table->death_checker);
	}
	return (NULL);
}

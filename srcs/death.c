/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:08:27 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/09 21:03:25 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_bool	is_philo_dead(t_philo *philo)
{
	long		last_meal;
	long		since_last_meal;

	last_meal = philo->last_meal_time;
	since_last_meal = get_time() - last_meal;
	if (since_last_meal > philo->table->time_to_die)
	{
		philo->table->simulation = FALSE;
		print_mutex(philo->table->philo, DIED);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	reach_max_meals(t_table *table)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (i < table->nbr_philo)
	{
		if (table->max_meals == table->philo[i].meals_count)
			n++;
		i++;
	}
	if (n == table->nbr_philo)
	{
		table->simulation = FALSE;
		return (TRUE);
	}
	return (FALSE);
}

void	*monitoring(void *arg)
{
	int		i;
	t_table	*table;
	t_bool	everyone_ate;
	t_bool	someone_died;

	i = 0;
	table = (t_table *) arg;
	everyone_ate = 0;
	someone_died = 0;
	while (1)
	{
		pthread_mutex_lock(&table->mutex_monitor);
		everyone_ate = reach_max_meals(table);
		someone_died = is_philo_dead(table->philo) == TRUE;
		pthread_mutex_unlock(&table->mutex_monitor);
		if (i == table->nbr_philo)
			i = 0;
		if (everyone_ate || someone_died)
			break ;
		i++;
		usleep(500);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:08:27 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/28 20:50:15 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	is_philo_dead(t_philo *philo)
{
	long		now;
	long		last_meal;
	long		since_last_meal;

	now = elapsed_time(philo->table);
	last_meal = philo->last_meal_time;
	since_last_meal = now - last_meal;
	printf("slm:%ld\n", since_last_meal);
	if (since_last_meal > philo->table->time_to_die)
		philo->life_status = DIED;
}

void	monitoring(t_table *table)
{
	if (create_thread(table) == TRUE && table->philo->life_status != DIED)
	{
		is_philo_dead(table->philo);
		// if (table->philo->life_status == DIED)
		// {
			print_mutex(table->philo, table->philo->life_status);
			// break ;
		// }
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:48:10 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/03 18:25:30 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_mutex(t_table *table)
{
	int	i;
	int	result;

	i = 0;
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->death_checker, NULL);
	pthread_mutex_init(&table->mutex_all, NULL);
	pthread_mutex_init(&table->mutex_all_2, NULL);
	while (i < table->nbr_philo)
	{
		result = pthread_mutex_init(&table->fork[i].fork, NULL);
		i++;
	}
}

void	destroy_mutex(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->death_checker);
	pthread_mutex_destroy(&table->mutex_all);
	pthread_mutex_destroy(&table->mutex_all_2);
	while (i < table->nbr_philo)
	{
		pthread_mutex_destroy(&table->fork[i].fork);
		i++;
	}
}

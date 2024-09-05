/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:19:55 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/05 20:04:36 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	create_thread(t_table *table)
{
	int	i;
	int	n_create;

	i = 0;
	while (i < table->nbr_philo)
	{
		n_create = pthread_create(&table->philo[i].philosopher, NULL,
				philo_life, &table->philo[i]);
		i++;
	}
}

void	create_one(t_table *table)
{
	int	n_create;

	n_create = pthread_create(&table->philo[0].philosopher, NULL,
		life_one, &table->philo[0]);
}

void	join_thread(t_table *table)
{
	int	i;
	int	n_join;

	i = 0;
	while (i < table->nbr_philo)
	{
		n_join = pthread_join(table->philo[i].philosopher, NULL);
		if (n_join != 0)
			write(2, "Error joining thread.", 22);
		i++;
	}
	pthread_join(table->monitor, NULL);
}

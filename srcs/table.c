/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:03:49 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/03 20:43:34 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	set_table(t_table *table, char **argv)
{
	table->nbr_philo = ft_atol(argv[1]);
	table->philo = malloc(sizeof(t_philo) * table->nbr_philo);
	table->fork = malloc(sizeof(t_fork) * table->nbr_philo);
	table->start_time = get_time();
	table->philo->last_meal_time = get_time();
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->rip_philo = FALSE;
	table->end = FALSE;
	if (argv[5])
		table->max_meals = ft_atol(argv[5]);
	else
		table->max_meals = -1;
	init_mutex(table);
	set_philosophers(table, table->nbr_philo);
	create_thread(table);
	pthread_create(&table->monitor, NULL, monitoring, table);
	join_thread(table);
	destroy_mutex(table);
}

void	set_philosophers(t_table *table, int nbr)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < nbr)
	{
		philo = &table->philo[i];
		philo->id = i + 1;
		philo->preference = philo_laterality(philo);
		philo->right_fork = &table->fork[i];
		philo->left_fork = &table->fork[(i + 1) % nbr];
		philo->table = table;
		philo->meals_count = 0;
		philo->life_status = TAKE_FORK;
	}
}

t_fork_preference	philo_laterality(t_philo *philo)
{
	if (philo->id % 2 != 0)
		return (RIGHT);
	else
		return (LEFT);
}

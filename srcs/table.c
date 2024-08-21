/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:03:49 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/19 18:48:52 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	set_table(t_table *table, char *argv)
{	
	table->nbr_philo = atol(argv);
	table->philo = malloc(sizeof(t_philo) * table->nbr_philo);
	table->fork = malloc(sizeof(t_fork) * table->nbr_philo);
	set_philosophers(table, table->nbr_philo);
	init_mutex(table);
	create_thread(table);
	join_thread(table);
	destroy_mutex(table);
}

void	set_philosophers(t_table *table, int nbr)
{
	int i;
	t_philo *philo;
	i = -1;
	
	while (++i < nbr)
	{
		philo = &table->philo[i];
		philo->id = i + 1;
		assign_fork(table);
		philo->life_status = EATING;
		philo->preference = philo_laterality(philo);
		printf("philo id: %d, life: %d\n", table->philo[i].id, table->philo[i].life_status);
	}
}

void	assign_fork(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->nbr_philo && table->philo->preference == RIGHT)
	{
		table->philo[i].left_fork.fork_id = (i + 1) % table->nbr_philo;
		table->philo[i].right_fork.fork_id = i;
	}
	while (++i < table->nbr_philo && table->philo->preference == LEFT)
	{
		table->philo[i].right_fork.fork_id = i;
		table->philo[i].left_fork.fork_id = (i + 1) % table->nbr_philo;
	}
}
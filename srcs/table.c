/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:03:49 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/21 17:43:45 by cshingai         ###   ########.fr       */
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
		philo->right_fork.fork = malloc (sizeof (pthread_mutex_t));
		philo->left_fork.fork = malloc (sizeof (pthread_mutex_t));
		philo->life_status = EATING;
		philo->preference = philo_laterality(philo);
		philo->right_fork.fork_status = TRUE;
		philo->left_fork.fork_status = TRUE;
	}
}

void	assign_fork(t_table *table)
{
	int	i;

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

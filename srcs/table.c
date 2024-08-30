/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:03:49 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/29 20:54:52 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	set_table(t_table *table, char **argv)
{
	table->nbr_philo = atol(argv[1]);
	table->philo = malloc(sizeof(t_philo) * table->nbr_philo);
	table->fork = malloc(sizeof(t_fork) * table->nbr_philo);
	table->start_time = get_time();
	table->time_to_die = atol(argv[2]);
	table->time_to_eat = atol(argv[3]);
	table->time_to_sleep = atol(argv[4]);
	table->rip_var = FALSE;
	if (argv[5])
		table->max_meals = atol(argv[5]);
	else
		table->max_meals = -1;
	init_mutex(table);
	set_philosophers(table, table->nbr_philo);
	// monitoring(table);
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
		philo->id = i;
		philo->preference = philo_laterality(philo);
		philo->right_fork = &table->fork[i];
		philo->left_fork = &table->fork[(i + 1) % nbr];
		philo->table = table;
		philo->meals_count = 0;
		// assign_fork(philo);
		philo->life_status = TAKE_FORK;
		// philo->right_fork.fork_status = TRUE;
		// philo->left_fork.fork_status = TRUE;
		// &data->forks_mutex[(i + data->philos_count - 1) % data->philos_count];
		// assign_fork(table);
		// table->philo[i].left_fork.fork_id = (i + 1) % table->nbr_philo;
		// table->philo[i].right_fork.fork_id = i;
	}
}

// void	assign_fork(t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	if (philo->preference == RIGHT)
// 	{
// 		philo->left_fork = &philo->table->fork[(i + 1) % philo->table->nbr_philo];
// 		philo->right_fork = &philo->table->fork[i];
// 	}
// 	else
// 	{
// 		philo->right_fork = &philo->table->fork[i];
// 		philo->left_fork = &philo->table->fork[(i + 1) % philo->table->nbr_philo];
// 	}

// }

t_fork_preference	philo_laterality(t_philo *philo)
{
	if (philo->id % 2 != 0)
		return (RIGHT);
	else
		return (LEFT);
}

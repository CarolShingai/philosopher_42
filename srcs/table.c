/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:03:49 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/17 20:33:57 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	set_table(t_table *table, char *argv)
{
	table->nbr_philo = atol(argv);
	build_philosophers(table->philo, table->nbr_philo);
	pthread_create(&table->philo->philosopher, NULL, philo_life, NULL);
	pthread_join(&table->philo->philosopher, NULL);
}

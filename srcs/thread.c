/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:19:55 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/18 23:57:48 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void    create_thread(t_table *table)
{
    int i;
    int n_create;

    i = 0;
    while (i < table->nbr_philo)
    {
        n_create = pthread_create(&table->philo[i].philosopher, NULL,
        philo_life, &table->philo[i]);
        if(n_create != 0)
            printf("Error creating thread %d\n", i);
        i++;
    }
}

void    join_thread(t_table *table)
{
    int i;
    int n_join;

    i = 0;
    while (i < table->nbr_philo)
    {
        n_join = pthread_join(table->philo[i].philosopher, NULL);
        if (n_join != 0)
            printf("Error joining thread %d\n", i);
        i++;
    }
}

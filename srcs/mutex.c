/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:48:10 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/21 17:29:17 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void    init_mutex(t_table *table)
{
    int i;

    i = 0;
    while (i < table->nbr_philo)
    {
        table->fork[i].fork = malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(table->fork[i].fork, NULL);
        i++;
    }
}

void   destroy_mutex(t_table *table)
{
    int i;

    i = 0;
    while (i < table->nbr_philo)
    {
        pthread_mutex_destroy(table->fork[i].fork);
        i++;
        free(table->fork[i].fork);
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:22:32 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/21 20:03:46 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_time(void)
{
	long	milliseconds;
	struct timeval	timer;

	gettimeofday(&timer, NULL);
	milliseconds = (timer.tv_sec * 1000LL) + (timer.tv_usec / 1000LL);
	return(milliseconds);
}

void	set_time(t_table *table, char **argv)
{
	table->time_to_die = atol(argv[2]);
	table->time_to_eat = atol(argv[3]);
	table->time_to_sleep = atol(argv[4]);
}

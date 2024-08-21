/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:22:32 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/21 20:30:56 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_time(void)
{
	long	time;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return(time);
}

// void	ft_usleep(long time)
// {
// 	long	start_time;

// 	start_time = 0;

// }

void	set_time(t_table *table, char **argv)
{
	table->time_to_die = atol(argv[2]);
	table->time_to_eat = atol(argv[3]);
	table->time_to_sleep = atol(argv[4]);
}

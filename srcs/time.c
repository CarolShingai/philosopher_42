/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:22:32 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/27 17:22:17 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_time(void)
{
	long	time;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000LL) + (current_time.tv_usec / 1000LL);
	return(time);
}

void	ft_usleep(long time)
{
	// long	start;

	// start = get_time();

	// while(get_time() - start < time)
	// 	usleep(time / 10);
	usleep(time * 1000);
}

long	elapsed_time(t_table *table)
{
	long	time;

	time = get_time() - table->start_time;
	return(time);
}

// void	set_time(t_table *table, char **argv)
// {

// }

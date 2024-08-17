/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:47:24 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/17 20:33:44 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->life_status == EATING && take_fork(philo))
	{
		printf("eating");
		philo->life_status = THINKING;
	}
	else if (philo->life_status == THINKING)
		printf("thinking");
	return(NULL);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (philo_checker(argc, argv[1]))
	{
		set_table(&table, argv[1]);

	}
}

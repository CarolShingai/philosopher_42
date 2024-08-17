/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:47:24 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/17 18:30:00 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->life_status.init && take_fork(philo))
	{
		printf("eating");
		philo->life_status.eating;
	}
	else if (philo->life_status.eating)
		printf("thinking");

}





int	main(int argc, char **argv)
{
	t_philo	*philo;
	int	n = atoi(argv[1]);
	pthread_t	*philopher;
	int id = 1;
	if (philo_checker(argc, argv[1]))
	{
		pthread_create(&*philopher, NULL, philo_life, &id);
		pthread_join(philopher, NULL);
	}
}

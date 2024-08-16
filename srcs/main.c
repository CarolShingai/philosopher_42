/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:47:24 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/16 20:15:09 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*philo_life(void *arg)
{
	int i;

	i = *(int *) arg;
	printf("Philosopher %d: comendo\n", i);
	printf("pensando\n");
	printf("dormindo\n");
	return(NULL);
}


int main(int argc, char **argv)
{
	int	n = atoi(argv[1]);
	pthread_t	philopher[n];
	int id = 1;

	pthread_create(&philopher, NULL, philo_life, &id);
	pthread_join(philopher, NULL);
}

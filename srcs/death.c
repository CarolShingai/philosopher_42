/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:08:27 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/29 21:00:18 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_bool	is_philo_dead(t_philo *philo)
{
	long		last_meal;
	long		since_last_meal;

	last_meal = philo->last_meal_time;
	since_last_meal = get_time() - last_meal;
	// printf("slm:%ld\n", since_last_meal);
	if (since_last_meal > philo->table->time_to_die)
	{
		philo->life_status = DIED;
		// philo->table->rip_var = TRUE;
		print_mutex(philo->table->philo, philo->life_status);
		return(TRUE);
	}
	else
		return(FALSE);
}

/*
A create_thread vai inicialiazr essa função,
mais simples
um loop numa thread separada
checando cada um dos philosophers se estao vivos
*/
void	*monitoring(void *arg)
{
	int	i;
	t_table *table;

	i = 0;
	table = (t_table *) arg;
	while(1)
	{
		ft_usleep(100);
		if (i == table->nbr_philo)
			i = 0;
		if (is_philo_dead(table->philo))
			break ;
		i++;
	}
	print_mutex(table->philo, table->philo->life_status);
	// break ;
	// }
	return (NULL);
}

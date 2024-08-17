/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:17:13 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/17 20:27:51 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	build_philosophers(t_philo *philo, int nbr)
{
	int i = -1;
	while (++i < nbr)
	{
		philo->id += 1;
		philo->right_fork.fork_status = TRUE;
		philo->left_fork.fork_status = TRUE;
		philo->life_status = EATING;
		philo_laterality(philo);
	}
}

void	philo_laterality(t_philo *philo)
{
	if (philo->id % 2 != 0)
		philo->preference = RIGHT;
	else
		philo->preference = LEFT;
}

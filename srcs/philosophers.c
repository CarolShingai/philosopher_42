/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:17:13 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/21 14:22:39 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_fork_preference	philo_laterality(t_philo *philo)
{
	if (philo->id % 2 != 0)
		return (RIGHT);
	else
		return(LEFT);
}

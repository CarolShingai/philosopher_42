/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:25:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/17 20:35:46 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_bool	take_fork(t_philo *philo)
{
	if (philo->preference == RIGHT)
		return(right_hand(philo));
	else
		return(left_hand(philo));
}

t_bool	right_hand(t_philo *philo)
{
	if (philo->preference == RIGHT && philo->right_fork.fork_status == TRUE)
	{
		if (philo->left_fork.fork_status == TRUE)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

t_bool	left_hand(t_philo *philo)
{
	if (philo->preference == LEFT && philo->left_fork.fork_status == TRUE)
	{
		if (philo->right_fork.fork_status == TRUE)
			return (TRUE);
		else
			return(FALSE);
	}
	else
		return(FALSE);
}

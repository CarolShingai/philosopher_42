/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:45:30 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/18 21:30:11 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

//argc must 5 or 6
//argv[1] must no surpace 200
t_bool	philo_checker(int argc, char *argv)
{
	int nbr;

	nbr = atoi(argv);
	if (argc == 2)
	{
		if (nbr > 0 && nbr <= 200)
			return(TRUE);
		else
			return(perror("Invalid number of philosophers."), FALSE);
	}
	else
		return(perror("Invalid number of arguments."), FALSE);
}

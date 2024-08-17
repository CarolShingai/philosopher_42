/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:45:30 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/17 14:45:58 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

//argc must 5 or 6
//argv[1] must no surpace 200
t_bool	philo_checker(int argc, char *argv)
{
	if (argc == 5 || argc == 6)
	{
		if (argv > 0 && argv <= 200)
			return(TRUE);
		else
			return(error("Invalid number of philosophers.") ,FALSE);
	}
	else
		return(error("Invalid number of arguments.") ,FALSE);
}

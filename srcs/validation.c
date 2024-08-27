/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:45:30 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/27 19:15:49 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

//argc must 5 or 6
//argv[1] must no surpace 200
t_bool	philo_checker(int argc, char **argv)
{
	int	nbr;

	nbr = atoi(argv[1]);
	if (argc == 5 || argc == 6)
	{
		if (is_alldigits(argc, argv) == TRUE)
		{
			if (nbr > 0 && nbr <= 200)
				return(TRUE);
			else
				return(perror("Invalid number of philosophers."), FALSE);
		}
		else
			return(perror("Invalid argument."), FALSE);
	}
	else
		return(perror("Invalid number of arguments."), FALSE);
}

t_bool	is_alldigits(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while(++i < argc)
	{
		len = ft_strlen(argv[i]);
		j = 0;
		// printf("char:%s bool:%d\n", &argv[i][j], ft_isdigit(argv[i][j]));
		while (j < len)
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else
				return (FALSE);
		}
	}
	return (TRUE);
}

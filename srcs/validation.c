/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:45:30 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/03 18:32:40 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_bool	philo_checker(int argc, char **argv)
{
	int	nbr;

	nbr = atoi(argv[1]);
	if (argc == 5 || argc == 6)
	{
		if (is_alldigits(argc, argv) == TRUE)
		{
			if (nbr > 0 && nbr <= 200)
				return (TRUE);
			else
				return (write(2, "Invalid number of philosophers.", 32), FALSE);
		}
		else
			return (write(2, "Invalid argument.", 18), FALSE);
	}
	else
		return (write(2, "Invalid number of arguments.", 29), FALSE);
}

t_bool	is_alldigits(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (++i < argc)
	{
		len = ft_strlen(argv[i]);
		j = 0;
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

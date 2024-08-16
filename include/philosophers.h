/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:10:16 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/16 19:44:35 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h> //thread:create, join, mutex:init, destroy, lock, unlock
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_philo
{
	int	id;
	t_bool	right_fork;
	t_bool	left_fork;
}			t_philo;


#endif

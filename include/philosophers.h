/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:10:16 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/17 18:42:28 by cshingai         ###   ########.fr       */
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

typedef enum e_fork_preference
{
	RIGHT = 1,
	LEFT = 0
}	t_fork_preference;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int	fork_id;
}	t_fork;

typedef struct s_life
{
	init;
	eating;
	thinking;
	sleepping;
	died;
}			t_life;

typedef struct s_philo
{
	int	id;
	int	meals_count;
	t_bool	right_fork;
	t_bool	left_fork;
	t_life	life_status;
	t_fork_preference	preference;
	pthread_t	philosopher;
}			t_philo;


//philosophers.c
void	build_philosophers(t_philo *philo, int nbr);
void	philo_laterality(t_philo *philo);

// validation.c
t_bool	philo_checker(int argc, char *argv);

// take_fork.c
t_bool	take_fork(t_philo *philo);
t_bool	right_hand(t_philo *philo);
t_bool	left_hand(t_philo *philo);

#endif

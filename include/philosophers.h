/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:10:16 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/17 20:38:56 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h> //thread:create, join, mutex:init, destroy, lock, unlock
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <errno.h>

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

typedef struct	s_fork
{
	pthread_mutex_t	fork;
	t_bool	fork_status;
	int	fork_id;
}	t_fork;

typedef enum	e_life
{
	EATING,
	THINKING,
	SLEEPING,
	DIED
}			t_life;

typedef struct	s_philo
{
	int	id;
	int	meals_count;
	t_fork	right_fork;
	t_fork	left_fork;
	t_life	life_status;
	t_fork_preference	preference;
	pthread_t	philosopher;
}			t_philo;

typedef struct	s_table
{
	int		nbr_philo;
	t_philo	*philo;
	t_fork	fork;
}			t_table;


//philosophers.c
void	build_philosophers(t_philo *philo, int nbr);
void	philo_laterality(t_philo *philo);

void	*philo_life(void *arg);

// validation.c
t_bool	philo_checker(int argc, char *argv);

// take_fork.c
t_bool	take_fork(t_philo *philo);
t_bool	right_hand(t_philo *philo);
t_bool	left_hand(t_philo *philo);

// table.c
void	set_table(t_table *table, char *argv);

#endif

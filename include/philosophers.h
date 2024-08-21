/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:10:16 by cshingai          #+#    #+#             */
/*   Updated: 2024/08/21 20:35:48 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h> //thread:create, join, mutex:init, destroy, lock, unlock
# include <stdio.h>
# include <unistd.h>
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
	pthread_mutex_t	*fork;
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
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	start_time;
	t_philo	*philo;
	t_fork	*fork;
}			t_table;


//philosophers.c

// philo_life.c
void	*philo_life(void *arg);
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);

// mutex.c
void	init_mutex(t_table *table);
void	destroy_mutex(t_table *table);

// thread.c
void	create_thread(t_table *table);
void	join_thread(t_table *table);

// validation.c
t_bool	philo_checker(int argc, char *argv);

// take_fork.c
void	take_fork(t_philo *philo);
void	right_hand(t_philo *philo);
void	left_hand(t_philo *philo, int i);

// table.c
void	set_table(t_table *table, char *argv);
void	set_philosophers(t_table *table, int nbr);
void	assign_fork(t_table *table);
t_fork_preference	philo_laterality(t_philo *philo);

#endif

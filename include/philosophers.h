/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:10:16 by cshingai          #+#    #+#             */
/*   Updated: 2024/09/03 20:31:05 by cshingai         ###   ########.fr       */
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

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef enum e_life
{
	EATING,
	THINKING,
	SLEEPING,
	TAKE_FORK,
	DIED
}	t_life;

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

struct s_philo
{
	int					id;
	int					meals_count;
	long				last_meal_time;
	t_fork				*right_fork;
	t_fork				*left_fork;
	t_life				life_status;
	t_table				*table;
	t_fork_preference	preference;
	pthread_t			philosopher;
};

struct s_table
{
	int				nbr_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			max_meals;
	long			time_of_last_meal;
	long			start_time;
	pthread_mutex_t	death_checker;
	pthread_mutex_t	print;
	pthread_mutex_t	mutex_all;
	pthread_mutex_t	mutex_all_2;
	pthread_t		monitor;
	t_philo			*philo;
	t_bool			rip_philo;
	t_fork			*fork;
};

// death.c
t_bool				is_philo_dead(t_philo *philo);
void				*monitoring(void *arg);
void	max_meals_free(t_table *table);

// philo_life.c
void				*philo_life(void *arg);
void				eating(t_philo *philo);
void				thinking(t_philo *philo);
void				sleeping(t_philo *philo);

// time.c
long				get_time(void);
long				elapsed_time(t_table *table);
void				set_time(t_table *table, char **argv);
void				ft_usleep(long time);

// mutex.c
void				init_mutex(t_table *table);
void				destroy_mutex(t_table *table);

// take_fork.c
void				take_fork(t_philo *philo);
void				right_hand(t_philo *philo);
void				left_hand(t_philo *philo);

// table.c
void				set_table(t_table *table, char **argv);
void				set_philosophers(t_table *table, int nbr);
void				assign_fork(t_philo *philo);
t_fork_preference	philo_laterality(t_philo *philo);

//the create_thread is where the thread(philosophers) are created
// thread.c
void				create_thread(t_table *table);
void				join_thread(t_table *table);

// validation.c
t_bool				philo_checker(int argc, char **argv);
t_bool				is_alldigits(int argc, char **argv);

// utils.c
void				print_mutex(t_philo *philo, t_life status);
int					ft_isdigit(int c);
int					ft_strlen(char *str);
long				ft_atol(const char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:46:43 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/10 18:13:29 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <fcntl.h>
# include <limits.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pthread.h>
# include <unistd.h>

/*
** defines
 */
# define TRUE			1
# define FALSE			0

typedef enum e_status
{
	EATING = 1,
	SLEEPING,
	THINKING,
	FORK,
	HUNGRY,
	DEAD
}				t_status;

/*
** typdefs
 */
typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				is_running;
	int				is_all_eaten;
	sem_t			*fork;
	sem_t			*print_sem;
	sem_t			*status_sem;
	sem_t			*dead_sem;
	sem_t			*eaten_sem;
	pthread_t		eat_thread;
	pthread_t		die_thread;
	t_philo			*philo;
}					t_info;

typedef struct s_philo
{
	int				idx;
	int				live;
	long			last_eat;
	int				meals;
	pid_t			pid;
	t_info			*info;
	pthread_t		monitor;
}					t_philo;

/*
** src/thread.c
 */
void	*monitor_start(void *);
void	*thread_start(void *);

/*
** src/act.c
 */
void	pick_up(t_philo *philo, int idx);
void	test(t_info *info, int idx);
void	put_down(t_philo *info, int idx);
void	eat(t_philo *philo);

/*
** src/run.c
 */
int		run(t_info *info);
int		process(t_philo *philo);

/*
** src/print.c
 */
void	print(t_philo *philo, t_status status);

/*
** src/utils.c
 */
int		js_strlen(char *str);
int		error(char *msg);
int		left(t_info *info, int idx);
int		right(t_info *info, int idx);
long	get_time(void);

/*
** src/arguments.c
 */
int		get_argument(char *arg);

/*
** src/init.c
 */
int		init_info(t_info *info, int argc, char *argv[]);

#endif

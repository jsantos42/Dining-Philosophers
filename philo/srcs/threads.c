#include "../headers/threads.h"

/*
**	Starts a thread for each philosopher, each executing the run_thread function
**	with philo as its only argument.
*/

void	start_threads(t_data *data)
{
	int			iter;
	pthread_t	*thread;
	t_philo		*philo;

	iter = -1;
	while (++iter < data->nb_philo)
	{
		thread = &data->philo_thread[iter];
		philo = &data->philo[iter];
		if (pthread_create(thread, NULL, run_thread, philo))
			terminate_program(data, THREAD_CREATION_FAILED);
	}
}

/*
//**	Runs the simulation until either a philosopher is dead or all the
//**	philosophers had enough meals.
//**	In each instance, it calculates the next timeframe in which there should be
//**	a status change of at least 1 philosopher.
*/

void	*run_thread(void *philo_cast_to_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_cast_to_void;
	while (is_everybody_alive(data) && is_anybody_missing_a_meal(data))
		data->timings.current_time_ms = get_next_checkpoint(data);
}

/*
**	Gets the next timeframe in which there should be a status change of at least
**	1 philosopher.
*/

long long	get_next_checkpoint(t_data *data)
{
	int			iter;
	long long	current_time;
	long long	next_checkpoint;
	int			status;
	long long	*next_status_change;

	iter = -1;
	current_time = data->timings.current_time_ms;
	next_checkpoint = 0;
	while (++iter < data->nb_philo)
	{
		next_status_change = &data->philo[iter].next_status_change;
		status = data->philo[iter].status;
		if (current_time == *next_status_change)
		{
			if (current_time == data->philo[iter].last_meal_end + data->timings.time_to_eat)
			{
				update_status(data, iter, DEAD);
				break ;
			}
			if (status == THINK || status == SLEEP)
			{
				if (is_fork_available)
				{
					take_fork(data);
					update_status(data, iter, FORK);
					*next_status_change = check_when_forks_will_be_available_next(data);
				}
				else
					update_status(data, iter, THINK);
			}
			else if (status == FORK)
			{
				if (is_fork_available)
				{
					take_fork(data);
					update_status(data, iter, EAT);
					*next_status_change = current_time + data->timings.time_to_eat;
				}

			}
			else if (status == EAT)
			{
				data->philo[iter].last_meal_end = current_time;
				update_status(data, iter, SLEEP);
				*next_status_change = current_time + data->timings.time_to_sleep;
			}
			if (*next_status_change > data->philo->last_meal_end + data->timings.time_to_eat)
				*next_status_change = data->philo->last_meal_end + data->timings.time_to_eat;
			if (!next_checkpoint || next_checkpoint > *next_status_change)
				next_checkpoint = *next_status_change;
		};
	}
	return (next_checkpoint);
}

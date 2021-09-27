#include "../headers/threads_utils.h"

/*
**	Checks whether the given philosopher is dead.
*/

int	is_not_dead(t_philo *philo)
{
	if (philo->status != DEAD)
		return (1);
	else
		return (0);
}

/*
**	If the must_eat optional argument was given to the program, checks whether
**	the given philosopher had enough meals already.
*/

int	is_missing_a_meal(t_philo *philo)
{
	if (philo->must_eat == -1 || philo->meal_count < philo->must_eat)
		return (1);
	else
		return (0);
}

/*
**	Starts by checking whether any philosopher has already been killed; it does
**	so through a static variable, since this function is used by every thread.
**	If any philosopher is already dead, then the program should terminate and
**	print nothing else.
**	On the other hand, if all philosophers are still alive, this function prints
**	the new status update (in case it differs from the previous one) and, if the
**	new status is DEAD, then it changes the static variable, so that every
**	thread will eventually exit.
*/

void	update_status(t_philo *philo, int new_status)
{
	static	bool	all_alive = true;

	philo->timings.current_time_ms = get_current_time();
	if (!all_alive)
	{
		philo->status = DEAD;
		release_forks(philo);
	}
	else
	{
		philo->status = new_status;
		print_philo_status(philo);
		if (new_status == DEAD)
			all_alive = false;
	}
}


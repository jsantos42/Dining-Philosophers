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
**	Checks whether the status of the philosopher of index 'index' needs updating
**	and, if so, prints the status update to the terminal.
*/

void	update_status(t_philo *philo, int new_status)
{
	if (philo->status != new_status)
	{
		philo->status = new_status;
		print_philo_status(philo);
	}
}

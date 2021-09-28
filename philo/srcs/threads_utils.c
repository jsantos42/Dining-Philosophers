#include "../headers/threads_utils.h"


/*
**	Checks whether all philosophers are still alive.
*/

int	is_alive(t_philo *philo)
{
	if (philo->status == DEAD)
		return (0);
	return (1);
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


void	update_status(t_philo *philo, int new_status)
{
	pthread_mutex_lock(&philo->data->is_everybody_alive_lock);
	philo->status = new_status;
	if (philo->data->is_everybody_alive)
		print_philo_status(philo);
	if (new_status == DEAD)
		philo->data->is_everybody_alive = false;
	pthread_mutex_unlock(&philo->data->is_everybody_alive_lock);
}

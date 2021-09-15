#ifndef RUN_SIMULATION_H
# define RUN_SIMULATION_H

# include "main.h"

void	run_simulation(t_data *data);
long long	get_next_checkpoint(t_data *data);
int		is_everybody_alive(t_data *data);

#endif

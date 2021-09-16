#ifndef THREADS_UTILS_H
# define THREADS_UTILS_H

# include "main.h"

int			is_everybody_alive(t_data *data);
int			is_anybody_missing_a_meal(t_data *data);
void		update_status(t_data *data, int index, int new_status);

#endif

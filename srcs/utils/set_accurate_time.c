#include "../../philosopher.h"

void	update_accurate_time(t_accurate_time *accurate_time, int time_to_action)
{
	accurate_time->actual_time_usec = ft_get_time_usec();
	accurate_time->dt = (accurate_time->ideal_time_usec - accurate_time->actual_time_usec) % 1000;
	accurate_time->ideal_time_usec += time_to_action;
}
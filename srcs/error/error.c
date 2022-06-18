#include "../../philosopher.h"

int	ft_error(t_all *all)
{
	printf("Error:\n");
	if (all->err == MALLOC_FAIL)
		printf("malloc failed\n");
	else if (all->err == INPUT_NULL_POINTER)
		printf("pass NULL as argument\n");
	else if (all->err == INVALID_ARG_NUM)
		printf("invalid number of args\n");
	else if (all->err == INVALID_ARG_VALUE)
		printf("invalid value of args\n");
	else if (all->err == OVER_FLOW)
		printf("over flow happened\n");
	else if (all->err == NO_DIGITS)
		printf("atoi convert to 0 from no digits\n");
	// else
	// 	printf("%d", all->err);
	ft_finalize(all);
	return (-1);
}

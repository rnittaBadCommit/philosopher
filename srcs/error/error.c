#include "../../philosopher.h"

int ft_error(t_all *all)
{
    printf("Error:\n");
    if (all->err == INVALID_ARG_NUM)
        printf("invalid number of args\n");
    else if (all->err == INVALID_ARG_VALUE)
        printf("invalid value of args\n");
    
    ft_finalize(all);
    return (-1);
}